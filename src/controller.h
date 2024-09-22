#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "snake.h"

class Controller {
 public:
  void HandleInput(bool &running, Snake &snake, SDL_Point &food) const;

 private:
  void ChangeDirection(Snake &snake, Snake::Direction input) const;
    Snake::Direction GetOppositeDirection(Snake::Direction input) const;
    Snake::Direction ComputeDirection(Snake &snake, SDL_Point &food) const;
};

#endif