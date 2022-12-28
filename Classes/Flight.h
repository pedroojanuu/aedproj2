#ifndef AED_PROJ2_FLIGHT_H
#define AED_PROJ2_FLIGHT_H


#include "Airport.h"
#include "Airline.h"

class Flight {
public:
    Flight(Airport* source, Airport* dest, Airline* airline);
private:
    Airport* source;
    Airport* dest;
    Airline* airline;
};


#endif //AED_PROJ2_FLIGHT_H
