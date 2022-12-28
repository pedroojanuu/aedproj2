#include "AirTransport.h"

#include <fstream>
#include <sstream>
#include <iostream>

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

        Airline* airline = new Airline(code, name, callsign, country);
        airlines.insert({Airline::hash(code),airline});
    }

    ifs = ifstream("../resources/airports.csv");
    getline (ifs, line);

    while (getline(ifs, line)) {
        string code, name, city, country, lat, lon;
        istringstream iss(line);
        getline(iss, code, ',');
        getline(iss, name, ',');
        getline(iss, city, ',');
        getline(iss, country, ',');
        getline(iss, lat, ',');
        getline(iss, lon, ',');

        if (cities.empty() || cities.find(City::hash(city, country)) == cities.end()) {
            City* newCity = new City(city, country);
            cities.insert({City::hash(city, country), newCity});
        }

        Airport* airport = new Airport(code, name, city, country, stod(lat), stod(lon));
        airports.insert({Airport::hash(code), airport});

        cities[City::hash(city, country)]->addAirport(airport);
    }

    ifs = ifstream("../resources/flights.csv");
    getline(ifs, line);

    while (getline(ifs, line)) {
        string source, target, airline;

        istringstream iss(line);
        getline(iss, source, ',');
        getline(iss, target, ',');
        getline(iss, airline, ',');

        Flight flight = Flight(airports[Airport::hash(target)], airlines[Airline::hash(airline)]);

        airports[Airport::hash(source)]->addFlight(flight);
    }

    //for (const pair<const int, Airport*>& airport : airports) airport.second->print();
    //for (const pair<const size_t, City*>& city : cities) city.second->print();
    //for (const pair<const int, Airline*>& airline : airlines) airline.second->print();
}
