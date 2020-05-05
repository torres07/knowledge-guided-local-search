#include <iostream>
#include "../include/Customer.hpp"

using namespace std;

int main()
{
    Customer c(10.2);
    cout << c.getCapacity();
    return 0;
}