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

    l = airTransport.getPaths(airTransport.getAirportsInRange(40.143022, -8.020368, 200), airTransport.getAirport("LHR"));

    for (auto it = l.begin(); it != l.end(); it++) {
        for (auto it2 = it->begin(); it2 != it->end(); it2++)
            (*it2)->print();
        cout << '\n';
    }

    //vector<string> codes = {"RYR", "EZY", "BAW", "AAL"};

    //vector<Airline*> x = airTransport.getAirlines(codes);

    //for (Airline* airline : x) airline->print();

    vector<string>codes = {"EZY", "TAP", "RYR"};

    vector<Airline*>x = airTransport.getAirlines(codes);

    l = airTransport.getPaths(airTransport.getAirport("OPO"), airTransport.getAirport("EWR"), x);

    for (auto it = l.begin(); it != l.end(); it++) {
        for (auto it2 = it->begin(); it2 != it->end(); it2++)
            (*it2)->print();
        cout << '\n';
    }

    cout << airTransport.connectedComponents() << endl;

    airTransport.flightsByAirport(airTransport.getAirport("OPO"));

    return 0;
}
