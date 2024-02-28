#ifndef CITY_OPERATIONS_CPP
#define CITY_OPERATIONS_CPP

#include <iostream>
#include "City.h"
#include "Non_capital.h"
#include "Capital.h"
#include "Menu.h"
#include "Converter.h"
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

// global const variables
const double Koffset = 273.15;
const double Kmultiplier = 1;
const double Fmultiplier = (9 / 5);
const double Foffset = 32;

// Global functions
bool min_val(City* c1, City* c2)

{

    return c1->get_min() < c2->get_min();

}

bool max_val(City* c1, City* c2)

{

    return c1->get_max() > c2->get_max();

}

bool avg_val_ascending(City* c1, City* c2)

{

    return c1->get_avg() < c2->get_avg();

}

CityOperations::CityOperations() {
    cities = {};
}
void CityOperations:: set_cities(vector<City*> cities) {
    this->cities = cities;
}

void CityOperations::display_cities(vector<City*> cities)
{
    cout << setw(5) << left << "No." << setw(25) << left << "City name" << setw(15) << right << "Min temp" << setw(20) << right << "       Max temp" << setw(20) << right << "      Avg temp" << endl;

    for (int i = 0; i < cities.size(); i++) {
        if (i < 9) {
            cout << "0" << i + 1 << ". " << setw(3) << right << "  ";
        }
        else {
            cout << setw(2) << left << i + 1 << ". " << setw(3) << right << "  ";
        }
        cities[i]->display();
    }
}

void CityOperations::convert(vector<City*> cities, char unit) {
    cout << setw(5) << left << "No." << setw(25) << left << "City name" << setw(15) << right << "Min temp" << setw(20) << right << "       Max temp" << setw(20) << right << "      Avg temp" << endl;
    switch (unit) {

    case 'K':

    {

        for (int i = 0; i < cities.size(); i++) {
            if (i < 9) {
                cout << "0" << i + 1 << ". " << setw(3) << right << "  ";
            }
            else {
                cout << setw(2) << left << i + 1 << ". " << setw(3) << right << "  ";
            }
            Converter c(Kmultiplier, Koffset);
            double mini = c.converter(cities[i]->get_min());
            double maxi = c.converter(cities[i]->get_max());
            double avg = c.converter(cities[i]->get_avg());
            cout << setw(30) << left << cities[i]->get_name() << mini << "K" << setw(20) << right << maxi << "K" << setw(18) << right << avg << "K" << endl;
        }
        break;
    }

    case 'F':
    {
        for (int i = 0; i < cities.size(); i++) {
            if (i < 9) {
                cout << "0" << i + 1 << ". " << setw(3) << right << "  ";
            }
            else {
                cout << setw(2) << left << i + 1 << ". " << setw(3) << right << "  ";
            }
            Converter c2(Fmultiplier, Foffset);
            double mini = c2.converter(cities[i]->get_min());
            double maxi = c2.converter(cities[i]->get_max());
            double avg = c2.converter(cities[i]->get_avg());
            cout << setw(30) << left << cities[i]->get_name() << mini << "F " << setw(20) << right << maxi << "F" << setw(20) << right << avg << "F" << endl;
        }
        break;
    }
    default:
    {
        cout << "Invalid Input!!!\n";
        break;
    }
    }
}

void CityOperations::sort_cities(vector<City*> cities, int sort_choice)
{
    if (sort_choice == 1) {
        cout << "\nSorting on the basis of max temperature\n";
        cout << setw(5) << left << "No." << setw(25) << left << "City name" << setw(15) << right << "Max temp" << endl;
        sort(cities.begin(), cities.end(), max_val);

        for (int i = 0; i < cities.size(); i++)
        {
            if (i < 9) {

                cout << "0" << i + 1 << ". " << setw(3) << right << "  ";

            }

            else {

                cout << setw(2) << left << i + 1 << ". " << setw(3) << right << "  ";

            }
            cout << setw(30) << left << cities[i]->get_name() << setw(5) << right << cities[i]->get_max() << " C\n";
        }

    }

    if (sort_choice == 2) {

        cout << "\nSorting on the basis of min temperature\n";
        cout << setw(5) << left << "No." << setw(25) << left << "City name" << setw(15) << right << "       Min temp" << endl;
        sort(cities.begin(), cities.end(), min_val);
        for (int i = 0; i < cities.size(); i++)
        {
            if (i < 9) {

                cout << "0" << i + 1 << ". " << setw(3) << right << "  ";

            }

            else {

                cout << setw(2) << left << i + 1 << ". " << setw(3) << right << "  ";

            }
            cout << setw(30) << left << cities[i]->get_name() << setw(5) << right << cities[i]->get_min() << " C\n";
        }
    }
    if (sort_choice == 3) {
        cout << "Sorting on the basis of avg temperature\n";
        cout << setw(5) << left << "No." << setw(25) << left << "City name" << setw(15) << right << "       Avg temp" << endl;
        sort(cities.begin(), cities.end(), avg_val_ascending);
        for (int i = 0; i < cities.size(); i++)
        {
            if (i < 9) {
                cout << "0" << i + 1 << ". " << setw(3) << right << "  ";
            }
            else {
                cout << setw(2) << left << i + 1 << ". " << setw(3) << right << "  ";
            }
            cout << setw(30) << left << cities[i]->get_name() << setw(5) << right << cities[i]->get_avg() << " C\n";
        }
    }

}

void CityOperations::search_city(vector<City*> cities, string& city_name)

{
    int res = -1;

    try {
        // Check if the entered city_name is empty
        if (city_name.empty()) {
            throw invalid_argument("Invalid city name! Please enter a non-empty city name.");
        }

        for (int i = 0; i < city_name.length(); i++) {
            city_name[i] = tolower(city_name[i]);
        }

        for (int i = 0; i < cities.size(); i++) {
            if (cities[i]->get_name() == city_name) {
                res = i;
                break;
            }
        }

        if (res == -1) {
            cout << "!!!---City not found---!!!\n";
        }
        else {
            cout << setw(22) << left << "City name" << setw(15) << right << "Min temp" << setw(20) << right << "       Max temp" << setw(22) << right << "      Avg temp" << endl;
            cities[res]->display();
        }
    }
    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
}

void CityOperations::search_state(vector<City*> cities, string state_name)

{
    int res = -1;

    try {
        // Check if the entered city_name is empty
        if (state_name.empty()) {
            throw invalid_argument("Invalid city name! Please enter a non-empty city name.");
        }

        for (int i = 0; i < state_name.length(); i++) {
            state_name[i] = tolower(state_name[i]);
        }

        for (int i = 0; i < cities.size(); i++) {
            if (cities[i]->get_stateName() == state_name) {
                res = i;
                break;
            }
        }

        if (res == -1) {
            cout << "!!!---State not found---!!!\n";
        }
        else {
            cout << setw(22) << left << "city name" << setw(15) << right << "Min temp" << setw(20) << right << "       Max temp" << setw(22) << right << "      Avg temp" << endl;
            cities[res]->display();
        }
    }
    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
}
void CityOperations::delete_city(vector<City*> cities, string city_name)

{
    cout << setw(5) << left << "No." << setw(25) << left << "City name" << setw(15) << right << "Min temp" << setw(20) << right << "       Max temp" << setw(20) << right << "      Avg temp" << endl;
    int count = 0;

    try {
        // Check if the entered city_name is empty
        if (city_name.empty()) {
            throw invalid_argument("Invalid city name! Please enter a non-empty city name.");
        }

        for (int i = 0; i < cities.size(); i++) {
            if (cities[i]->get_name() == city_name) {
                count = i;
                continue;
            }
            else {
                if (count < 9) {
                    cout << "0" << count + 1 << ". " << setw(3) << right << "  ";
                }
                else {
                    cout << setw(2) << left << count + 1 << ". " << setw(3) << right << "  ";
                }
                cities[i]->display();
                count++;
            }
        }
    }
    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
}

#endif
