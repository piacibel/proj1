#include "eventloop.hpp"

EventLoop::EventLoop(double timestep) :timestep(timestep){
}

EventLoop::~EventLoop(){
}


void EventLoop::orchestrate(Game&,
                            std::function<void(Game&)>& idleAction,
                            std::function<void(Game&, char)>& inputAction){
    std::cout<<"Ho Ho Ho"<<std::endl;
}
