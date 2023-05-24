#include "include/catch.hpp"

#include "../src/include/warehouse.hpp"
#include <iostream>

///////////////////////////////////////////////////////////////
//                                                           //
//                    Warehouse unittests                    //
//                                                           //
///////////////////////////////////////////////////////////////
//                                                           //
// This file contains all testcases for the Warehouse class. //
// Currently it only contains tests for the rearranging of   //
// shelves. All other Warehouse functions will also need to  //
// be tested. You will have to do this yourself.             //
//                                                           //
// For information on how to write testcases with catch2,    //
// see https://github.com/catchorg/Catch2.                   //
//                                                           //
///////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////
//                Functions used in testcases                //
///////////////////////////////////////////////////////////////

/// \brief 
/// Creates a mock Warehouse.
/// \return Warehouse with shelf of books.
/// \details
/// Creates a Warehouse with 3 unsorted shelves with a total of 100 Books, 60 Boxes, and 60 Toy Bears.
/// \n Adds forklift certified employee Bob.
/// \n This function can be used in testcases to avoid the repeated construction of Warehouse objects.
Warehouse createMockWarehouse(){
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 40), 
        Pallet("Boxes", 100, 10), 
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 20)
    };

    Shelf shelf2 = Shelf();
    shelf2.pallets = {
        Pallet("Books", 100, 15), 
        Pallet("Boxes", 100, 20), 
        Pallet("Books", 100, 5), 
        Pallet("Boxes", 100, 30)
    };

    Shelf shelf3 = Shelf();
    shelf3.pallets = {
        Pallet("Toy Bears", 100, 20), 
        Pallet("Toy Bears", 100, 10), 
        Pallet(), 
        Pallet("Toy Bears", 100, 30)
    };
    
    warehouse.AddShelf(shelf1);
    warehouse.AddShelf(shelf2);
    warehouse.AddShelf(shelf3);

    warehouse.AddEmployee(Employee("Bob", true));

    return warehouse;
}


///////////////////////////////////////////////////////////////
//           Warehouse::rearrangeShelf test cases            //
///////////////////////////////////////////////////////////////

TEST_CASE("Rearrange empty shelf", "Warehouse::RearrangeShelf"){
    // Construct empty warehouse and add empty shelf and forklift certified Employee.
    Warehouse warehouse = Warehouse();
    warehouse.AddShelf(Shelf());
    warehouse.AddEmployee(Employee("Bob", true));

    // Check if shelf is already arranged.
    // Empty shelf should already be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].GetItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[1].GetItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[2].GetItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[3].GetItemCount() == 0);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.RearrangeShelf(warehouse.shelves[0]);
    // Should be successful
    REQUIRE(successful);

    // Check if shelf is now correctly arranged.
    // Empty shelf should still be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].GetItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[1].GetItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[2].GetItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[3].GetItemCount() == 0);
}

TEST_CASE("Rearrange full shelf", "Warehouse::RearrangeShelf"){
    // Construct warehouse with unsorted shelf of books.
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };

    warehouse.AddEmployee(Employee("Bob", true));
    warehouse.AddShelf(shelf1);

    // Check if shelf is already arranged.
    // This shelf should not already be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].GetItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[1].GetItemCount() == 40);
    REQUIRE(warehouse.shelves[0].pallets[2].GetItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[3].GetItemCount() == 10);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.RearrangeShelf(warehouse.shelves[0]);
    // Should be successful
    REQUIRE(successful);

    // Check if shelf is now correctly arranged.
    // Shelf should now be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].GetItemCount() == 10);
    REQUIRE(warehouse.shelves[0].pallets[1].GetItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[2].GetItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[3].GetItemCount() == 40);
}

TEST_CASE("Rearrange half filled shelf", "Warehouse::RearrangeShelf"){
    // Construct empty warehouse and unsorted shelf of books.
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 20), 
        Pallet(), 
        Pallet()
    };
    
    warehouse.AddEmployee(Employee("Bob", true));
    warehouse.AddShelf(shelf1);

    // Check if shelf is already arranged.
    // This shelf should not already be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].GetItemCount() == 40);
    REQUIRE(warehouse.shelves[0].pallets[1].GetItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[2].GetItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[3].GetItemCount() == 0);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.RearrangeShelf(warehouse.shelves[0]);
    // Should be successful
    REQUIRE(successful);

    // Check if shelf is now correctly arranged.
    // Shelf should now be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].GetItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[1].GetItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[2].GetItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[3].GetItemCount() == 40);
}

TEST_CASE("Rearrange shelf without qualified employee", "Warehouse::RearrangeShelf"){
    // Construct warehouse with unsorted shelf of books.
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };
    
    warehouse.AddEmployee(Employee("Bert", false));
    warehouse.AddShelf(shelf1);

    // Check if shelf is already arranged.
    // This shelf should not already be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].GetItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[1].GetItemCount() == 40);
    REQUIRE(warehouse.shelves[0].pallets[2].GetItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[3].GetItemCount() == 10);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.RearrangeShelf(warehouse.shelves[0]);
    // Should fail
    REQUIRE(!successful);

    // Check if shelf is now correctly arranged.
    // Shelf should now still not be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].GetItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[1].GetItemCount() == 40);
    REQUIRE(warehouse.shelves[0].pallets[2].GetItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[3].GetItemCount() == 10);
}

TEST_CASE("Rearrange shelf with quallified, but busy, employee", "Warehouse::rearrangeShelf"){
    // Construct warehouse with unsorted shelf of books.
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };
    
    Employee bert = Employee("Bert", true);
    bert.SetBusy(true);

    warehouse.AddEmployee(bert);
    warehouse.AddShelf(shelf1);

    // Check if shelf is already arranged.
    // This shelf should not already be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].GetItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[1].GetItemCount() == 40);
    REQUIRE(warehouse.shelves[0].pallets[2].GetItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[3].GetItemCount() == 10);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.RearrangeShelf(warehouse.shelves[0]);
    // Should fail
    REQUIRE(!successful);

    // Check if shelf is now correctly arranged.
    // Shelf should now still not be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].GetItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[1].GetItemCount() == 40);
    REQUIRE(warehouse.shelves[0].pallets[2].GetItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[3].GetItemCount() == 10);
}