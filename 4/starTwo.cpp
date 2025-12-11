#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int vecRows = 0;
int accessableRolls = 0;
int totalOfRemovedRolls = 0;
bool accessableRollsThere = true;

vector<vector<char>> rollShelfVec;
vector<vector<char>> rollShelfVecCopy;

void printRollShelfVec () {
  for (int i = 0; i < rollShelfVec.size(); i++) {
    for (int j = 0; j < rollShelfVec[i].size(); j++) {
      cout << rollShelfVec.at(i).at(j);
    }
    cout << endl;
  }
}

void printRollShelfVecCopy () {
  for (int i = 0; i < rollShelfVecCopy.size(); i++) {
    for (int j = 0; j < rollShelfVecCopy[i].size(); j++) {
      cout << rollShelfVecCopy.at(i).at(j);
    }
    cout << endl;
  }
}

void fillRollShelfVec(const string& inputLine) {
  rollShelfVec.push_back(vector<char>());

  for (int i = 0; i < inputLine.length(); i++) {
    rollShelfVec.at(vecRows).push_back(inputLine[i]);
  }

  vecRows++;
}

int countAdjacentRolls (int& i, int& j) {
  int adjacentRolls = 0;

  for (int xAchse = i - 1; xAchse < (i + 2); xAchse++) {
    for (int yAchse = j - 1; yAchse < (j + 2); yAchse++) {
      if (xAchse < 0 || yAchse < 0) {
        continue;
      }

      if (xAchse >= rollShelfVec.size() || yAchse >= rollShelfVec.at(j).size()) {
        continue;
      }

      if (xAchse == i && yAchse == j) {
        continue;
      }

      if (rollShelfVec.at(xAchse).at(yAchse) == '@') {
        adjacentRolls++;
      }
    }
  }

  return adjacentRolls;
}

void countAccessableRolls() {
  for (int i = 0; i < rollShelfVec.size(); i++) {
    for (int j = 0; j < rollShelfVec.at(i).size(); j++) {
      int adjacent = 0;

      if (rollShelfVec.at(i).at(j) == '@') {
        adjacent = countAdjacentRolls(i, j);
      } else {
        continue;
      }

      if (adjacent < 4) {
        rollShelfVecCopy.at(i).at(j) = 'x';
        accessableRolls++;
      }
    }
  }

  if (accessableRolls == 0) {
    accessableRollsThere = false;
  }
}

void removeRollsOfPaper() {
  int removedRolls = 0;

  for (int i = 0; i < rollShelfVecCopy.size(); i++) {
    for (int j = 0; j < rollShelfVecCopy.at(i).size(); j++) {

      if (rollShelfVecCopy.at(i).at(j) == 'x') {
        rollShelfVecCopy.at(i).at(j) = '.';
        removedRolls++;
      }
    }
  }

  accessableRolls = 0;
  totalOfRemovedRolls += removedRolls;
  rollShelfVec = rollShelfVecCopy;
}

int main()
{
  string inputLine;

  ifstream ReadInputFile("input.txt");

  while (getline(ReadInputFile, inputLine)) {

    if (!inputLine.empty() && inputLine.back() == '\r') {
      inputLine.pop_back();
    }

    fillRollShelfVec(inputLine);
  }
  ReadInputFile.close();
  rollShelfVecCopy = rollShelfVec;

  printRollShelfVec();

  while (accessableRollsThere == true) {
    cout << endl;
    countAccessableRolls();
    cout << "Remove " << accessableRolls << " rolls of paper: " << endl;
    rollShelfVec = rollShelfVecCopy;
    printRollShelfVec();
    removeRollsOfPaper();
  }

  cout << "-----------Ergebnis: " << totalOfRemovedRolls << "-----------" << endl;

  return 0;
}