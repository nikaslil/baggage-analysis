#include <iostream>
#include "baggage.h"
#include <windows.h> 

using namespace std;

int main() {
    setRussianLocale();
    cout << "==========================================" << endl;
    cout << "  ПРОГРАММА ДЛЯ АНАЛИЗА БАГАЖА ПАССАЖИРОВ" << endl;
    cout << "==========================================" << endl;
    vector<Baggage> baggageList = readBaggageData("bagaj.txt");
    if (baggageList.empty()) {
        cout << "Файл пуст или не найден!" << endl;
        cout << "Убедитесь, что файл 'bagaj.txt' находится в той же папке!" << endl;
        return 1;
    }
    cout << "Успешно загружены данные о " << baggageList.size() << " пассажирах" << endl;
    displayBaggageTable(baggageList);
    solveTaskA(baggageList);
    solveTaskB(baggageList);

    cout << "\n==========================================" << endl;
    cout << "         ПРОГРАММА ЗАВЕРШИЛА РАБОТУ" << endl;
    cout << "==========================================" << endl;

    return 0;
}
