#ifndef AED_PROJ2_AIRPORT_H
#define AED_PROJ2_AIRPORT_H

#include "City.h"

#include <string>

using namespace std;

class Airport {
public:
    Airport(std::string code, std::string name, string city, std::string country, double lat, double lon);
private:
    string code;
    string name;
    string city;
    string country;
    double lat;
    double lon;
};


#endif //AED_PROJ2_AIRPORT_H
