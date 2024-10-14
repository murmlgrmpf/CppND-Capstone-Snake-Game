#include "game.h"
#include <iostream>
#include "SDL.h"
#include <future>

Game::Game(std::size_t grid_width, std::size_t grid_height, std::shared_ptr<Snake> snake_)
    : snake(snake_),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)),
      controller(snake_)
       {
  snake->Setup(grid_width,grid_height);
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;
  Food food;
  food = PlaceFood(std::move(food));

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    // Async: food is call by value:
    auto upd_future = std::async(std::launch::async, &Game::Update,this,food);
    // Now the food is moved around:
    food = controller.HandleInput(running, std::move(food));
    // And rendered by call by reference (const)
    renderer.Render(snake,food);
    
    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
    // new food comes back:
    food = upd_future.get();
  }
}

Food &&Game::PlaceFood(Food && food) {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake->SnakeCell(x, y)) {
      food.setFood(x,y);
      return std::move(food);
    }
  }
}

Food Game::Update(Food food) {
  if (!snake->isAlive()) return food;
  snake->Update();
  SDL_Point head = snake->GetHead();
  int new_x = static_cast<int>(head.x);
  int new_y = static_cast<int>(head.y);

  // Check if there's food over here
  SDL_Point fd = food.getFood();
  if (fd.x == new_x && fd.y == new_y) {
    score++;
    food = PlaceFood(std::move(food));
    // Grow snake and increase speed.
    snake->GrowBody();
    snake->incrementSpeed(0.02);
  }
  return food;
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake->getSize(); }