#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int totalJoltage = 0;

int calculateMaxJoltage(const string& joltageAsString) {
    char one = joltageAsString[0];
    int stateOfOne = 0;
    int calculatedJoltage = 0;

    for (int i = 1; i < joltageAsString.size() -1 ; i++) {

        if (one < joltageAsString[i]) {
            one = joltageAsString[i];
            stateOfOne = i;
        }
    }

    char two = joltageAsString[stateOfOne + 1];

    for (int i = stateOfOne + 1; i < joltageAsString.size(); i++) {

        if (two < joltageAsString[i]) {
            two = joltageAsString[i];
        }
    }

    string three;
    three += one;
    three += two;

    calculatedJoltage = stoi(three);

    //cout << "ergebnis: " << one << two << endl;
    //cout << "Ergebnis: " << three << endl;
    //cout << "Vergebnis: " << calculatedJoltage << endl;

    return calculatedJoltage;
}

int main() {

    const string file_path = "input.txt";
    ifstream file(file_path);
    string line;

    int result = 0;

    while (getline(file, line)) {
        result += calculateMaxJoltage(line);
    }

    cout << "----------SOLUTION: " << result << "----------" << endl;

    return 0;
}