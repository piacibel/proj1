#pragma once
#include "termview.hpp"
#include <utility>
#include <vector>


using coord = std::pair<unsigned int, unsigned int>;

class Matrix{
private:
    static const unsigned int MAXLINES = 40;
    static const unsigned int MAXCOLS = 100;

    //View
    TermView view{MAXLINES, MAXCOLS};

    // position : <LINE,COL>
    coord cursor{0,0};

    //Matrix
    std::vector<std::vector<char>> map;

    void update_map(char);

public:
    //ctor
    Matrix(void);

    //dtor
    ~Matrix(void);

    coord getSize() const;

    // Cursor Manipulation
    void _shiftCursor(int, int);
    void _setCursor(coord&);
    void _initCursor();
    coord _getCursor() const;

    // Drawing basic things
    void drawVertLine(int, char);
    void drawHoriLine(int, char);
    void drawRectangle(unsigned int, unsigned int);
    void drawBorder();
    void displayScene();
    void displayTextScene();

};
