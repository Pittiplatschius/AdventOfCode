#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

long addedInvalidNumbers = 0;

//Diese funktion wurde nicht mit chatgpt gemacht
bool isInvalidID(const std::string& s) {
	const int n = s.size();
	for (int len = 1; len <= n / 2; len++) {
		if (n % len != 0) continue;
		std::string pattern = s.substr(0, len);
		bool match = true;
		for (int i = len; i < n; i += len) {
			if (s.substr(i, len) != pattern) {
				match = false;
				break;
			}
		}
		if (match) {
			cout << s << endl;
			return true;
		}
	}
	return false;
}

void cutRanges(const string& range) {
	stringstream rangeAsStream(range);
	string rangeSegment;
	vector<long> seglist;

	while (getline(rangeAsStream, rangeSegment, '-')) {
		seglist.push_back(stol(rangeSegment));
	}

	for (long i = seglist[0]; i <= seglist[1]; i++) {
		string intAsString = to_string(i);

		if (isInvalidID(intAsString)) {
			addedInvalidNumbers += i;
		}

		if (to_string(i).length() % 2 == 0) {

			const auto stringLength = intAsString.length();
			string subStringOne = intAsString.substr(0, stringLength / 2);
			string subStringTwo = intAsString.substr(stringLength / 2, stringLength);

			if (subStringOne == subStringTwo) {
				//addedInvalidNumbers = addedInvalidNumbers + i;
			}
		}
	}
}

int main()
{
	string file_path = "input.txt";
	ifstream MyReadFile(file_path);
	string line;
	vector<string> inputSeparated;

	while (getline(MyReadFile, line, ',')) {
		inputSeparated.push_back(line);
	}

	for (const auto& range : inputSeparated) {
		cutRanges(range);
	}

    cout << "----------SOLUTION: " << addedInvalidNumbers << "----------" << endl;

	MyReadFile.close();

	return 0;
}