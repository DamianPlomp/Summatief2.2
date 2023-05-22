#pragma once
#include <iostream>
#include <array>
#include "Pallet.hpp"
#include "Icontainer.hpp"

class Shelf : public Icontainer
{
    public:
        std::array<Pallet, 4> pallets;
        // Basic constructor for a shelf
        Shelf();
        // Swaps two pallets with eachother on the same shelf
        bool SwapPallet(int slot, int slot2);
        // Checks whether the pallets on the shelf are all completely empty
        bool IsEmpty() override;
        // Checks whether the pallets on the shelf are all completely full
        bool IsFull() override;
};