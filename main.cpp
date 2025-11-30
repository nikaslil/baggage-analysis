#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


struct Baggage {
    int itemCount;      
    double totalWeight; 


vector<Baggage> baggageInformation(const string& filename) {
    vector<Baggage> baggageList;
    ifstream file(filename);
    
    if (!file.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << filename << endl;
        return baggageList;
    }
    
    string name; 
    Baggage temp;
    
    while (file >> name >> temp.itemCount >> temp.totalWeight) {
        baggageList.push_back(temp);
    }
    
    file.close();
    return baggageList;
}

double calculateAverageItems(const vector<Baggage>& baggageList) {
    if (baggageList.empty()) return 0.0;
    
    int totalItems = 0;
    for (const auto& baggage : baggageList) {
        totalItems += baggage.itemCount;
    }
    
    return static_cast<double>(totalItems) / baggageList.size();
}

void solveTaskA(const vector<Baggage>& baggageList) {
    cout << "\n--- РЕШЕНИЕ ЗАДАЧИ а) ---" << endl;

    int passengersWithMoreThan2Items = 0;
    for (const auto& baggage : baggageList) {
        if (baggage.itemCount > 2) {
            passengersWithMoreThan2Items++;
        }
    }
    
    cout << "1. Число пассажиров с более чем 2 вещами: " 
         << passengersWithMoreThan2Items << endl;
    
    
    double averageItems = calculateAverageItems(baggageList);
    int passengersAboveAverage = 0;
    
    for (const auto& baggage : baggageList) {
        if (baggage.itemCount > averageItems) {
            passengersAboveAverage++;
        }
    }
    
    cout << "2. Среднее количество вещей: " << averageItems << endl;
    cout << "3. Число пассажиров с количеством вещей выше среднего: " 
         << passengersAboveAverage << endl;
}

int main() {
    cout << "=== ПРОГРАММА ДЛЯ АНАЛИЗА БАГАЖА ПАССАЖИРОВ ===" << endl;
    cout << "Этап 1: Чтение данных из файла" << endl;
    
    
    vector<Baggage> baggageList = baggageInformation("bagaj.txt");
    
    if (baggageList.empty()) {
        cout << "Файл пуст или не найден!" << endl;
        return 1;
    }
    
    cout << "Успешно загружено данных о " << baggageList.size() << " пассажирах" << endl;
    
    return 0;
}
