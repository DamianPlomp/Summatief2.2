#pragma once
#include <iostream>

class Icontainer
{
    public:
        // Virtual function used in both Shelf.hpp and Pallet.hpp
        // Shelf.hpp: All the pallets on the shelf are empty
        // Pallet.hpp: Perticular pallet is empty
        virtual bool IsEmpty() = 0;
        // Virtual function used in both shelf.hpp and pallet.hpp
        // Shelf.hpp: All the pallets on the shelf are full
        // Pallet.hpp: Perticular pallet is full
        virtual bool IsFull() = 0;
};