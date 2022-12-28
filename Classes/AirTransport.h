#ifndef AED_PROJ2_AIRTRANSPORT_H
#define AED_PROJ2_AIRTRANSPORT_H


#include <unordered_map>
#include <unordered_set>
#include <set>
#include "Airport.h"
#include "City.h"
#include "Airline.h"

class AirTransport {
public:
    AirTransport();
    //~AirTransport();
private:
    unordered_map<int, Airport*> airports;
    unordered_map<size_t, City*> cities;
    unordered_map<int, Airline*> airlines;
};


#endif //AED_PROJ2_AIRTRANSPORT_H
