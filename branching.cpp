#include <iostream>
#include <cmath>
using namespace std;



int task1 () {
    int num;
    cout << "Input int number:\n";
    cin >> num;

    if (num % 2 == 0) {
        cout << num << " is even\n";
    }
    else {
        cout << num << " is odd\n";
    }

    if (num % 3 == 0) {
        cout << num << " is divide by three\n";
    }
    if (num % 6 == 0) {
        cout << num << " is divide by six\n";
    }
    return 0;
}

int task2 () {
    double x;
    cout << "Input X:\n";
    cin >> x;

    if (x < 1) {
        cout << "Y = " << pow(5*x +9, 1/3);
    }
    else if (x >= 1 && x <= 4) {
        cout << "Y = " <<  pow(x, 2) / 6 + pow(exp(-x), -x);
    }
    else {
        cout << "Y = " << cos(3 * pow(x, 3) + 8);
    }
    return 0;
}

int main () {
    task1();
    task2();
    return 0;
}