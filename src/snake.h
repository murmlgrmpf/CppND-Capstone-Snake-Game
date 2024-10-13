#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <mutex>
#include "SDL.h"

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(int grid_width = 10, int grid_height = 10)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2) {}

  void Setup(int grid_width, int grid_height);
  void Update();

  void GrowBody();
  bool SnakeCell(int x, int y);
  bool isAlive() {
    std::lock_guard<std::mutex> lck(smtx);
    return alive;
  };
  void incrementSpeed(float increment) {
    std::lock_guard<std::mutex> lck(smtx);
    speed += increment;
  };
  int getSize() {
    std::lock_guard<std::mutex> lck(smtx);
    return size;
  };
  Direction getDirection(){
    std::lock_guard<std::mutex> lck(smtx);
    return direction;
  }
  void setDirection(Direction dir){
    std::lock_guard<std::mutex> lck(smtx);
    direction = dir;
  }

  SDL_Point GetHead();
  SDL_Point GetGrid();

  std::vector<SDL_Point> getBody(){
    std::lock_guard<std::mutex> lck(smtx);
    return body;
  }

 private:
  std::vector<SDL_Point> body;
  Direction direction = Direction::kUp;

  float speed{0.1f};
  int size{1};
  bool alive{true};

  std::mutex smtx;
  float head_x;
  float head_y;
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif