#ifndef CITY_H
#define CITY_H

#include <iostream>

#include<vector>

#include<string>

using namespace std;



#define total_samples 24

#define capital_size 4

#define non_capital_size 1



class City {

protected:

    string name;

    double max;

    double min;

    double avg;

    double** pTemp;

    int size;



public:

    //City();

    City(string name);

    string get_name();

    void accept(vector<double> temp);

    void display();

    int get_size();

    double get_max();

    double get_min();

    double get_avg();

    virtual string get_stateName() { return ""; };
};

#endif // !CITY_H
