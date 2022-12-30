#include <iostream>
#include "Classes/AirTransport.h"
#include "Classes/Menu.h"

int main() {
    /*AirTransport airTransport;

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
    list<list<Airport*>> b = airTransport.getPaths(airTransport.getAirport("OPO"), airTransport.getAirportsInCity(airTransport.getCity("New York", "United States")));
    for (auto & it : b) {
        for (auto & it2 : it)
            it2->print();
        cout << '\n';
    }

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

    airTransport.flightsByAirport(airTransport.getAirport("LIS"));

    airTransport.flightsInRange(airTransport.getAirport("LIS"), 1);
*/

    while(Menu::mainMenu());
    //AirTransport airTransport;
    //cout << airTransport.diameter() << endl;

    //airTransport.globalStats();
    //airTransport.countryStats("Portugal");
    //airTransport.airlineStats(airTransport.getAirline("RYR"));
    //airTransport.topAirportsFlights(3);
    //airTransport.topAirportsAirlines(3);
    return 0;
}
