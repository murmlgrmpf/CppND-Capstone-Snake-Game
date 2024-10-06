#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <memory>
#include "snake.h"
#include "base.h"

class Controller: public Base {
 public:
    Controller(std::shared_ptr<Snake> snake, std::shared_ptr<SDL_Point>food);
    void HandleInput(bool &running) const;
    void start();
    std::shared_ptr<SDL_Point> _food;

 private:
    void ChangeDirection(Snake::Direction input) const;
    Snake::Direction GetOppositeDirection(Snake::Direction input) const;
    Snake::Direction ComputeDirection() const;

    std::shared_ptr<Snake> _snake;
};

#endif