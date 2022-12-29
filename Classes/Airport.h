#ifndef AED_PROJ2_AIRPORT_H
#define AED_PROJ2_AIRPORT_H

#include "City.h"
#include "Flight.h"

#include <string>

using namespace std;

class Flight;
class City;

class Airport {
public:
    Airport(const string& code, const string& name, City* city, double lat, double lon);
    static int hash(const string& code);
    void print() const;
    void addFlight(const Flight& flight);
    bool isVisited() const;
    void setVisited(bool b);
    int getDistance() const;
    void setDistance(int d);
    Airport* getLast() const;
    void setLast(Airport* l);
    vector<Flight> getFlights() const;
    double getLat() const;
    double getLon() const;
private:
    string code;
    string name;
    City* city;
    double lat;
    double lon;
    vector<Flight> flights;
    bool visited;
    int distance;
    Airport* lastAirport;
};


#endif //AED_PROJ2_AIRPORT_H
