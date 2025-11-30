#include "baggage.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

void setRussianLocale() {
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 
    setlocale(LC_ALL, "Russian");
}


vector<Baggage> readBaggageData(const string& filename) {
    vector<Baggage> baggageList;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << filename << endl;
        return baggageList;
    }

    string name;
    Baggage temp;
    temp.itemCount = 0;
    temp.totalWeight = 0.0;

    while (file >> name >> temp.itemCount >> temp.totalWeight) {
        baggageList.push_back(temp);
    }

    file.close();
    return baggageList;
}


double calculateAverageItems(const vector<Baggage>& baggageList) {
    if (baggageList.empty()) return 0.0;

    int totalItems = 0;
    for (int i = 0; i < baggageList.size(); i++) {
        totalItems += baggageList[i].itemCount;
    }

    return static_cast<double>(totalItems) / baggageList.size();
}


void displayBaggageTable(const vector<Baggage>& baggageList) {
    cout << "\n--- ТАБЛИЦА БАГАЖА ПАССАЖИРОВ ---" << endl;
    cout << "Пассажир\tКол-во вещей\tВес (кг)" << endl;
    cout << "----------------------------------------" << endl;

    for (int i = 0; i < baggageList.size(); i++) {
        cout << i + 1 << "\t\t"
            << baggageList[i].itemCount << "\t\t"
            << baggageList[i].totalWeight << endl;
    }
}


void solveTaskA(const vector<Baggage>& baggageList) {
    cout << "\n--- РЕШЕНИЕ ЗАДАЧИ а) ---" << endl;

    int passengersWithMoreThan2Items = 0;
    for (int i = 0; i < baggageList.size(); i++) {
        if (baggageList[i].itemCount > 3) {
            passengersWithMoreThan2Items++;
        }
    }

    cout << "1. Число пассажиров с более чем 3 вещами: "
        << passengersWithMoreThan2Items << endl;

    double averageItems = calculateAverageItems(baggageList);
    int passengersAboveAverage = 0;

    for (int i = 0; i < baggageList.size(); i++) {
        if (baggageList[i].itemCount > averageItems) {
            passengersAboveAverage++;
        }
    }

    cout.precision(2);
    cout << "2. Среднее количество вещей: " << averageItems << endl;
    cout << "3. Число пассажиров с количеством вещей выше среднего: "
        << passengersAboveAverage << endl;
}


void solveTaskB(const vector<Baggage>& baggageList) {
    cout << "\n--- РЕШЕНИЕ ЗАДАЧИ б) ---" << endl;
    cout << "Поиск пассажира с одной вещью массой менее 6 кг:" << endl;

    bool found = false;

    for (int i = 0; i < baggageList.size(); i++) {
        if (baggageList[i].itemCount == 1 && baggageList[i].totalWeight < 6.0) {
            cout << "НАЙДЕНО: Пассажир #" << (i + 1)
                << " - 1 вещь, вес: " << baggageList[i].totalWeight << " кг" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Пассажиров с одной вещью массой менее 6 кг не найдено." << endl;
    }
}
