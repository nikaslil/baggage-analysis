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
        cout << "Прочитано: " << name << " - " << temp.itemCount 
             << " вещей, " << temp.totalWeight << " кг" << endl;
    }
    
    file.close();
    return baggageList;
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
