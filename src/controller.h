#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <memory>
#include "food.h"
#include "snake.h"
#include "base.h"

class Controller: public Base {
 public:
    Controller(std::shared_ptr<Snake> snake);
    Food && HandleInput(bool &running, Food &&fd) const;
    void start();

 private:
    void ChangeDirection(Snake::Direction input) const;
    Snake::Direction GetOppositeDirection(Snake::Direction input) const;
    Snake::Direction ComputeDirection(int food_x, int food_y) const;

    std::shared_ptr<Snake> _snake;
};

#endif