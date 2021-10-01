#include "snake.hpp"

Snake::Snake(){
    this->matrix = new Matrix();
}

Snake::~Snake(){
    delete this->matrix;
}
