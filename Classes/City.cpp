#include <valarray>
#include <iostream>
#include <string>
#include "City.h"

City::City(const string &name, const string &country) {
    this->name = name;
    this->country = country;
}

size_t City::hash(string name, const string& country) {
    std::hash<string> hash;
    name += country;
    return hash(name);
}

void City::addAirport(Airport *airport) {
    airports.push_back(airport);
}

void City::print() const {
    cout << name << ',' << country << endl;
}
