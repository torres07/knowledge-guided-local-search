#include "../include/Customer.hpp"

Customer::Customer(float capacity)
{
    setCapacity(capacity);
}

void Customer::setCapacity(float capacity)
{
    this->capacity = capacity;
}

float Customer::getCapacity()
{
    return this->capacity;
}