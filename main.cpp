#include <iostream>
#include <unordered_map>
#include "Classes/AirTransport.h"

int main() {
    AirTransport airTransport;

    list <Airport*> l = airTransport.shortestPath(airTransport.getAirport("OPO"), airTransport.getAirport(""));

    for (auto it = l.begin(); it != l.end(); it++) (*it)->print();
}
