#ifndef AED_PROJ2_AIRLINE_H
#define AED_PROJ2_AIRLINE_H


#include <string>

using namespace std;

class Airline {
public:
    Airline(const string& code, const string& name, const string& callsign, const string& country);
    static int hash(const string& code);
    void print() const;
private:
    string code;
    string name;
    string callsign;
    string country;
};


#endif //AED_PROJ2_AIRLINE_H
