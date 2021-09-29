#include "termview.hpp"
#include <thread>

void test_curse_view(int size){

    initscr();
    printw("Hello !!");
    refresh();
    getch();

    int maxlines = LINES - 1;
    int maxcols = COLS - 1;

    if ((size > maxlines) or (size>maxcols)){
        std::cout<<"Size must be inferior to "<<maxlines<<" and "<<maxcols<<std::endl;
    }
    else{

    }
    endwin();
    return;
}


TermView::TermView(unsigned int maxlines,
                   unsigned int maxcols) : MAXLINES(maxlines), MAXCOLS(maxcols){
    initscr();
    /**  Disable line buffering */
    cbreak();
    /** The nodelay option causes getch to be a non-blocking call. If
     * no input is ready, getch returns ERR. If disabled (bf is
     * FALSE), getch waits until a key is pressed. */
}

TermView::~TermView(){
    endwin();
}

int TermView::getMaxLines() const{
    return MAXLINES;
}

int TermView::getMaxCols() const{
    return MAXCOLS;
}

void TermView::set_nodelay(){
    nodelay(stdscr, true);
}

void TermView::set_noecho(){
    noecho();
}

void TermView::set_echo(){
    echo();
}

void TermView::displayScene(std::vector<std::vector<char>>& map){
    move(0, 0);
    for (unsigned int idLine=0; idLine < this->MAXLINES ; idLine++){
        for (unsigned int idCol=0; idCol < this->MAXCOLS ; idCol++){
            move(idLine,idCol);
            if (map[idLine][idCol] != 0){
                addch(map[idLine][idCol]);
            }
        }
    }
    refresh();
}
