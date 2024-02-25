#ifndef CAPITAL_CPP
#define CAPITAL_CPP

#include <iostream>
#include "City.h"
#include "Capital.h"
using namespace std;

Capital::Capital(string name) : City(name) {
    size = 4;
    pTemp = new double* [size];
    for (int i = 0; i < size; i++) {
        pTemp[i] = new double[total_samples];
    }
    //this->state = state;
}
//string Capital::get_stateName() {
//    return this->state;
//}

#endif
