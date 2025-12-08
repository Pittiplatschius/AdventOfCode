#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

long addedInvalidNumbers = 0;

void cutRanges(string range) {
	stringstream rangeAsStream(range);
	string rangeSegment;
	vector<long> seglist;

	//cout << "-----------------------" << endl;

	while (getline(rangeAsStream, rangeSegment, '-')) {
		seglist.push_back(stol(rangeSegment));
	}

	for (long i = seglist[0]; i <= seglist[1]; i++) {
		
		if (to_string(i).length() % 2 == 0) {
			//cout << i << ": " << to_string(i).length() << endl;

			string intAsString = to_string(i);
			int stringLength = intAsString.length();
			string subStringOne = intAsString.substr(0, stringLength / 2);
			string subStringTwo = intAsString.substr(stringLength / 2, stringLength);

			//cout << subStringOne << " and " << subStringTwo << endl;

			if (subStringOne == subStringTwo) {
				addedInvalidNumbers = addedInvalidNumbers + i;
			}
		}

	}
	
}

int main()
{
	string file_path = "input.txt";
	ifstream file(file_path);
	string line;
	vector<string> inputSeparated;

	while (getline(file, line, ',')) {
		inputSeparated.push_back(line);
	}

	for (auto range : inputSeparated) {
		cutRanges(range);
	}

    cout << "----------SOLUTION: " << addedInvalidNumbers << "----------" << endl;

	return 0;
}