
#ifndef AED_PROJ2_MENU_H
#define AED_PROJ2_MENU_H


#include "AirTransport.h"

class Menu {
public:
    static bool mainMenu(AirTransport& airTransport);
    static void pathMenu(AirTransport& airTransport);
    static void infoMenu(AirTransport& airTransport);
    static void statsMenu(AirTransport& transport);
};


#endif //AED_PROJ2_MENU_H
