#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int totalJoltage = 0;

int calculateMaxJoltage(string& joltageAsString) {
    char one = joltageAsString[0];
    int stateOfCurser = 0;
    long calculatedJoltage = 0;
    string twelveDigitsJoltage;
    string three;
    int numberOfDigits = 0;

    //while (twelveDigitsJoltage.length() != 12) {}

    for (int i = 1; i < joltageAsString.size() - 12 ; i++) {
        if (one < joltageAsString[i]) {
            one = joltageAsString[i];
            stateOfCurser = i;
        }
    }

    three += one;
    numberOfDigits++;
    joltageAsString.erase(0, stateOfCurser + 1);
    cout << "gecuted: " << joltageAsString << endl;

    while (numberOfDigits != 12) {
        one = joltageAsString[0];
        if (joltageAsString.length() < 12 - numberOfDigits) {
            for (int i = 1; i < joltageAsString.size() - 12 ; i++) {
                if (one < joltageAsString[i]) {
                    one = joltageAsString[i];
                    stateOfCurser = i;
                }
            }

            three += one;
            numberOfDigits++;
            joltageAsString.erase(0, stateOfCurser + 1);
        } else {
            for (int i = 1; i < joltageAsString.size(); i++) {
                if (one < joltageAsString[i]) {
                    one = joltageAsString[i];
                    stateOfCurser = i;
                }
            }

            three += one;
            numberOfDigits++;
            //joltageAsString.erase(0, stateOfCurser + 1);
        }
    }

    calculatedJoltage = stol(three);

    //cout << "ergebnis: " << one << two << endl;
    //cout << "Ergebnis: " << three << endl;
    cout << "Eergebnis: " << calculatedJoltage << endl;

    return calculatedJoltage;
}

int main() {

    const string file_path = "test.txt";
    ifstream file(file_path);
    string line;

    unsigned long result = 0;

    while (getline(file, line)) {
        result += calculateMaxJoltage(line);
    }

    cout << "----------SOLUTION: " << result << "----------" << endl;

    return 0;
}