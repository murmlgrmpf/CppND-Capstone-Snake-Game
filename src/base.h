#ifndef BASE_H
#define BASE_H

#include <thread>
#include <vector>

class Base {
 public:
 virtual void start() {};

 private:
  std::vector<std::thread> threads;
};

#endif