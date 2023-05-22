#include <iostream>
#include "include/Warehouse.hpp"

Warehouse::Warehouse()
{

};

void Warehouse::AddEmployee(Employee employee)
{
    Employees.push_back(employee);
};

void Warehouse::AddShelf(Shelf shelf)
{
    Shelves.push_back(shelf);
};

bool Warehouse::RearrangeShelf(Shelf& shelf) // TO DO
{
    bool rearranged = false;

    if(Employee::GetForkliftCertificate)
    {
        for(int i=0; i<3; i++)
        {
            for(int j=i+1; j<4; j++)
            {
                if(shelf.pallets[i].GetItemCount() > shelf.pallets[j].GetItemCount())
                {
                    shelf.SwapPallet(i, j);
                    rearranged = true;
                }
            }
        }
    }
    return rearranged;
};

bool Warehouse::PickItems(std::string itemName, int itemCount)
{
    bool itemPicked = false;

    for (auto& shelf : Shelves)
    {
        for (auto& pallet : shelf.pallets)
        {
            if (itemName == pallet.GetItemName())
            {
                while (itemCount > 0 && !pallet.IsEmpty())
                {
                    pallet.TakeOne();
                    itemCount--;
                    itemPicked = true;
                }

                if (itemCount == 0)
                {
                    break;
                }
            }
        }
        
        if (itemCount == 0)
        {
            break;
        }
    }

    return itemPicked;
}