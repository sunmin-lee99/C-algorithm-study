#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	string str;
	vector<int> vec;
	int numbers[10] = {0,};
	int sixornine = 0;

	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		vec.push_back(str[i] - '0');
	}
	
	int answer = -1;

	for (auto i : vec) {
		if (i == 6) {
			if (numbers[6] > numbers[9])
				numbers[9]++;
			else
				numbers[6]++;
		}
		else if(i == 9) {
			if (numbers[6] < numbers[9])
				numbers[6]++;
			else
				numbers[9]++;
		}
		else {
			numbers[i]++;
		}
	}

	for (int i = 0; i < 10; i++) {
		if (answer < numbers[i]) {
			answer = numbers[i];
		}
	}

	cout << answer;
}
