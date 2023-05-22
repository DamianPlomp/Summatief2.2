#include <iostream>
#include "include/Pallet.hpp"


Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount)
{
    this -> itemName = itemName;
    this -> itemCapacity = itemCapacity;
    this -> itemCount = itemCount;
};

Pallet::Pallet()
{

};

std::string Pallet::GetItemName()
{
    return this -> itemName;
};

int Pallet::GetItemCount()
{
    return this -> itemCount;
};

int Pallet::GetRemainingSpace()
{
    return itemCapacity - itemCount;
};

bool Pallet::RealocateEmptyPallet(std::string itemName, int itemCapacity, int itemCount) // TO DO
{
    if(IsEmpty())
    {
        this -> itemName = itemName;
        this -> itemCapacity = itemCapacity;
        this -> itemCount = itemCount;
        return true;
    };
    return false;
};

bool Pallet::TakeOne()
{
    if(IsEmpty())
    {
        std::cout << ("ERROR: pallet is empty");
        return false;
    };
    itemCount--;
    return true;
};

bool Pallet::PutOne()
{
    if(IsFull())
    {
        std::cout << ("ERROR: pallet is full");
        return false;
    };
    itemCount++;
    return true;
};

bool Pallet::IsEmpty()
{
    return itemCount == 0;
};

bool Pallet::IsFull()
{
    return itemCount == itemCapacity;
};