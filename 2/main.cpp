#include <iostream>
#include <vector>
using namespace std;
#include <fstream>
#include <sstream>

void cutRanges(string newRange) {
	stringstream test(newRange);
	string rangeSegment;
	vector<long> seglist;

	cout << "-----------------------" << endl;

	while (getline(test, rangeSegment, '-')) {
		cout << rangeSegment << endl;
		seglist.push_back(stol(rangeSegment));
	}
}

int main()
{
	string file_path = "input.txt";
	ifstream file(file_path);
	string line;
	vector<string> inputSeparated;
	
	long solution = 0;

	while (getline(file, line, ',')) {
		inputSeparated.push_back(line);
	}

	for (auto range : inputSeparated) {
		cutRanges(range);
	}

    cout << "----------SOLUTION: " << solution << "----------" << endl;

	return 0;
}