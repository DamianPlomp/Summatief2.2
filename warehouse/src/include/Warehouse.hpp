#pragma once
#include <iostream>
#include <vector>
#include "Shelf.hpp"
#include "Employee.hpp"

class Warehouse
{  
    private:
        std::vector<Employee> Employees;
        std::vector<Shelf> Shelves;
    public:
        // Basic constructor for a warehouse
        Warehouse();
        // Add an employee to the warehouse
        void AddEmployee(Employee employee);
        // Add a shelf to the warehouse
        void AddShelf(Shelf shelf);
        // Rearrange the shelfs inside the warehouse
        bool RearrangeShelf(Shelf& shelf);
        // Pick an item from any shelf from any pallet
        bool PickItems(std::string itemName, int itemCount);
};