#include "explorer.hpp"


Explorer::Explorer(){
    this->matrix = new Matrix();
    this->events = new EventLoop<Explorer>(1.,
                                           &Explorer::idleAction,
                                           &Explorer::inputAction);
}

Explorer::~Explorer(){
    delete this->matrix;
}

void Explorer::Run(){
    this->events->orchestrate(*this);
}

void Explorer::idleAction(){
    matrix->displayScene();
}

void Explorer::inputAction(char c){
    switch(c){
    case KEY_LEFT:
        matrix->update_map(' ');
        matrix->_shiftCursor(-1,0);
    case KEY_RIGHT:
        matrix->update_map(' ');
        matrix->_shiftCursor(1,0);
    case KEY_UP:
        matrix->update_map(' ');
        matrix->_shiftCursor(0,-1);
    case KEY_DOWN:
        matrix->update_map(' ');
        matrix->_shiftCursor(0,1);
    }
    matrix->displayScene();
}
