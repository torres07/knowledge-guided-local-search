#include <iostream>

#include "../include/InterRoute.hpp"

using namespace std;

bool InterRoute::orExchange(Route r1, Route r2){
    printf("Route 1: ");
    r1.listPath();
    printf("Route 2: ");
    r2.listPath();

    Route subRoute = r1.getSubstring(3, 4); // 65  30  66  35
    r2.addSubroute(subRoute, 1); 

    printf("Route 2 - with subrout added: ");
    r2.listPath();

    printf("Route 1- with subrout removed: ");
    r1.removeSubroute(subRoute);
    r1.listPath();

	return true;
}