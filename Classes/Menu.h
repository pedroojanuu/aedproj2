
#ifndef AED_PROJ2_MENU_H
#define AED_PROJ2_MENU_H


#include "AirTransport.h"

/**
 * @class Menu implements
 * A class with no fields and only static methods that provides the program's user interface.
 */

class Menu {
public:
    static bool mainMenu(AirTransport& airTransport); /*!< Provides the UI main menu. Is called by main and receives
 * an instance of AirTransport in order to call the last's
 * necessary methods. */
    static void pathMenu(AirTransport& airTransport); /*!< Provides the UI first submenu, that helps the user find
 * paths between places. Is called by mainMenu() and receives an instance of AirTransport in order to call the last's
 * necessary methods. */
    static void infoMenu(AirTransport& airTransport); /*!< Provides the UI second submenu, that helps the user get information
 * about a desired airport. Is called by mainMenu() and receives an instance of AirTransport in order to call the last's
 * necessary methods. */
};


#endif //AED_PROJ2_MENU_H
