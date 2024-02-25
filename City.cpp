#ifndef CITY_CPP

#define CITY_CPP



#include "city.h"

#include <iostream>

#include <algorithm>

#include <cmath>

#include <string>

#include <iomanip>



using namespace std;



//City::City() {

//    name = "";

//}



City::City(string name)

{

    this->name = name;

}



string City::get_name() {

    return name;

}

int City::get_size() {

    return size;

}



void City::accept(vector<double> temp) {

    int count = 0;

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < total_samples; j++) {

            pTemp[i][j] = temp[count++];

        }

    }

}



double City::get_max() {

    double maxi = -200;

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < total_samples; j++) {

            maxi = (maxi > pTemp[i][j]) ? maxi : pTemp[i][j];

        }

    }

    return maxi;

}



double City::get_min() {

    double mini = 1000;

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < total_samples; j++) {

            mini = (mini < pTemp[i][j]) ? mini : pTemp[i][j];

        }

    }

    return mini;

}



double City::get_avg() {

    double sum = 0;

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < total_samples; j++) {

            sum += pTemp[i][j];

        }

    }

    int elements = size * total_samples;

    return sum / elements;

}



void City::display() {

    //cout << "inside display()\n";
    switch (size) {
    case 1:
        cout << setw(10) << left << name << "   ";
        cout << setw(20) << right << get_min() << "C"<<setw(18)<<left << "    "<< get_max() << "C" << setw(16) << right << "    " << get_avg() << "C" << endl;
        break;

    case 4:
        cout << setw(10) << left << name << "   ";
        cout << setw(20) << right << get_min() << "C" << setw(18) << left << "    "<< get_max() << "C" << setw(16) << right << "    " <<get_avg() << "C" << endl;
        break;

    default:
        cout << "Invalid size!!!\n";
        break;

    }
}
#endif // !CITY_CPP

