#pragma once
#include <iostream>

class Employee
{
    private:
        std::string name;
        bool busy;
        bool forkliftCertificate;
    public:
        // Constructor for the employee class
        Employee(std::string name, bool busy, bool forkliftCerticate);
        // Gets the name of the employee
        std::string GetName();
        // Returns a boolean, true if the employee is busy, false if the person is not
        bool GetBusy();
        // Set an employee on busy or not
        void SetBusy(bool busy);
        // Returns a boolean, true if the employee has a forklift certificate, false if the person does not
        bool GetForkliftCertificate();
        // Add or remove a forklift certificate from an employee
        void SetForkliftCertificate(bool forkliftCertificate);
};