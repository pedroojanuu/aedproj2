#include "Classes/AirTransport.h"
#include "Classes/Menu.h"

/*! \mainpage Projeto 2 AED
* This is a tender for the second practical assignment of the
* course Algoritmos e Estruturas de Dados of the Licenciatura em Engenharia
* Informática e Computação of the Faculty of Engineering of the University of Porto
* and the Faculty of Sciences of the University of Porto.
* It was made by the students João das Neves Fernandes (202108867)
* (up202108867@edu.fe.up.pt) and
* Pedro Simão Januário Vieira (202108768) (up202108768@edu.fe.up.pt), both belonging to Group No. 10, from class 2LEIC01.\n \n
 * It supports showing the best way to travel by airplane between two places, information about a given airport and general
 * statistics about the provided air traffic network.\n \n
 * We have represented the air traffic network by a directed graph, where the airport are the nodes and the flights are the edges.
 * Each airport has a vector of departing flights.\n \n
 * Since we used dynamic memory allocation, we had to test for memory leaks. However, since João works in Ubuntu and Pedro
 * works in Windows, due to compatibility problems during the process in Windows, João completed this step on Linux and,
 * after making sure there were no more leaks, we ended up not testing for them anymore upon runtime to avoid further problems.
 * For this reason, no memory leaks checking flag will be found on our compiler options.\n \n
 * The logo photo was taken by Pedro Januário on Porto Airport (OPO) on the 1st of May 2017.
 * It is licensed under the Creative Commons Attribution-Share Alike 4.0 International license.
 * It can be found on https://commons.wikimedia.org/wiki/File:Ryanair_B738_departing_LPPR.jpg
*/

int main() {
    AirTransport airTransport;
    while(Menu::mainMenu(airTransport));
    return 0;
}
