#ifndef AED_PROJ2_CITY_H
#define AED_PROJ2_CITY_H

#include <string>
#include <vector>
#include "Airport.h"

using namespace std;

class Airport;

class City {
public:
    City(const string& name, const string& country);
    static size_t hash(string name, const string& country);
    void addAirport(Airport* airport);
    vector<Airport*> getAirports() const;
    void print() const;
private:
    string name;
    string country;
    vector<Airport*> airports;
};


#endif //AED_PROJ2_CITY_H
