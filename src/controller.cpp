#include "controller.h"
#include <iostream>
#include "snake.h"
#include "base.h"

void Controller::ChangeDirection(Snake::Direction input) const {
  if (_snake->direction != GetOppositeDirection(input) || _snake->size == 1) _snake->direction = input;
  return;
}

void Controller::start(){

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

Controller::Controller(std::shared_ptr<Snake> snake, std::shared_ptr<SDL_Point> food):
  _snake(snake),
  _food(food)
{}

void Controller::HandleInput(bool &running) const
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            running = false;
        }
        else if (e.type == SDL_KEYDOWN)
        {
            switch (e.key.keysym.sym)
            {
            case SDLK_UP:
                ChangeDirection(Snake::Direction::kUp);
                break;

            case SDLK_DOWN:
                ChangeDirection(Snake::Direction::kDown);
                break;

            case SDLK_LEFT:
                ChangeDirection(Snake::Direction::kLeft);
                break;

            case SDLK_RIGHT:
                ChangeDirection(Snake::Direction::kRight);
                break;
            case SDLK_c:
                std::cout << "Cheat Mode enabled!" << std::endl;
                ChangeDirection(ComputeDirection());
            }
        }
    }
}

Snake::Direction Controller::ComputeDirection() const{
  SDL_Point head = _snake->GetHead();
  SDL_Point grid = _snake->GetGrid();
  int x_diff = (_food->x -head.x ) %grid.x;
  int y_diff = (_food->y -head.y ) %grid.y;
  if (abs(x_diff)>abs(y_diff)){
    return (x_diff>0 && x_diff<grid.x/2)? Snake::Direction::kRight : Snake::Direction::kLeft;
  }
  else{
    return (y_diff>0 && y_diff<grid.y/2)? Snake::Direction::kDown : Snake::Direction::kUp;
  }
}