#ifndef AED_PROJ2_FLIGHT_H
#define AED_PROJ2_FLIGHT_H


#include "Airport.h"
#include "Airline.h"

class Airport;

/**
 * @class Flight implements
 * A class that represents a flight by its airline and destination. Given our graph structure, a flight is a edge of the graph.
 */

class Flight {
public:
    Flight(Airport* dest, Airline* airline); /*!< A constructor that receives a pointer to the destination airport
 * and a pointer to the airline that operates it. */
    Airport* getDest() const; /*!< Returns a pointer to the flight's destination airport. */
    Airline* getAirline() const; /*!< Returns a pointer to the airline that operates the flight. */
private:
    Airport* dest; /*!< A pointer to the flight's destination airport */
    Airline* airline; /*!< A pointer to the airline that operates the flight */
};


#endif //AED_PROJ2_FLIGHT_H
