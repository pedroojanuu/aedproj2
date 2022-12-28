#include "AirTransport.h"

#include <fstream>
#include <sstream>

using namespace std;

AirTransport::AirTransport() {
    ifstream ifs("../resources/airlines.csv");
    string line;
    getline(ifs, line);

    while (getline(ifs, line)) {
        string code, name, callsign, country;
        istringstream iss(line);
        getline(iss, code, ',');
        getline(iss, name, ',');
        getline(iss, callsign, ',');
        getline(iss, country);

        Airline airline = Airline(code, name, callsign, country);
        airlines.insert(airline);
    }

    ifs = ifstream("../resources/airports.csv");
    getline (ifs, line);

    vector<City> aux;

    while (getline(ifs, line)) {
        string code, name, city, country, lat, lon;
        istringstream iss(line);
        getline(iss, code, ',');
        getline(iss, name, ',');
        getline(iss, country, ',');
        getline(iss, lat, ',');
        getline(iss, lon, ',');
    }
}
