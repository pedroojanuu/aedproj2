#include "Menu.h"
#include "AirTransport.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int readOption(int numberOfOptions) {
    string option;
    while(true) {
        cin >> option;
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

void Menu::mainMenu() {

    AirTransport airTransport;
    int option;

    cout << "\nEscolha uma opcao:\n" <<
    "1.Ver melhor maneira de voar de um local para outro\n" <<
    "2.Informacoes de um aeroporto\n" <<
    "3.Sair\n";

    option = readOption(3);

    switch(option) {
        case 1:
            pathMenu(airTransport);
            break;
        case 2:
            //infoMenu();
            break;
        case 3:
            cout << "Adeus!\n";
            return;
        default:
            return;
    }
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
                cin >> code;
                cout << endl;
                if(code.length() == 3 && airTransport.getAirport(code).size() == 1) break;
                cout << "Codigo invalido ou aeroporto inexistente.\n" <<
                "Por favor, tente novamente.\n";
            }
            source = airTransport.getAirport(code);
            break;
        case 2:
            while(true) {
                cout << "Insira o nome da cidade de origem:\n";
                cin >> name;
                cout << "\nInsira o nome do pais de origem:\n";
                cin >> country;
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
                cin >> latstr;
                cout << endl;
                if(is_float(latstr)) break;
                cout << "Latitude invalida.\n" <<
                "Por favor, tente novamente.\n";
            }
            cout << "Insira a longitude de origem:\n";
            while(true) {
                cin >> lonstr;
                cout << endl;
                if(is_float(lonstr)) break;
                cout << "Longitude invalida.\n" <<
                "Por favor, tente novamente.\n";
            }
            cout << "\nInsira a distancia maxima a origem:\n";
            while(true) {
                cin >> radiusstr;
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
                cin >> code;
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
                cin >> name;
                cout << "\nInsira o nome do pais de destino:\n";
                cin >> country;
                cout << endl;
                if(airTransport.getCity(name,country) != nullptr) break;
                cout << "Cidade ou pais inexistente.\n" <<
                     "Por favor, tente novamente.\n\n";
            }
            dest = AirTransport::getAirportsInCity(airTransport.getCity(name,country));
            break;
        case 3:
            cout << "Insira a latitude de destino:\n";
            while(true) {
                cin >> latstr;
                cout << endl;
                if(is_float(latstr)) break;
                cout << "Latitude invalida.\n" <<
                     "Por favor, tente novamente.\n";
            }
            cout << "Insira a longitude de destino:\n";
            while(true) {
                cin >> lonstr;
                cout << endl;
                if(is_float(lonstr)) break;
                cout << "Longitude invalida.\n" <<
                     "Por favor, tente novamente.\n";
            }
            cout << "\nInsira a distancia maxima a destino:\n";
            while(true) {
                cin >> radiusstr;
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
        cin >> answer;
        cout << endl;
        if(answer == "Sim" || answer == "Nao") break;
        cout << "Opcao invalida, por favor responda apenas Sim/Nao\n";
    }

    if(answer == "Sim") {
        cout << "Insira as companhias que desejar.\n"<<
        "Quando terminar, insira 0.\n";
        string airline;
        while(true) {
            cin >> airline;
            cout << endl;
            if(airline == "0") break;
            if(airTransport.getAirline(airline) != nullptr) desiredAirlines.push_back(airTransport.getAirline(airline));
            else cout << "Codigo de companhia invalido\n";
        }
    }

    auto paths = airTransport.getPaths(source,dest,desiredAirlines);
    for(const auto& path : paths) {
        for(auto airport : path) {
            airport->print();
        }
        cout << endl;
        cout << "Numero de voos: " << path.size()-1 << endl;
    }
}
