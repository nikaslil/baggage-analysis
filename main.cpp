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

void displayBaggageTable(const vector<Baggage>& baggageList) {
    cout << "\n--- ТАБЛИЦА БАГАЖА ПАССАЖИРОВ ---" << endl;
    cout << setw(10) << "Пассажир" << setw(15) << "Кол-во вещей" << setw(15) << "Вес (кг)" << endl;
    cout << "----------------------------------------" << endl;
    
    for (int i = 0; i < baggageList.size(); i++) {
        cout << setw(10) << i + 1 
             << setw(15) << baggageList[i].itemCount 
             << setw(15) << baggageList[i].totalWeight << endl;
    }
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
    
  cout << fixed << setprecision(2);
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
            cout << " НАЙДЕНО: Пассажир #" << (i + 1) 
                 << " - 1 вещь, вес: " << baggageList[i].totalWeight << " кг" << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << " Пассажиров с одной вещью массой менее 6 кг не найдено." << endl;
    }
}
int main() {
    cout << "==========================================" << endl;
    cout << "  ПРОГРАММА ДЛЯ АНАЛИЗА БАГАЖА ПАССАЖИРОВ" << endl;
    cout << "==========================================" << endl;

    vector<Baggage> baggageList = baggageInformation("bagaj.txt");
    
    if (baggageList.empty()) {
        cout << "Файл пуст или не найден!" << endl;
        cout << "Убедитесь, что файл 'bagaj.txt' находится в той же папке!" << endl;
        return 1;
    }
    
    cout << "Успешно загружено данных о " << baggageList.size() << " пассажирах" << endl;
    
    displayBaggageTable(baggageList);
    solveTaskA(baggageList);
    solveTaskB(baggageList);

    cout << "\n==========================================" << endl;
    cout << "         ПРОГРАММА ЗАВЕРШИЛА РАБОТУ" << endl;
    cout << "==========================================" << endl;
    return 0;
}
}
