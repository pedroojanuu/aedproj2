#include "Menu.h"
#include "AirTransport.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int readOption(int numberOfOptions) {
    string option;
    while(true) {
        getline(cin, option);
        cout << endl;
        if(option.length() == 1 && isdigit(option[0]) && stoi(option) <= numberOfOptions && stoi(option) > 0) break;
        cout << "Numero invalido, por favor tente novamente.\n";
    }
    return stoi(option);
}


bool is_float(const std::string& s)
{
    char* end = nullptr;
    double val = strtod(s.c_str(), &end);
    return end != s.c_str() && *end == '\0' && val != HUGE_VAL;
}

bool Menu::mainMenu(AirTransport& airTransport) {

    int option;

    cout << "\nEscolha uma opcao:\n" <<
    "1. Ver melhor maneira de voar de um local para outro\n" <<
    "2. Informacoes de um aeroporto\n" <<
    "3. Estatisticas da rede\n"
    "4. Sair\n";

    option = readOption(4);

    switch(option) {
        case 1:
            pathMenu(airTransport);
            break;
        case 2:
            infoMenu(airTransport);
            break;
        case 3:
            statsMenu(airTransport);
            break;
        case 4:
            cout << "Adeus!\n";
            return false;
        default:
            return true;
    }
    return true;
}

void Menu::pathMenu(AirTransport& airTransport) {
    int option;

    cout << "Tipo de local de partida:\n" <<
         "1. Aeroporto\n" <<
         "2. Cidade\n" <<
         "3. Coordenadas e Raio\n" <<
         "4. Voltar ao Menu\n";

    option = readOption(4);
    vector<Airport*> source;
    string code;
    string name;
    string country;
    string latstr;
    string lonstr;
    string radiusstr;
    double lat;
    double lon;
    int radius;

    switch(option) {
        case 1:
            cout << "Insira o codigo do aeroporto de origem:\n";
            while(true) {
                getline(cin, code);
                cout << endl;
                if(code.length() == 3 && !airTransport.getAirport(code).empty()) break;
                else if(code.length() != 3) cout << "Codigo invalido.\n";
                else cout << "Aeroporto nao encontrado.\n";
                cout << "Por favor, tente novamente.\n";
            }
            source = airTransport.getAirport(code);
            break;
        case 2:
            while(true) {
                cout << "Insira o nome da cidade de origem:\n";
                getline(cin, name);
                cout << "\nInsira o nome do pais de origem:\n";
                getline(cin, country);
                cout << endl;
                if(airTransport.getCity(name,country) != nullptr) break;
                cout << "Cidade ou pais inexistente.\n" <<
                "Por favor, tente novamente.\n\n";
            }
            source = AirTransport::getAirportsInCity(airTransport.getCity(name,country));
            break;
        case 3:
            cout << "Insira a latitude de origem:\n";
            while(true) {
                getline(cin, latstr);
                cout << endl;
                if(is_float(latstr)) break;
                cout << "Latitude invalida.\n" <<
                "Por favor, tente novamente.\n";
            }
            cout << "Insira a longitude de origem:\n";
            while(true) {
                getline(cin, lonstr);
                cout << endl;
                if(is_float(lonstr)) break;
                cout << "Longitude invalida.\n" <<
                "Por favor, tente novamente.\n";
            }
            cout << "\nInsira a distancia maxima a origem:\n";
            while(true) {
                getline(cin, radiusstr);
                cout << endl;
                if (is_float(radiusstr) && stoi(radiusstr) >= 0) break;
                cout << "Distancia invalida.\n" <<
                     "Por favor, tente novamente.\n";
            }
            lat = stod(latstr);
            lon = stod(lonstr);
            radius = stoi(radiusstr);
            source = airTransport.getAirportsInRange(lat,lon,radius);
            break;
        case 4:
            return;
        default:
            return;
    }

    cout << "Tipo de local de destino:\n" <<
         "1. Aeroporto\n" <<
         "2. Cidade\n" <<
         "3. Coordenadas e Raio\n" <<
         "4. Voltar ao Menu\n";

    option = readOption(4);
    vector<Airport*> dest;

    switch(option) {
        case 1:
            cout << "Insira o codigo do aeroporto de destino:\n";
            while(true) {
                getline(cin, code);
                cout << endl;
                if(code.length() == 3 && airTransport.getAirport(code).size() == 1) break;
                cout << "Codigo invalido ou aeroporto inexistente.\n" <<
                     "Por favor, tente novamente.\n";
            }
            dest = airTransport.getAirport(code);
            break;
        case 2:
            while(true) {
                cout << "Insira o nome da cidade de destino:\n";
                getline(cin, name);
                cout << "\nInsira o nome do pais de destino:\n";
                getline(cin, country);
                cout << endl;
                if(airTransport.getCity(name,country) != nullptr) break;
                cout << "Cidade ou pais nao encontrados.\n" <<
                     "Por favor, tente novamente.\n\n";
            }
            dest = AirTransport::getAirportsInCity(airTransport.getCity(name,country));
            break;
        case 3:
            cout << "Insira a latitude de destino:\n";
            while(true) {
                getline(cin, latstr);
                cout << endl;
                if(is_float(latstr)) break;
                cout << "Latitude invalida.\n" <<
                     "Por favor, tente novamente.\n";
            }
            cout << "Insira a longitude de destino:\n";
            while(true) {
                getline(cin, lonstr);
                cout << endl;
                if(is_float(lonstr)) break;
                cout << "Longitude invalida.\n" <<
                     "Por favor, tente novamente.\n";
            }
            cout << "\nInsira a distancia maxima a destino:\n";
            while(true) {
                getline(cin, radiusstr);
                cout << endl;
                if (is_float(radiusstr) && stoi(radiusstr) >= 0) break;
                cout << "Distancia invalida.\n" <<
                     "Por favor, tente novamente.\n";
            }
            lat = stod(latstr);
            lon = stod(lonstr);
            radius = stoi(radiusstr);
            dest = airTransport.getAirportsInRange(lat,lon,radius);
            break;
        case 4:
            return;
        default:
            return;
    }
    string answer;
    vector<Airline*> desiredAirlines;
    cout << "Tem preferencia em relacao a companhias aereas? Sim/Nao\n";
    while(true) {
        getline(cin, answer);
        cout << endl;
        if(answer == "Sim" || answer == "Nao") break;
        cout << "Opcao invalida, por favor responda apenas Sim/Nao\n";
    }

    if(answer == "Sim") {
        cout << "Insira as companhias que desejar.\n"<<
        "Quando terminar, insira 0.\n";
        string airline;
        while(true) {
            getline(cin, airline);
            cout << endl;
            if(airline == "0") break;
            if(airTransport.getAirline(airline) != nullptr) desiredAirlines.push_back(airTransport.getAirline(airline));
            else cout << "Codigo de companhia invalido\n";
        }
    }

    auto paths = airTransport.getPaths(source,dest,desiredAirlines);
    for(const auto& path : paths) {
        for(auto airport : path) airport->print();
        cout << endl;
        if(!paths.begin()->empty()) cout << "Numero de voos: " << path.size()-1 << endl << endl;
    }
}

void Menu::infoMenu(AirTransport& airTransport) {
    cout << "Insira o codigo do aeroporto:\n";
    string code;
    while(true) {
        getline(cin, code);
        cout << endl;
        if(code.length() == 3 && !airTransport.getAirport(code).empty()) break;
        else if(code.length() != 3) cout << "Codigo invalido.\n";
        else cout << "Aeroporto nao encontrado.\n";
        cout << "Por favor, tente novamente.\n";
    }
    airTransport.flightsByAirport(airTransport.getAirport(code));

    cout << "\nInsira um numero maximo de voos:\n";
    string num;
    while (true) {
        getline(cin, num);
        cout << endl;
        if (is_float(num) && stoi(num) >= 1) break;
        cout << "Numero invalido.\nPor favor tente novamente." << endl;
    }
    airTransport.flightsInRange(airTransport.getAirport(code), stoi(num));
}

void Menu::statsMenu(AirTransport& airTransport) {
    int option;

    cout << "Escolha uma opcao:\n" <<
         "1. Estatisticas globais\n" <<
         "2. Estatisticas de um pais\n" <<
         "3. Estatisticas de uma companhia\n"
         "4. Voltar ao Menu\n";

    option = readOption(4);
    string country;
    string airline;
    int diam;
    string k;
    switch(option) {
        case 1:
            airTransport.globalStats();
            cout << "\nA calcular diametro do componente principal..." << endl;
            diam = airTransport.diameter();
            cout << "\nDiametro do componente principal: " << diam << endl;
            cout << "\nInsira um numero para apresentar o top de aeroportos com mais partidas e com mais companhias a partir deles" << endl;
            getline(cin, k);
            if (is_float(k) && stoi(k) >= 1) {
                airTransport.topAirportsFlights(stoi(k));
                airTransport.topAirportsAirlines(stoi(k));
            } else cout << "Numero invalido" << endl;
            break;
        case 2:
            cout << "Insira o nome do pais:\n";
            getline(cin,country);
            cout << endl;
            airTransport.countryStats(country);
            break;
        case 3:
            cout << "Insira o codigo da companhia:\n";
            while(true) {
                getline(cin,airline);
                cout << endl;
                if(airline.length() == 3 || airTransport.getAirline(airline) != nullptr) break;
                cout << "Codigo invalido. Por favor, insira novamente.\n";
            }
            airTransport.airlineStats(airTransport.getAirline(airline));
        case 4:
            return;
        default:
            return;
    }
}
