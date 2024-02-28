#ifndef CAPITAL_H

#define CAPITAL_H

#include <iostream>
#include "City.h"

class Capital : public City {
    string state;
public:
    Capital(string name);
    Capital(string name, string state);
    string get_stateName();

};

#endif
