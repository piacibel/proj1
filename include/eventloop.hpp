#pragma once
#include <ncurses.h>
#include <chrono>
#include <iostream>
#include <functional>
#include <termview.hpp>

using namespace std::chrono_literals;


template<class Game>
class EventLoop{
private:
    std::chrono::duration<double, std::milli> timestep;
public:
    //ctor
    EventLoop(double timestep) : timestep(timestep){}
    //dtor
    ~EventLoop(){}

    void orchestrate(Game& game,
                     std::function<void(Game&)>& idleAction,
                     std::function<void(Game&, char)>& inputAction){

        auto startTime = std::chrono::system_clock::now();

        while(true){
            auto currentTime = std::chrono::system_clock::now() - startTime;

            if(std::chrono::duration<double, std::milli>(currentTime) >= timestep){

                idleAction(game);
                //Reset the timer.
                startTime = std::chrono::system_clock::now();
            }

            //Run other code here while not updating.
            char key = ' ';
            if(TermView::get_keyhit()){
                key = getch();
            }
            if( key == 'X' ) //Exit common for everything, to be determined ?
                break; //Quit the while loop
            else if (key !=' ')
            {
                inputAction(game, key);
            }
        }
    }
};
