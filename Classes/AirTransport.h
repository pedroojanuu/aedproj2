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
 * This is important to build routes.\n Complexity: O(|V| + |E|), where |V| is the number of airports and |E| the number of flights. */
    void bfs(Airport* source, const vector<Airline*>& desiredAirlines); /*!< Same as the BFS implementation but with airline
 * filtering, allowing to make only certain edges (flights of the desired airlines) eligible for traversing. */
    void dfs(Airport* source); /*!< Implementation of Depth-First-Search given a source airport\n
 * Complexity: O(|V| + |E|). */
    int connectedComponents(); /*!< Returns the numbers of the air traffic network connected components (i.e., groups of airports
 * that are only reachable from within their group).\n Complexity: O(|V|²). */
    list<Airport*> shortestPath (Airport* source, Airport* dest, const vector<Airline*>& desiredAirlines);
    vector<Airport*> getAirport(const string& code);
    City* getCity(const string &name, const string &country);
    list<list<Airport*>> getPaths(const vector<Airport*>& source, const vector<Airport*>& dest, const vector<Airline*>& desiredAirlines = vector<Airline*>());
    vector<Airport*> getAirportsInRange(double lat, double lon, int dist);
    static double haversine(double lat1, double lon1, double lat2, double lon2);
    static vector<Airport*> getAirportsInCity(City* city);
    Airline* getAirline(const string& code);
    void flightsByAirport(const vector<Airport*>& airport) const;
    void flightsInRange(const vector<Airport*>& airport, int maxflights);
    int diameter();
    int componentSize(Airport *source);
    int maxSize();
    void globalStats();
    void countryStats(const string& country);
    void airlineStats(Airline* airline);
    void topAirportsFlights(unsigned k);
    void topAirportsAirlines(unsigned k);
private:
    unordered_map<int, Airport*> airports;
    unordered_map<size_t, City*> cities;
    unordered_map<int, Airline*> airlines;
};


#endif //AED_PROJ2_AIRTRANSPORT_H
