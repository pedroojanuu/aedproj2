#include <iostream>
#include "Classes/AirTransport.h"

int main() {
    AirTransport airTransport;

    list<list<Airport*>> a = airTransport.getPaths(airTransport.getAirport("OPO"), airTransport.getAirport("EWR"));

    for (auto it = a.begin(); it != a.end(); it++) {
        for (auto it2 = it->begin(); it2 != it->end(); it2++)
            (*it2)->print();
        cout << '\n';
    }

    list<list<Airport*>> l = airTransport.getPaths(airTransport.getAirportsInCity(airTransport.getCity("New York", "United States")),
                                                   airTransport.getAirportsInCity(airTransport.getCity("Porto", "Portugal")));

    for (auto it = l.begin(); it != l.end(); it++) {
        for (auto it2 = it->begin(); it2 != it->end(); it2++)
            (*it2)->print();
        cout << '\n';
    }


}
