
#ifndef AED_PROJ2_MENU_H
#define AED_PROJ2_MENU_H


#include "AirTransport.h"

class Menu {
public:
    static void mainMenu();
    static void pathMenu(AirTransport& airTransport);
    static void infoMenu(AirTransport& airTransport);
};


#endif //AED_PROJ2_MENU_H
