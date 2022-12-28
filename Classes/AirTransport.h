#ifndef AED_PROJ2_AIRTRANSPORT_H
#define AED_PROJ2_AIRTRANSPORT_H


#include <unordered_map>
#include <unordered_set>
#include <list>
#include "Airport.h"
#include "City.h"
#include "Airline.h"

class AirTransport {
public:
    AirTransport();
    //~AirTransport();
    void bfs(Airport* source);
    list<Airport*> shortestPath (Airport* source, Airport* dest);
    Airport* getAirport(const string& code);
    City* getCity(const string &name, const string &country);
    list<list<Airport*>> flightsByCity(City* source, City* dest);
private:
    unordered_map<int, Airport*> airports;
    unordered_map<size_t, City*> cities;
    unordered_map<int, Airline*> airlines;
};


#endif //AED_PROJ2_AIRTRANSPORT_H
