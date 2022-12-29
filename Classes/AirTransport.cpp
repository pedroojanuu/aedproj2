#include "AirTransport.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

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

        Airport* airport = new Airport(code, name, cities[City::hash(city, country)], stod(lat), stod(lon));
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

void AirTransport::bfs(Airport* source) {
    for (const pair<int, Airport*>& airport : airports) airport.second->setVisited(false);
    queue<Airport*> q;
    q.push(source);
    source->setVisited(true);
    source->setDistance(0);
    while (!q.empty()) {
        Airport* u = q.front(); q.pop();
        //u->print();
        for (const Flight& flight : u->getFlights()) {
            Airport* dest = flight.getDest();
            if (!dest->isVisited()) {
                q.push(dest);
                dest->setVisited(true);
                dest->setDistance(u->getDistance() + 1);
                dest->setLast(u);
            }
        }
    }
}

void AirTransport::bfs(Airport* source, const vector<Airline*>& desiredAirlines) {
    for (const pair<int, Airport*>& airport : airports) airport.second->setVisited(false);
    queue<Airport*> q;
    q.push(source);
    source->setVisited(true);
    source->setDistance(0);
    while (!q.empty()) {
        Airport* u = q.front(); q.pop();
        //u->print();
        for (const Flight& flight : u->getFlights()) {
            Airline* airline = flight.getAirline();
            if (find(desiredAirlines.begin(), desiredAirlines.end(), airline) != desiredAirlines.end()) {
                Airport* dest = flight.getDest();
                if (!dest->isVisited()) {
                    q.push(dest);
                    dest->setVisited(true);
                    dest->setDistance(u->getDistance() + 1);
                    dest->setLast(u);
                }
            }
        }
    }
}

list<Airport*> AirTransport::shortestPath(Airport *source, Airport *dest, const vector<Airline*>& desiredAirlines) {
    list<Airport*> ret;
    if (source == nullptr) {
        cout << "Aeroporto de origem nao existe.";
        return ret;
    }
    if (dest == nullptr) {
        cout << "Aeroporto de destino nao existe.";
        return ret;
    }
    if (desiredAirlines.empty()) bfs(source);
    else bfs(source, desiredAirlines);

    if(!dest->isVisited() && desiredAirlines.empty()) {
        cout << "Nao existe ligacao entre " << source->getName() << " e " << dest->getName() <<".\n";
        return ret;
    } else if (!dest->isVisited()) {
        cout << "Nao existe ligacao entre " << source->getName() << " e " << dest->getName() << " com a(s) companhia(s) escolhida(s).\n";
        return ret;
    }

    while (dest != source) {
        ret.push_front(dest);
        dest = dest->getLast();
    }
    ret.push_front(source);
    return ret;
}

vector<Airport*> AirTransport::getAirport(const string &code) {
    vector<Airport*> ret;
    if (airports.find(Airport::hash(code)) == airports.end()) return ret;
    ret.push_back(airports[Airport::hash(code)]);
    return ret;
}

City* AirTransport::getCity(const string& name, const string& country) {
    if (cities.find(City::hash(name, country)) == cities.end()) return nullptr;
    return cities[City::hash(name, country)];
}

vector<Airport*> AirTransport::getAirportsInCity(City* city) {
    return city->getAirports();
}

list<list<Airport*>> AirTransport::getPaths(const vector<Airport*>& source, const vector<Airport*>& dest, const vector<Airline*>& desiredAirlines) {
    list<list<Airport*>> ret;
    for (Airport* src : source) {
        for (Airport * dst : dest) {
            list<Airport*> path = shortestPath(src, dst, desiredAirlines);
            if (ret.empty() || ret.back().size() == path.size()) ret.push_back(path);
            else if (ret.back().size() > path.size()) {
                ret.pop_back();
                ret.push_back(path);
            }
        }
    }
    return ret;
}

double AirTransport::haversine(double lat1, double lon1, double lat2, double lon2) {
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}

vector<Airport*> AirTransport::getAirportsInRange(double lat, double lon, int dist) {
    vector<Airport*> ret;
    for (pair<const int, Airport *> p : airports)
        if (haversine(p.second->getLat(), p.second->getLon(), lat, lon) <= dist)
            ret.push_back(p.second);
    return ret;
}

void AirTransport::dfs(Airport* source) {
    source->setVisited(true);
    for (auto flight : source->getFlights()) {
        Airport* dest = flight.getDest();
        if (!dest->isVisited())
            dfs(dest);
    }
}

int AirTransport::connectedComponents() {
    int counter = 0;
    for (auto x : airports)
        x.second->setVisited(false);
    for (auto x : airports)
        if (!x.second->isVisited()) {
            counter++;
            dfs(x.second);
        }
    return counter;
}

vector<Airline*> AirTransport::getAirlines(const vector<string>& codes) {
    vector<Airline*> ret;
    for (const string& code : codes) ret.push_back(airlines[Airline::hash(code)]);
    return ret;
}

void AirTransport::flightsByAirport(const vector<Airport*>& airport) const {
    unordered_set<Airline*> airlines;
    unordered_set<City*> cities;
    unordered_set<string> countries;
    unsigned counter = 0;
    for (const Flight& flight : airport[0]->getFlights()) {
        counter++;
        airlines.insert(flight.getAirline());
        cities.insert(flight.getDest()->getCity());
        countries.insert(flight.getDest()->getCity()->getCountry());
        flight.getDest()->print();
        flight.getAirline()->print();
        cout << '\n';
    }
    cout << "\nExistem " << counter << " voos a partir deste aeroporto, para " << cities.size() << " cidades de " << countries.size() <<
    " paises, de " << airlines.size() << " companhias diferentes.\n";
}

void AirTransport::flightsInRange(const vector<Airport*>& airport, int maxflights) {
    unsigned counter = 0;
    unordered_set<City*> cities;
    unordered_set<string> countries;
    bfs(airport[0]);
    for (auto p : airports)
        if (p.second->isVisited() && p.second->getDistance() <= maxflights && p.second!=airport[0]) {
            counter++;
            cities.insert(p.second->getCity());
            countries.insert(p.second->getCity()->getCountry());
        }
    cout << "\nExistem " << counter << " aeroportos, em " << cities.size() << " cidades, de " << countries.size() <<
    " paises atingiveis com um maximo de " << maxflights << " voo(s).\n";
}
