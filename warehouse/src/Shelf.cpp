#include <iostream>
#include "include/Shelf.hpp"

Shelf::Shelf()
{

};

bool Shelf::SwapPallet(int slot, int slot2)
{
    Pallet ph = pallets[slot];
    pallets[slot] = pallets[slot2];

    pallets[slot2] = ph;

    return true;
};

bool Shelf::IsEmpty()
{
    for (auto& pallet : pallets)
    {
        if (!pallet.IsEmpty())
        {
            return false;
        }
    }
    return true;
}

bool Shelf::IsFull() // TO DO
{
    for (auto& pallet : pallets)
    {
        if(!pallet.IsFull())
        {
            return false;
        }

    }
    return true;
};