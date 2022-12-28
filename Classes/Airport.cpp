#include <valarray>
#include <iostream>
#include "Airport.h"

Airport::Airport(const string &code, const string &name, const string &city, const string &country, double lat,
                 double lon) {
    this->code = code;
    this->name = name;
    this->city = city;
    this->country = country;
    this->lat = lat;
    this->lon = lon;
}

int Airport::hash(const string &code) {
    int hashCode = 0;
    for (int i = 0; i < code.length(); i++) {
        hashCode += code[i] * pow(31, i);
    }
    return hashCode;
}

void Airport::print() const {
    cout << code << ',' << name << ',' << city << endl;
}

void Airport::addFlight(const Flight &flight) {
    flights.push_back(flight);
}
