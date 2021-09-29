#pragma once
#include <chrono>
#include <iostream>
#include <functional>

using namespace std::chrono_literals;


template<class Game>
class EventLoop{
private:
    std::chrono::duration<double, std::milli> timestep;
public:
    //ctor
    EventLoop(double);
    //dtor
    ~EventLoop();

    void orchestrate(Game&,
                     std::function<void(Game&)>&,
                     std::function<void(Game&, char)>&);
};
