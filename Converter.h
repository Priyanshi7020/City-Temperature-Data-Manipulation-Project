#ifndef CONVERTER_H
#define CONVERTER_H

#include "Menu.h"
#include "City.h"
#include "Capital.h"
#include "Non_capital.h"
#include<iostream>
using namespace std;

class Converter {
	double multiplier;
	double offset;

public:
	Converter();
	Converter(const double multiplier, const double offset);
	double converter(double num);
};

#endif // 
