#ifndef AED_PROJ2_AIRPORT_H
#define AED_PROJ2_AIRPORT_H

#include "City.h"
#include "Flight.h"

#include <string>
#include <unordered_set>

using namespace std;

class Flight;
class City;
class Airline;

/**
 * @class Airport implements
 * A class to represent an airport by its IATA code, name, city (which includes the country) and coordinates.\n
 * Since we represent the provided air traffic network by a directed graph, the Airports are the nodes, which leads to having
 * a vector of departing flights (which are the graph's edges), a boolean\a visited to represents if we have traversed
 * the node in a search, as well as an integer\a distance and a pointer to the airport where we 'came from', in order
 * to build a route.
 */

class Airport {
public:
    Airport(const string& code, const string& name, City* city, double lat, double lon); /*!< A constructor that receives a
 * a IATA code, a name, a pointer to a City and coordinates. */
    static int hash(const string& code); /*!< Hash function that returns an integer based on a given IATA code.
 * \n Complexity: the complexity of the function's algorithm is O(n), with \a n being the length of the given code.
 * However, given the context of the program and the provided air traffic dataset, since all IATA codes have exactly 3 characters
 * and the function is only called when it has previously been checked that the given input has 3 characters, the O(n) 'is' O(3),
 * which is O(1) complexity. */
    void print() const; /*!< Prints the airport's IATA code, name and calls City's print() method, in order to print the airport's
 * city name and country. */
    void addFlight(const Flight& flight); /*!< Adds a departing flight (graph's edge) to the airport's vector of departing flights. */
    bool isVisited() const; /*!< Returns whether the Airport (graph's node) has been visited (in a graph search). */
    void setVisited(bool b); /*!< Sets the\a visited field to a given\b boolean value. */
    int getDistance() const; /*!< In a graph search, returns the distance (in number of flights) to the airport (node) where
 * the search began. */
    void setDistance(int d); /*!< Sets the distance (in number of flights) to the airport where a graph search began
 * to a given number. */
    Airport* getLast() const; /*!< Returns a pointer to the airport where we 'came from' in a graph search, in order to build a route. */
    void setLast(Airport* l); /*!< Sets the field\a lastAirport to a given Airport pointer. */
    vector<Flight> getFlights() const; /*!< Returns a copy of the vector of the airport's departing flights. */
    double getLat() const; /*!< Returns the airport's latitude. */
    double getLon() const; /*!< Returns the airport's longitude. */
    string getName() const; /*!< Returns the airport's name. */
    City* getCity() const; /*!< Returns a pointer to the airport's city. */
    unordered_set<Airline*> getAirlines() const; /*!< Returns a set of pointers to the Airlines that operate departing flights
 * from the airport.\n Complexity: O(n), with\a n being the number of the airport's departing flights. */
private:
    string code; /*!< Airport's IATA code */
    string name; /*!< Airport's name */
    City* city; /*!< Pointer to the airport's city. */
    double lat; /*!< Airport's latitude. */
    double lon; /*!< Airport's longitude. */
    vector<Flight> flights; /*!< Vector of the airport's departing flights (edges of the air traffic network directed graph
 * that begin in the airport). */
    bool visited; /*!< Whether the airport has been visited or not in a graph search. */
    int distance; /*!< Distance (in number of flights) in a graph search to the airport where we initiated the search. */
    Airport* lastAirport; /*!< Pointer to the airport where we 'came from' in a graph search. */
};


#endif //AED_PROJ2_AIRPORT_H
