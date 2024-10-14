#ifndef FOOD_H
#define FOOD_H
#include "SDL.h"

class Food {
 public:
 // Rule of 5: Plus RAII
    Food(){
        food = new SDL_Point;
        food->x = 0;
        food->y = 0;
    }
    Food(const Food& other){
        food = new SDL_Point;
        food->x = other.x();
        food->y = other.y();
    }
    Food(Food&& other):
        food(other.food)
    {
        other.food = nullptr;
    }
    Food &operator=(const Food &other){
        food->x = other.x();
        food->y = other.y();
        return *this;
    }
    Food &operator=(Food &&other){
        if (this != &other){
            delete food;
            food = other.food;
            other.food = nullptr;
        }
        return *this;
    }
    ~Food(){
        delete food;
    };
    SDL_Point getFood() {
        SDL_Point fd;
        fd.x = food->x;
        fd.y = food->y;
        return fd;
    };
    // overloaded setFood function:
    void setFood(SDL_Point f){
        food->x = f.x;
        food->y = f.y;
    }
    void setFood(int x, int y){
        food->x = x;
        food->y = y;
    }

    // overloaded setter and getter aliases:
    int x() const {return food->x;}
    int y() const {return food->y;}
    void x(int x) {food->x = x;}
    void y(int y) {food->y = y;}

 private:
    SDL_Point *food;
};

#endif