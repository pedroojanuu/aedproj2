#include "Airline.h"

Airline::Airline(string code, string name, string callsign, string country) {
    code = code;
    name = name;
    callsign = callsign;
    country = country;
}

bool Airline::operator<(const Airline &b) const {
    return code < b.code;
}
