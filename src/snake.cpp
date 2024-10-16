#include "snake.h"
#include <cmath>
#include <iostream>

SDL_Point Snake::GetGrid(){
  std::lock_guard<std::mutex> lck(smtx);
  SDL_Point cell{
      grid_width,
      grid_height};  // get the lower right corner = size of the grid.
  return cell;
}

SDL_Point Snake::GetHead(){
  std::lock_guard<std::mutex> lck(smtx);
  SDL_Point cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)};  // Capture the head's cell.
  return cell;
}

void Snake::Setup(int grid_width, int grid_height){
    std::lock_guard<std::mutex> lck(smtx);
    this->grid_width = grid_width;
    this->grid_height = grid_height;
    this->head_x = grid_width / 2;
    this->head_y = grid_height / 2;
}

void Snake::Update() {
  SDL_Point prev_cell = GetHead();  // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell = GetHead();  // Capture the head's cell after updating.

  // Update all of the body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
    UpdateBody(current_cell, prev_cell);
  }
}

void Snake::UpdateHead() {
  std::lock_guard<std::mutex> lck(smtx);
  switch (direction) {
    case Direction::kUp:
      head_y -= speed;
      break;

    case Direction::kDown:
      head_y += speed;
      break;

    case Direction::kLeft:
      head_x -= speed;
      break;

    case Direction::kRight:
      head_x += speed;
      break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  head_x = fmod(head_x + grid_width, grid_width);
  head_y = fmod(head_y + grid_height, grid_height);
}

void Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell) {
  std::lock_guard<std::mutex> lck(smtx);
  // Add previous head location to vector
  body.push_back(prev_head_cell);

  if (!growing) {
    // Remove the tail from the vector.
    body.erase(body.begin());
  } else {
    growing = false;
    size++;
  }

  // Check if the snake has died.
  for (auto const &item : body) {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
      alive = false;
    }
  }
}

void Snake::GrowBody() {
  std::lock_guard<std::mutex> lck(smtx);
  growing = true;
}

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int x, int y) {
  std::lock_guard<std::mutex> lck(smtx);
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
    return true;
  }
  for (auto const &item : body) {
    if (x == item.x && y == item.y) {
      return true;
    }
  }
  return false;
}