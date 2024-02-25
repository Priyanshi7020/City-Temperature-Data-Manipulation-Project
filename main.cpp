// MAIN.CPP

#include "City.h"
#include "Capital.h"
#include "Non_capital.h"
#include "Menu.h"
#include <vector>
#include <sstream>
#include<iostream>
#include<string>
#include <iomanip>
#include<fstream>
using namespace std;

// Function to parse CSV line into pair of string and vector of doubles
pair<string, vector<double>> parseCSVLineToPair(const string& line) {
    stringstream ss(line);
    string cityName;
    getline(ss, cityName, ',');
    vector<double> temperatures;
    string temp;
    while (getline(ss, temp, ',')) {
        if (!temp.empty()) {
            try {
                temperatures.push_back(stod(temp));
            }
            catch (const std::invalid_argument& e) {
                cerr << "Error parsing temperature data: " << e.what() << endl;
                throw;  // Re-throw the exception after displaying the error
            }
        }
    }
    return make_pair(cityName, temperatures);
}



int main() {

    vector<pair<string, vector<double>>> cityTemperatureData;

    // Open CSV file

    ifstream file("E:/VS Projets/MSVS/example.csv");

    if (!file.is_open()) {

        cerr << "Error: Unable to open file.\n";

        return 1;

    }



    // Read data from CSV file
    string line;
    while (getline(file, line)) {
        try {
            cityTemperatureData.push_back(parseCSVLineToPair(line));
        }
        catch (const std::exception& e) {
            cerr << "Error reading CSV line: " << e.what() << endl;
            // Skip the current line and continue with the next one
            continue;
        }
    }
    file.close();

    vector<City*> cities(cityTemperatureData.size());

    for (int i = 0; i < cityTemperatureData.size(); i++) {
        try {
            if (cityTemperatureData[i].second.size() == total_samples * non_capital_size) {
                cities[i] = new Non_capital(cityTemperatureData[i].first);
                cities[i]->accept(cityTemperatureData[i].second);
            }
            else if (cityTemperatureData[i].second.size() == total_samples * capital_size) {
                cities[i] = new Capital(cityTemperatureData[i].first);
                cities[i]->accept(cityTemperatureData[i].second);
            }
            else {
                cerr << "Invalid data format for city: " << cityTemperatureData[i].first << endl;
                // Handle the error as needed
                // Skip creating this city and move to the next one
                continue;
            }
        }
        catch (const std::exception& e) {
            cerr << "Error creating city: " << e.what() << endl;
            // Handle the error as needed
            // Skip creating this city and move to the next one
            continue;
        }
    }

    // Menu interaction
    try {
        Menu m;
        m.menu_case(cities);
    }
    catch (const std::exception& e) {
        cerr << "Error in menu interaction: " << e.what() << endl;
    }

    // for memory cleanup
    for (City* city : cities) {
        delete city;
    }
}
