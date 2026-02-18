#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

#include <iostream>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

template<typename T>
T getValidInput(const string& prompt) {
    T value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cout << "Error! Invalid format. Please try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

inline int getValidInt(const string& prompt, bool positiveOnly = false) {
    while (true) {
        int value = getValidInput<int>(prompt);

        if (positiveOnly && value <= 0) {
            cout << "Error! Number must be positive. Please try again.\n";
            continue;
        }
        return value;
    }
}

inline double getValidDouble(const string& prompt, double min = -1e9, double max = 1e9) {
    while (true) {
        double value = getValidInput<double>(prompt);

        if (value < min || value > max) {
            cout << "Error! Number must be between " << min << " and " << max << ". Please try again.\n";
            continue;
        }
        return value;
    }
}

inline string getValidString(const string& prompt, bool allowEmpty = false) {
    string value;
    while (true) {
        cout << prompt;
        getline(cin, value);

        if (!allowEmpty && value.empty()) {
            cout << "Error! Input cannot be empty. Please try again.\n";
            continue;
        }
        return value;
    }
}

inline string getValidNumberString(const string& prompt) {
    string num;
    while (true) {
        cout << prompt;
        getline(cin, num);

        bool valid = !num.empty();
        for (char c : num) {
            if (!isdigit(c)) {
                valid = false;
                break;
            }
        }

        if (valid) {
            return num;
        }

        cout << "Error! Please enter only digits.\n";
    }
}
#endif