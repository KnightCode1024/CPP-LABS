#include <iostream>
#include <ctime>
#include <cstdlib>
#include <clocale>
#include "input_validation.h"
using namespace std;

int generateNumber() {
    int minVal = 0;
    int maxVal = 100;
    int number = minVal + rand() % (maxVal - minVal + 1);
    return number;
}

double generateDoubleNumber() {
    int minVal = 0;
    int maxVal = 100;
    double number = minVal + (double)rand() / RAND_MAX * (maxVal - minVal);
    return number;
}

int* generateArray(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = generateNumber();
    }
    return arr;
}

double* generateDoubleArray(int n) {
    double* arr = new double[n];
    for (int i = 0; i < n; i++) {
        arr[i] = generateDoubleNumber();
    }
    return arr;
}

void showArray(int* arr, int n, string& message) {
    cout << message;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void showDoubleArray(double* arr, int n, string& message) {
    cout << message;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

double srZnach(int* arr, int k, int l) {
    double sum = 0;
    int count = 0;
    for (int i = k - 1; i <= l - 1; i++) {
        sum += arr[i];
        count++;
    }
    return sum / count;
}

int task1() {
    cout << "\n=== Задание 1 ===" << endl;
    
    int n = getValidInt("Введите размер массива N: ", true);
    int* arr = generateArray(n);
    showArray(arr, n, "Сгенерированный массив: ");
    
    int k, l;
    do {
        k = getValidInt("Введите K (от 1 до N): ", true);
        l = getValidInt("Введите L (от K до N): ", true);
        
        if (k > l) {
            cout << "Ошибка! K должно быть <= L. Повторите ввод.\n";
        }
        if (l > n) {
            cout << "Ошибка! L должно быть <= N. Повторите ввод.\n";
        }
    } while (k > l || l > n);
    
    double average = srZnach(arr, k, l);
    cout << "Среднее арифметическое элементов с " << k << " по " << l << ": " << average << endl;
    
    delete[] arr;
    return 0;
}

int task2() {
    cout << "\n=== Задание 2 ===" << endl;
    
    int n = getValidInt("Введите размер массива N: ", true);
    double* arr = generateDoubleArray(n);
    showDoubleArray(arr, n, "Сгенерированный массив: ");

    int lastNegativeIndex = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            lastNegativeIndex = i;
        }
    }
    
    if (lastNegativeIndex == -1) {
        cout << "В массиве нет отрицательных элементов." << endl;
    } else if (lastNegativeIndex == n - 1) {
        cout << "Последний отрицательный элемент находится в конце массива. После него нет элементов." << endl;
    } else {
        int sum = 0;
        cout << "Целые части элементов после последнего отрицательного: ";
        for (int i = lastNegativeIndex + 1; i < n; i++) {
            int intPart = static_cast<int>(arr[i]);
            cout << intPart << " ";
            sum += intPart;
        }
        cout << "\nСумма целых частей: " << sum << endl;
    }
    
    delete[] arr;
    return 0;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    srand(time(nullptr));
    task1();
    task2();
    return 0;
}