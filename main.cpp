#include <iostream>
#include "Classes/AirTransport.h"

int main() {
    AirTransport airTransport;

    list <Airport*> a = airTransport.shortestPath(airTransport.getAirport("OPO"), airTransport.getAirport("EWR"));

    for (auto it = a.begin(); it != a.end(); it++) (*it)->print();

    cout << '\n';

    list<list<Airport*>> l = airTransport.flightsByCity(airTransport.getCity("New York", "United States"),
                                                        airTransport.getCity("Porto", "Portugal"));

    for (auto it = l.begin(); it != l.end(); it++) {
        for (auto it2 = it->begin(); it2 != it->end(); it2++)
            (*it2)->print();
        cout << '\n';
    }
}
