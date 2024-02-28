#ifndef MENU_CPP

#define MENU_CPP



#include "Menu.h"
#include "City.h"
#include "Capital.h"
#include "Non_capital.h"
#include "Converter.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string>
#include <typeinfo>
#include <stdexcept>
#include <limits> // For numeric_limits

using namespace std;

Menu::Menu() { choice = 0; }    /*choice = 5;*/

void Menu::display_menu()

{

    cout << "!!!--------------------MENU------------------!!!\n";
    cout << endl;
    cout << "1. Display temperature of all cities\n";
    cout << "2. Sort temperature \n";
    cout << "3. Search temperature values for a city\n";
    cout << "4. Delete record of a particular city and display\n";
    cout << "5. Convert Temperature unit from C to other unit\n";
    cout << "6. Exit\n";

}



void Menu::accept_choice()
{
    cout << "Enter choice (1/2/3/4) : ";
    int choice2;
    cin >> choice2;
    choice = choice2;
}


void Menu::search_choices(vector<City*> cities) {
    int choice2;
    cout << "1. Search by city name\n";
    cout << "2. Search by state name(Only for Capital cities)\n";
    cout << "Enter your choice : ";
    cin >> choice2;
    cout << "Inside search_choices()\n";
    if (cin.fail()) {
        cin.clear(); // clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        cout << "!!!------Invalid input! Please enter a valid integer------!!!\n\n";
        return;
    }

    // Input validation for valid choice range
    if (choice2 < 1 || choice2 > 2) {
        cout << "!!!------Invalid choice! Please enter a number between 1 and 2------!!!\n\n";
        return;
    }

    // Process user's choice
    switch (choice2) {
    case 1:
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character
        string city_name;
        cout << "Enter city name: ";
        getline(cin, city_name);
        co.search_city(cities, city_name);
        break;
    }
    case 2:
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character
        string state_name = "";
        cout << "Enter state name: ";
        getline(cin, state_name);
        co.search_state(cities, state_name);
        break;
    }
    default:
        cout << "!!!--------Invalid input--------!!!\n";
        break;
    }

}

void Menu::convert_choices(vector<City*> cities) {
    int choice2;
    cout << "1. convert from C to K\n";
    cout << "2. convert from C to F\n";
    cout << "Enter your choice : ";
    cin >> choice2;
    if (cin.fail()) {
        cin.clear(); // clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        cout << "!!!------Invalid input! Please enter a valid integer------!!!\n\n";
        return;
    }

    // Input validation for valid choice range
    if (choice2 < 1 || choice2 > 2) {
        cout << "!!!------Invalid choice! Please enter a number between 1 and 2------!!!\n\n";
        return;
    }

    // Process user's choice
    switch (choice2) {
    case 1:
    {
        co.convert(cities, 'K');
        break;
    }
    case 2:
    {
        co.convert(cities, 'F');
        break;
    }
    default:
        cout << "!!!--------Invalid input--------!!!\n";
        break;
    }
}

void Menu::menu_case(vector<City*> cities)
{
    bool check = 1;
    co.set_cities(cities);
    do
    {
        this->display_menu();

        int choice2;
        cout << "Enter choice from the MENU: ";
        cin >> choice2;
        try {
            // Input validation for integer input
            if (cin.fail()) {
                throw runtime_error("Invalid input! Please enter a valid integer.");
            }

            // Input validation for valid choice range
            if (choice2 < 1 || choice2 > 6) {
                throw out_of_range("Invalid choice! Please enter a number between 1 and 6.");
            }

            // Input validation for integer input
            if (cin.fail()) {
                cin.clear(); // clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
                cout << "!!!------Invalid input! Please enter a valid integer------!!!\n\n";
                continue;
            }

            // Input validation for valid choice range
            if (choice2 < 1 || choice2 > 6) {
                cout << "!!!------Invalid choice! Please enter a number between 1 and 6------!!!\n\n";
                continue;
            }
            cout << endl;
            switch (choice2)
            {
            case 1:
            {
                co.display_cities(cities);
                break;
            }

            case 2:
            {
                sort_choices(cities);
                break;
            }

            case 3:
            {
                search_choices(cities);
                break;
            }

            case 4:
            {
                string city_name1 = "";
                cout << "Enter the city name want to skip from the display : ";
                cin >> city_name1;
                co.delete_city(cities, city_name1);
                break;
            }
            case 5:
            {
                convert_choices(cities);
                break;
            }
            case 6:
            {
                check = 0;
                break;
            }
            }

            cout << endl;
        }
        catch (const exception& e) {
            cout << "Exception: " << e.what() << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    } while (check);

}


void Menu::sort_choices(vector<City*> cities)
{
    int choice1;
    cout << "1. sort by maximum temperature.\n";
    cout << "2. sort by minimum temperature.\n";
    cout << "3. sort by average temperature.\n";
    cout << "Enter your choice : ";
    cin >> choice1;
    try {
        // Input validation for integer input
        if (cin.fail()) {
            throw runtime_error("Invalid input! Please enter a valid integer.");
        }

        // Input validation for valid choice range
        if (choice1 < 1 || choice1 > 3) {
            throw out_of_range("Invalid choice! Please enter a number between 1 and 3.");
        }

        // Process user's choice
        switch (choice1)
        {
        case 1:
            co.sort_cities(cities, choice1);
            break;

        case 2:
            co.sort_cities(cities, choice1);
            break;
        case 3:
        {
            co.sort_cities(cities, choice1);
            break;
        }
        default:
            cout << "!!!--------Invalid input--------!!!\n";
            break;
        }
    }
    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }
}

#endif
