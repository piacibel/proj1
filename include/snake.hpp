#pragma once
#include <iostream>
#include "eventloop.hpp"
#include "matrix.hpp"


class Snake{
private:
    Matrix* matrix;
public:
    Snake();
    ~Snake();
    void Run();
};
