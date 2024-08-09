#include<iostream>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string input;
	string optimal = "";
	cin >> input;

	for (int i = 0; i < input.size(); i++) { // 괄호 묶기
		if (input[i] == '-') {
			optimal.push_back('-');
			int result = 0;
			for (int j = i + 1; j < input.size(); j++) { // -가 나오면 다음 - 나올 때 까지 더함
				int tmp = 0;
				i++;
				bool check = false;
				if (input[j] != '+' && input[j] != '-') { // 숫자면
					tmp = input[j] - '0';
					for (int k = j + 1; k < input.size(); k++) {
						if (input[k] != '+' && input[k] != '-') {
							tmp = tmp * 10 + input[k] - '0';
							j++;
							i++;
						}
						else {
							j++;
							i++;
							break;
						}
					}
				}
				else if (input[j] == '-')
					break;
				result += tmp;
				
			}
			//cout << optimal << endl;
			//cout << result << endl;
			optimal += to_string(result);
		}
		else {
			optimal.push_back(input[i]);
		}
	}
	int answer = 0;
	char op = '-1';
	for (int i = 0; i < optimal.size(); i++) {
		int tmp = 0;
		if (optimal[i] != '+' && optimal[i] != '-') {
			tmp = optimal[i] - '0';
			for (int j = i + 1; j < optimal.size(); j++) {
				if (optimal[j] != '+' && optimal[j] != '-') {
					tmp = tmp * 10 + optimal[j] - '0';
					i++;
				}
				else {
					break;
				}
			}
			if (op == '+') answer += tmp;
			else if (op == '-') answer -= tmp;
			else answer += tmp;
		}
		else if (optimal[i] == '+') op = '+';
		else if (optimal[i] == '-') op = '-';


	}

	//cout << optimal << endl;
	cout << answer << '\n';
}
