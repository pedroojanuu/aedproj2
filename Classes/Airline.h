#ifndef AED_PROJ2_AIRLINE_H
#define AED_PROJ2_AIRLINE_H


#include <string>

using namespace std;

/** @class Airline class implements
 * A class that represents an air carrier by its ICAO code, name, callsign and the country where it's registered.
 */

class Airline {
public:
    Airline(const string& code, const string& name, const string& callsign, const string& country); /*!< A constructor that
 * receives a ICAO code, a name, a callsign and a country name. */
    static int hash(const string& code); /*!< Hash function that returns an integer based on a given ICAO code.
 * \n Complexity: the complexity of the function's algorithm is O(n), with \a n being the length of the given code.
 * However, given the context of the program and the provided air traffic dataset, since all ICAO codes have exactly 3 characters
 * and the function is only called when it has previously been checked that the given input has 3 characters, the O(n) 'is' O(3),
 * which is O(1) complexity. */
    void print() const; /*!< Prints the airline's ICAO code and name. */
    string getCode() const; /*!< Returns the airline's ICAO code. */
    string getName() const; /*!< Returns the airline's name. */
    string getCountry() const; /*!< Returns the name of the country where the airline is registered. */
private:
    string code; /*!< Airline's ICAO code. */
    string name; /*!< Airline's name. */
    string callsign; /*!< Airline's callsign. */
    string country; /*!< Airline's country of registration. */
};


#endif //AED_PROJ2_AIRLINE_H
