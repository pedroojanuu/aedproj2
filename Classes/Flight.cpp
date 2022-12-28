#include "Flight.h"

Flight::Flight(Airport *dest, Airline *airline) {
    this->dest = dest;
    this->airline = airline;
}

Airport* Flight::getDest() const {
    return dest;
}
