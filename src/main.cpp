#include "matrix.hpp"
#include "snake.hpp"

int main(int argc, char** argv){
    Matrix matrix=Matrix();
    matrix.drawBorder();
    //matrix.displayTextScene();
    matrix.displayScene();
    getch();
    return 0;
}
