#include <iostream>
#include "src/include/Employee.hpp"
#include "src/include/Pallet.hpp"
#include "src/include/Shelf.hpp"
#include "src/include/Warehouse.hpp"

int main(void)
{
    // Create an empty warehouse
    Warehouse warehouse = Warehouse();
    // Create a shelf with four pallets filled with items to put into the warehouse
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Cheese", 20, 20),
        Pallet("Cashew", 60, 40),
        Pallet("Cheese", 20, 15),
        Pallet("Cashew", 60, 20)
    };

    // Add the shelf into the warehouse
    warehouse.AddShelf(shelf1);
    // Create an employee with no forkliftcertificate
    Employee john = Employee("John", true);
    // Add an employee to the warehouse who doesn't have a forkliftcertificate
    warehouse.AddEmployee(john);


    // Picking items and rearranging shelves


    // We rearrange shelves by sorting them on item count
    if(warehouse.RearrangeShelf(shelf1))
    {
        std::cout << "Succesfully rearranged shelf" << std::endl;
    };
    // We can also pick items and a certain amount
    // In this example with want to take 20 packets of cashew nuts
    if(warehouse.PickItems("Cashew", 20))
    {
        std::cout << "Succesfully picked items" << std::endl;
    };
    
};
