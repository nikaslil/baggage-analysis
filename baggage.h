#ifndef BAGGAGE_H
#define BAGGAGE_H

#include <vector>
#include <string>


using namespace std;

struct Baggage {
    int itemCount;
    double totalWeight;
};


vector<Baggage> readBaggageData(const string& filename);
double calculateAverageItems(const vector<Baggage>& baggageList);
void displayBaggageTable(const vector<Baggage>& baggageList);
void solveTaskA(const vector<Baggage>& baggageList);
void solveTaskB(const vector<Baggage>& baggageList);
void setRussianLocale();
#endif
