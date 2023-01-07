#ifndef AED_PROJ2_AIRTRANSPORT_H
#define AED_PROJ2_AIRTRANSPORT_H


#include <unordered_map>
#include <unordered_set>
#include <list>
#include "Airport.h"
#include "City.h"
#include "Airline.h"

/**
 * @class AirTransport implements
 * A class that serves the purpose of having all the information about the network and operations over it centralized.\n
 * It accommodates pointers to all Airports, Cities and Airlines.\n
 * As described in the documentation's main page, the given network is represented in a Graph, where Airports are the
 * nodes and Flights are the edges.
 */

class AirTransport {
public:
    AirTransport(); /*!< Default constructor. Reads the provided csv files and dynamically allocates memory for the
 * airports, cities and airlines, which leads us to using pointers all along the program. */
    ~AirTransport(); /*!< Destructor that deletes the Airline, City and Airport objects initially created by the constructor. */
    void bfs(Airport* source); /*!< Implementation of Breadth-First-Search given a source airport. It marks the visited airports as
 * so and stores the distance to the source airport, as well as storing, for each airport it traverses, the last visited airport.
 * This is important to build routes.\n Complexity: O(|V|+|E|), where |V| is the number of airports and |E| the number of flights. */
    void bfs(Airport* source, const vector<Airline*>& desiredAirlines); /*!< Same as the BFS implementation but with airline
 * filtering, allowing to make only certain edges (flights of the desired airlines) eligible for traversing. */
    void dfs(Airport* source); /*!< Implementation of Depth-First-Search given a source airport\n
 * Complexity: O(|V|+|E|). */
    int connectedComponents(); /*!< Returns the numbers of the air traffic network connected components (i.e., groups of airports
 * that are only reachable from within their group).\n Complexity: O(|V|²). */
    list<Airport*> shortestPath (Airport* source, Airport* dest, const vector<Airline*>& desiredAirlines); /*!< Returns one of the
 * shortest paths between two given airports filtering by desired airlines (empty if no preference).\n
 * Complexity: O(|V|+|E|) (bfs call). */
    vector<Airport*> getAirport(const string& code); /*!< Returns a pointer to the airport with given IATA code or \a nullptr if
 * it does not exist.\n Complexity: O(1). */
    City* getCity(const string &name, const string &country); /*!< Returns a pointer to the city with given name and country
 * or \a nullptr if it does not exist.\n Complexity: O(1). */
    list<list<Airport*>> getPaths(const vector<Airport*>& source, const vector<Airport*>& dest, const vector<Airline*>& desiredAirlines = vector<Airline*>());/*!<
 * Returns, for a given list of source Airports (pointers to them) and a given list of destination Airports, a list of, for each pair
 * Source Airport, Destination Airport, one of the shortest path between them.\n Complexity: O(|V|²(|V| + |E|)). */
    vector<Airport*> getAirportsInRange(double lat, double lon, int dist); /*!< Returns a vector of pointers to all the airports
 * in a given radius (in kilometres), given a center by its latitude and its longitude.\n Complexity: O(|V|). */
    static double haversine(double lat1, double lon1, double lat2, double lon2); /*!< Returns a distance between two points
 * given their latitudes and longitudes (implementing the Haversine formula).\n Complexity: O(1). */
    static vector<Airport*> getAirportsInCity(City* city); /*!< Returns a vector of pointers to all the airports in a given City
 * pointer.\n Complexity: O(1). */
    Airline* getAirline(const string& code); /*!< Given an ICAO code, returns a pointer to the airline it belongs to or \a nullptr
 * if it does not exist.\n Complexity: O(1). */
    void flightsByAirport(const vector<Airport*>& airport) const; /*!< Given an airport, prints on terminal all flights leaving that
 * airport, together with the total number of flights, cities and countries of destination and airlines used.\n Complexity: O(|E|),
 * where |E| is the number of flights of that airport. */
    void flightsInRange(const vector<Airport*>& airport, int maxflights); /*!< Given an airport, prints on terminal all airports reachable
 * with \i maxflights flights or less. \n Complexity O(|E|), where |E| is the number of flights of that airport. */
    int diameter(); /*!< Returns the diameter of the largest connected component (with most airports). \n Complexity: O(|V|(|V|+|E|)²). */
    int componentSize(Airport *source); /*!< Given an airport, returns the connected component size that it belongs  Complexity: O(V+E) (dfs call). */
    int maxSize(); /*!< Returns the size of the largest component (with most airports). \n Complexity: O(|V|(|V|+|E|)). */
    void globalStats(); /*!< Prints on terminal the total number of airports, airlines and flights. \n Complexity: O(|V|). */
    void countryStats(const string& country); /*!< Given a country, prints on terminal the number of airports, airlines and flights leaving that country.
 * \n Complexity: O(|V|+|A|), where |V| is the number of airports and |A| is the number of airlines. */
    void airlineStats(Airline* airline); /*!< Given an airline, prints on terminal the number of flights of that airline, as well as the number of airports
 * it departs from. \n Complexity: O(|V|+|E|). */
    void topAirportsFlights(unsigned k); /*!< Given a number k, prints on terminal the top k airports, sorted by number of flights. \n Complexity: O(|V|log(|V|)). */
    void topAirportsAirlines(unsigned k);  /*!< Given a number k, prints on terminal the top k airports, sorted by number of airlines. \n Complexity: O(|V|log(|E|)). */
private:
    unordered_map<int, Airport*> airports; /*!< map with all airports of the network.  */
    unordered_map<size_t, City*> cities; /*!< map with all cities from the network. */
    unordered_map<int, Airline*> airlines; /*!< map with all airlines from the network. */
};


#endif //AED_PROJ2_AIRTRANSPORT_H
