#include <valarray>
#include <iostream>
#include "Airport.h"

Airport::Airport(const string &code, const string &name, City* city, double lat,
                 double lon) {
    this->code = code;
    this->name = name;
    this->city = city;
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
    cout << code << ',' << name << ',';
    city->print();
}

string Airport::getName() const {
    return name;
}

void Airport::addFlight(const Flight &flight) {
    flights.push_back(flight);
}

bool Airport::isVisited() const {
    return visited;
}

void Airport::setVisited(bool b) {
    visited = b;
}

int Airport::getDistance() const {
    return distance;
}

void Airport::setDistance(int d) {
    distance = d;
}

Airport* Airport::getLast() const {
    return lastAirport;
}

void Airport::setLast(Airport *l) {
    lastAirport = l;
}

vector<Flight> Airport::getFlights() const {
    return flights;
}

double Airport::getLat() const {
    return lat;
}

double Airport::getLon() const {
    return lon;
}
