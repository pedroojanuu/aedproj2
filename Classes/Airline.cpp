#include <valarray>
#include <iostream>
#include "Airline.h"

Airline::Airline(const string& code, const string& name, const string& callsign, const string& country) {
    this->code = code;
    this->name = name;
    this->callsign = callsign;
    this->country = country;
}

int Airline::hash(const string& code) {
    int hashCode = 0;
    for (int i = 0; i < code.length(); i++) {
        hashCode += code[i] * pow(31, i);
    }
    return hashCode;
}

void Airline::print() const {
    cout << code << ',' << name << endl;
}

string Airline::getCode() const {
    return code;
}
