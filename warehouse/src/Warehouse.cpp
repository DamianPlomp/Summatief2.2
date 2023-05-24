#include <iostream>
#include "include/Warehouse.hpp"

Warehouse::Warehouse()
{
    employees = {};
    shelves = {};
};

void Warehouse::AddEmployee(Employee employee)
{
    employees.push_back(employee);
};

void Warehouse::AddShelf(Shelf shelf)
{
    shelves.push_back(shelf);
};

bool Warehouse::RearrangeShelf(Shelf& shelf)
{
    bool running = false;


    for(auto& i : employees)
    {
        if(i.GetForkliftCertificate() && !i.GetBusy())
        {
            running = true;
            while(running)
            {
                running = false;
                for(unsigned int i=0; i<shelf.pallets.size()-1; i++)
                {
                    if(shelf.pallets[i].GetItemCount() > shelf.pallets[i+1].GetItemCount())
                    {
                        shelf.SwapPallet(i, i+1);
                        running = true;
                    }
                }
            }
            return true;
        }
    }
    return false;
};

bool Warehouse::PickItems(std::string itemName, int itemCount)
{
    int amount = 0;

    if (itemCount <= 0)
    {
        return false;
    }

    for (auto& shelf : shelves)
    {
        for (auto& pallet : shelf.pallets)
        {
            if (itemName == pallet.GetItemName())
            {
                amount+=pallet.GetItemCount();
            }
        }
    };

    if (amount>=itemCount)
    {
        for (auto& shelf : shelves)
        {
            for (auto& pallet : shelf.pallets)
            {
                if (itemName == pallet.GetItemName())
                {
                    while (itemCount > 0 && !pallet.IsEmpty())
                    {
                        pallet.TakeOne();
                        itemCount--;
                    }
                }
            }
        }
        return true;
    }
    return false;
}