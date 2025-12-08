#include <iostream>
using namespace std;
#include <fstream>

int countWithExtraZero = 0;

int countUp (int dial, int rotation) {
	for (int i = 1; i <= rotation; i++) {
		if (dial == 0) {
            countWithExtraZero++;
        }
        
        dial++;
		if (dial == 100) {
			dial = 0;
		}
	}
	return dial;
}

int countDown (int dial, int rotation) {
	for (int i = 1; i <= rotation; i++) {
		if (dial == 0) {
            countWithExtraZero++;
			dial = 100;
		}
		dial--;
	}

	return dial;
}

int main()
{
	int rotation;
	int dial = 50;

	string file_path = "input.txt";
	ifstream file(file_path);
	string line;

	while (getline(file, line)) {

		if (line[0] == 'L') {
			rotation = stoi(line.erase(0,1));
			dial = countDown(dial, rotation);
		} else if (line[0] == 'R') {
			rotation = stoi(line.erase(0,1));
			dial = countUp(dial, rotation);
		}
		cout << "new Dial: " << dial << endl;
	}

	cout << countWithExtraZero << endl;

	return 0;
}