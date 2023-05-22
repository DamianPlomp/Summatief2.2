#include <iostream>
#include "include/Employee.hpp"

Employee::Employee(std::string name, bool busy, bool forkliftCerticate)
{
    this -> name = name;
    this -> busy = busy;
    this -> forkliftCertificate = forkliftCerticate;
};

std::string Employee::GetName()
{
    return this -> name;
};

bool Employee::GetBusy()
{   
    return this -> busy;
};

void Employee::SetBusy(bool busy)
{
    this -> busy = busy;
};

bool Employee::GetForkliftCertificate()
{
    return this -> forkliftCertificate;
};

void Employee::SetForkliftCertificate(bool forkliftCertificate)
{
    this -> forkliftCertificate = forkliftCertificate;
};