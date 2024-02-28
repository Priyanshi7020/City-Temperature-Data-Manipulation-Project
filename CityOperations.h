#ifndef CITY_OPERATIONS_H
#define CITY_OPERATIONS_H

#include <iostream>
#include "City.h"
#include "Non_capital.h"
#include "Capital.h"
#include "Menu.h"
#include <vector>

class CityOperations {
	vector<City*> cities;
public:
	CityOperations();
	void set_cities(vector<City*> cities);
	void display_cities(vector<City*> cities);
	void convert(vector<City*> cities, char unit);
	void sort_cities(vector<City*> cities, int sort_choice);
	void search_city(vector<City*> cities, string& city_name);
	void search_state(vector<City*> cities, string state_name);
	void delete_city(vector<City*> cities, string city_name);

};

bool min_val(City* c1, City* c2);
bool max_val(City* c1, City* c2);
bool avg_val_ascending(City* c1, City* c2);
#endif 
