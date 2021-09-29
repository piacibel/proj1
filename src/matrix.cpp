#include "matrix.hpp"

Matrix::Matrix(void){
    this->map.resize(this->MAXLINES);
    for (auto & value: this->map){
        value.resize(this->MAXCOLS);
    }
}

Matrix::~Matrix(){
}

void Matrix::_shiftCursor(int dv, int dh){
    cursor = this->_getCursor();
    if (cursor.first + dv > this->MAXLINES){
        // Throw cursor error, yay
    }
    if (cursor.second + dh > this->MAXCOLS){
        // Throw cursor error, yay
    }
    this->cursor.first += dv;
    this->cursor.second += dh;
}

void Matrix::_setCursor(coord &pt){
    this->cursor = pt;
}

void Matrix::_initCursor(){
    this->cursor.first = 0;
    this->cursor.second = 0;
}

coord Matrix::_getCursor() const{
    return this->cursor;
}

void Matrix::update_map(char c){
    this->map[this->cursor.first][this->cursor.second] = c;
}

void Matrix::drawVertLine(int len, char c){
    for (int i=0 ; i<len; i++){
        this->update_map(c);
        this->_shiftCursor(1,0);
    }
    this->_shiftCursor(-1,0);
}

void Matrix::drawHoriLine(int len, char c){
    for (int i=0 ; i<len; i++){
        this->update_map(c);
        this->_shiftCursor(0,1);
    }
    this->_shiftCursor(0,-1);
}

void Matrix::drawRectangle(unsigned int dv, unsigned int dh){
    auto initial_point = this->_getCursor();
    this->drawVertLine(dv,'X');
    this->drawHoriLine(dh,'X');
    this->_setCursor(initial_point);
    this->drawHoriLine(dh,'X');
    this->drawVertLine(dv,'X');
}

void Matrix::drawBorder(){
    this->drawRectangle(this->MAXLINES, this->MAXCOLS);
}

void Matrix::displayScene(){
    this->view.displayScene(this->map);
}

void Matrix::displayTextScene(){
    for (auto & line: this->map){
        for (auto & ch: line){
            std::cout<<ch;
        }
        std::cout<<std::endl;
    }
}
