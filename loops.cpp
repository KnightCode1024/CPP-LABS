#include <iostream>
#include <cmath>
#include "input_validation.h"

using namespace std;

float factorial(int n) {
    double cnt = 1.0;
    for (int i = 1; i <= n; i++) {
        cnt *= i;
    }
    return cnt;
}

int task1 () {
    cout << "Task 1\n";

    string num = getValidNumberString("Input number: \n");

    int sum = 0;
    int product = 1;

    for (int i = 0; i < num.size(); ++i) {
        int intChar = num[i] - '0';
        product *= intChar;
        sum += intChar;
    }

    cout << "Sum = " << sum << ";\n" << "Product = " << product << "\n\n";
    return 0;
}
int task2 () {
    cout << "Task 2\n";

    double x = getValidInput<double>("Input x:\n");
    int n = getValidInt("Input n (n > 0):\n", true);

    double res = 1.0;

    for (int i = 2; i <= n; i++) {
        res += pow(x, i) / factorial(i);
    }

    cout << "res = " << res << "\n\n";
    return 0;
}

int task3 () {
    cout << "Task 3\n";

    int A = getValidInt("Input A (positive int):\n", true);
    int B = getValidInt("Input B (positive int):\n", true);

    int originalA = A, originalB = B;

    while ( B != 0) {
        int tmp = B;
        B = A % B;
        A = tmp;
    }

    cout << "NOD(" << originalA << ", " << originalB << ") = " << A << "\n\n";
    return 0;
}

int main() {
    task1();
    task2();
    task3();
    return 0;
}