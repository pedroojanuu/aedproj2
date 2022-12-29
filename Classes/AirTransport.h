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
    vector<Airport*> getAirport(const string& code);
    City* getCity(const string &name, const string &country);
    list<list<Airport*>> getPaths(const vector<Airport*>& source, const vector<Airport*>& dest);
    vector<Airport*> getAirportsInRange(double lat, double lon, int dist);
    static double haversine(double lat1, double lon1, double lat2, double lon2);
    list<list<Airport*>> flightsBySpot(double lat1, double lon1, double lat2, double lon2, int dist1, int dist2);
    vector<Airport*> getAirportsInCity(City* city);
private:
    unordered_map<int, Airport*> airports;
    unordered_map<size_t, City*> cities;
    unordered_map<int, Airline*> airlines;
};


#endif //AED_PROJ2_AIRTRANSPORT_H
