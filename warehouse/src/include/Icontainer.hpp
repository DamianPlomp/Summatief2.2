#pragma once
#include <iostream>

class Icontainer
{
    public:
        virtual bool IsEmpty() = 0;
        virtual bool IsFull() = 0;
};