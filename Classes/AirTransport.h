#ifndef AED_PROJ2_AIRTRANSPORT_H
#define AED_PROJ2_AIRTRANSPORT_H


#include <unordered_map>
#include <set>
#include "Airport.h"
#include "City.h"
#include "Airline.h"

class AirTransport {
public:
    AirTransport();
private:
    unordered_map<int, Airport> airports;
    unordered_map<int, City> cities;
    set<Airline> airlines;
};


#endif //AED_PROJ2_AIRTRANSPORT_H
