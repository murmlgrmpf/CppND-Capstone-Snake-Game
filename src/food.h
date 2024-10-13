#ifndef FOOD_H
#define FOOD_H
#include <mutex>
#include "SDL.h"

class Food {
 public:
    Food(){
        food = new SDL_Point;
    };
    ~Food(){
        delete food;
    };
    SDL_Point getFood(){
        std::lock_guard<std::mutex> lck(mtx);
        return *food;
    };
    void setFood(SDL_Point f){
        std::lock_guard<std::mutex> lck(mtx);
        food->x = f.x;
        food->y = f.y;
    }
    void setFood(int x, int y){
        std::lock_guard<std::mutex> lck(mtx);
        food->x = x;
        food->y = y;
    }


 private:
    SDL_Point *food;
    std::mutex mtx;
};

#endif