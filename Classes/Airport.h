#ifndef AED_PROJ2_AIRPORT_H
#define AED_PROJ2_AIRPORT_H

#include "City.h"
#include "Flight.h"

#include <string>

using namespace std;

class Flight;

class Airport {
public:
    Airport(const string& code, const string& name, const string& city, const string& country, double lat, double lon);
    static int hash(const string& code);
    void print() const;
    void addFlight(const Flight& flight);
private:
    string code;
    string name;
    string city;
    string country;
    double lat;
    double lon;
    vector<Flight> flights;
};


#endif //AED_PROJ2_AIRPORT_H
