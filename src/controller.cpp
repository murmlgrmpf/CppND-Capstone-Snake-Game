#include "controller.h"
#include <iostream>

#include "snake.h"

void Controller::ChangeDirection(Snake &snake, Snake::Direction input) const {
  if (snake.direction != GetOppositeDirection(input) || snake.size == 1) snake.direction = input;
  return;
}

Snake::Direction Controller::GetOppositeDirection(Snake::Direction input) const{
  Snake::Direction opposite;
  switch(input){
    case Snake::Direction::kUp:
      opposite = Snake::Direction::kDown;
      break;
    case Snake::Direction::kDown:
      opposite = Snake::Direction::kUp;
      break;
    case Snake::Direction::kRight:
      opposite = Snake::Direction::kLeft;
      break;
    case Snake::Direction::kLeft:
      opposite = Snake::Direction::kRight;
      break;
  }
  return opposite;
}

void Controller::HandleInput(bool &running, Snake &snake) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(snake, Snake::Direction::kUp);
          break;

        case SDLK_DOWN:
          ChangeDirection(snake, Snake::Direction::kDown);
          break;

        case SDLK_LEFT:
          ChangeDirection(snake, Snake::Direction::kLeft);
          break;

        case SDLK_RIGHT:
          ChangeDirection(snake, Snake::Direction::kRight);
          break;
        case SDLK_c:
          std::cout << "Cheat Mode enabled!"<<std::endl;
          ChangeDirection(snake, Snake::Direction::kRight);
      }
    }
  }
}