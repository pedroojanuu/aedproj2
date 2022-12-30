#ifndef AED_PROJ2_CITY_H
#define AED_PROJ2_CITY_H

#include <string>
#include <vector>
#include "Airport.h"

using namespace std;

class Airport;

/**
 * @class City implements
 * A class that represents a city by its name, the name of its country and ts airports.
 */

class City {
public:
    City(const string& name, const string& country); /*!< A constructor that receives a city name and a country name. */
    static size_t hash(string name, const string& country); /*!< Hash function that returns an integer based on a given city name
 * and country name.\n Complexity: O(n), with\a n being the length of the city name concatenated with the country name. */
    void addAirport(Airport* airport); /*!< Adds a pointer to an Airport to the vector of the city's airports. */
    vector<Airport*> getAirports() const; /*!< Returns a vector of pointers to the city's airports. */
    void print() const; /*!< Prints the city's name and it country's name. */
    string getCountry() const; /*!< Returns the city's country name. */
private:
    string name; /*!< City's name */
    string country; /*!< City's country name */
    vector<Airport*> airports; /*!< Vector of pointers to the city's airports */
};


#endif //AED_PROJ2_CITY_H
