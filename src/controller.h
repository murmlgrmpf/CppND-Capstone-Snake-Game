#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <memory>
#include "food.h"
#include "snake.h"
#include "base.h"

class Controller: public Base {
 public:
    Controller(std::shared_ptr<Snake> snake, std::shared_ptr<Food>food);
    void HandleInput(bool &running) const;
    void start();

 private:
    void ChangeDirection(Snake::Direction input) const;
    Snake::Direction GetOppositeDirection(Snake::Direction input) const;
    Snake::Direction ComputeDirection() const;

    std::shared_ptr<Food> _food;
    std::shared_ptr<Snake> _snake;
};

#endif