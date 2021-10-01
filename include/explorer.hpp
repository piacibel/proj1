#pragma once
#include <iostream>
#include "eventloop.hpp"
#include "matrix.hpp"


class Explorer{
private:
    Matrix* matrix;
    EventLoop<Explorer>* events;

public:
    Explorer();
    ~Explorer();
    void Run();

    // In this case, do nothing
    void idleAction();

    void inputAction(char);
};
