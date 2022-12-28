#ifndef AED_PROJ2_AIRLINE_H
#define AED_PROJ2_AIRLINE_H


#include <string>

using namespace std;

class Airline {
public:
    Airline(string code, string name, string callsign, string country);
    bool operator<(const Airline& b) const;
private:
    string code;
    string name;
    string callsign;
    string country;
};


#endif //AED_PROJ2_AIRLINE_H
