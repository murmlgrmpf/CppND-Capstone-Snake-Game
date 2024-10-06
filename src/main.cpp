#include <iostream>
#include <fstream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
using namespace std;

void writeScore(int score, int size){
  ofstream score_file;
  score_file.open ("scores.txt");
  score_file << "This is your highscores:"<< endl;
  score_file << "Score: " << score << " | ";
  score_file << "Size: " << size << endl;
  score_file.close();
}

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Game game(kGridWidth, kGridHeight);
  game.Run(game.controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  writeScore(game.GetScore(), game.GetSize());
  return 0;
}