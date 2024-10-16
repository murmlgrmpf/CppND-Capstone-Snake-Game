#ifndef GAME_H
#define GAME_H

#include <random>
#include <memory>
#include "food.h"
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height,
  std::shared_ptr<Snake> snake_ = std::make_shared<Snake>());
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

  Controller controller;

 private:
  std::shared_ptr<Snake> snake;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  Food &&PlaceFood(Food &&food);
  Food Update(Food food);
};

#endif