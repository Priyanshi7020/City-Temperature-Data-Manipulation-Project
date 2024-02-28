#ifndef CONVERTER_CPP
#define CONVERTER_CPP

#include "Menu.h"
#include "City.h"
#include "Capital.h"
#include "Non_capital.h"
#include "Converter.h"
#include<iostream>
using namespace std;


Converter::Converter() {
	multiplier = 0;
	offset = 0;
}
Converter::Converter(const double multiplier, const double offset) {
	this->multiplier = multiplier;
	this->offset = offset;
}
double Converter::converter(double num) {
	return num * (double)multiplier + (double)offset;
}

#endif // 
