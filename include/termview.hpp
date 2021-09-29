#pragma once
#include <ncurses.h>
#include <iostream>
#include <chrono>
#include <vector>


using coord = std::pair<unsigned int, unsigned int>;

//using namespace std::chrono_literals;


/** Exemple of use of curse interface **/
void test_curse_view(int size);


/** References can be found there :
 * https://linux.die.net/man/3/nodelay */

class TermView{
    const unsigned int MAXLINES;
    const unsigned int MAXCOLS;



public:
    TermView(unsigned int, unsigned int);
    ~TermView(void);

    void set_nodelay();
    void set_noecho();
    void set_echo();

    // Getter
    int getMaxLines() const;
    int getMaxCols() const;

    void displayScene(std::vector<std::vector<char>>&);

};
