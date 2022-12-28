#ifndef AED_PROJ2_FLIGHT_H
#define AED_PROJ2_FLIGHT_H


#include "Airport.h"
#include "Airline.h"

class Airport;

class Flight {
public:
    Flight(Airport* dest, Airline* airline);
    Airport* getDest() const;
private:
    Airport* dest;
    Airline* airline;
};


#endif //AED_PROJ2_FLIGHT_H
