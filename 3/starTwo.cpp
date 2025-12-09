#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string foundNumbers;
long solution = 0;

void findBiggestNumber(const string &inputString) {
  int number = 0;
  int cursorState = 0;
  int numbersNeeded = 12;
  string newString = inputString;

  while (foundNumbers.length() != 12) {
    if (newString.length() > numbersNeeded && numbersNeeded > 0) {
      for (int i = 0; i <= newString.length() - numbersNeeded; i++) {
        const int cursorInt = newString[i] - '0';

        if (cursorInt > number) {
          number = cursorInt;
          cursorState = i;
        }
      }

      foundNumbers += newString[cursorState];
      numbersNeeded--;
      newString = newString.erase(0, cursorState + 1);
      cursorState = 0;
      number = 0;

    } else {
      foundNumbers += newString;

      return;
    }
  }
}

int main()
{
    string inputText;

    ifstream ReadInputFile("input.txt");

    while (getline(ReadInputFile, inputText)) {

      if (!inputText.empty() && inputText.back() == '\r') {
        inputText.pop_back();
      }

      findBiggestNumber(inputText);
      solution += stol(foundNumbers);
      foundNumbers.clear();
    }

    cout << "Ergebnis: " << solution << endl;

    return 0;
}