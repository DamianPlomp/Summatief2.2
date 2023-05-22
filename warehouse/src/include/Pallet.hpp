#pragma once
#include <iostream>
#include "Icontainer.hpp"

class Pallet : public Icontainer
{
    private:
        int itemCount;
        std::string itemName;
        int itemCapacity;
    public:
        // Constructor for the Pallet class
        Pallet(std::string itemName, int itemCapacity, int itemCount);
        // Constructor for an empty pallet
        Pallet();
        // Get the item name from the item that's stacked on the pallet
        std::string GetItemName();
        // Get the amount of items that are on the pallet
        int GetItemCount();
        // Returns the amount of remaining space that is on the pallet
        int GetRemainingSpace();
        // Reallocate the object pallet to a different spot on the shelf
        bool RealocateEmptyPallet(std::string itemName, int itemCapacity, int itemCount);
        // Remove an item from the pallet
        bool TakeOne();
        // Add an item to the pallet
        bool PutOne();
        // Check whether the pallet is empty
        bool IsEmpty() override;
        // Check whether the pallet is full
        bool IsFull() override;
};
