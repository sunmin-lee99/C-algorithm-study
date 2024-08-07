#include <iostream>

using namespace std;

char w1[8];
char w2[8];
char w3[8];
char w4[8];

void clockmove(char *w) {
	char tmp;
	tmp = w[0];
	w[0] = w[7];
	w[7] = w[6];
	w[6] = w[5];
	w[5] = w[4];
	w[4] = w[3];
	w[3] = w[2];
	w[2] = w[1];
	w[1] = tmp;
}

void reversclockmove(char* w) {
	char tmp;
	tmp = w[0];
	w[0] = w[1];
	w[1] = w[2];
	w[2] = w[3];
	w[3] = w[4];
	w[4] = w[5];
	w[5] = w[6];
	w[6] = w[7];
	w[7] = tmp;
}

int main() {
	string tmp;
	cin >> tmp;
	for (int j = 0; j < 8; j++)
		w1[j] = tmp[j];
	cin >> tmp;
	for (int j = 0; j < 8; j++)
		w2[j] = tmp[j];
	cin >> tmp;
	for (int j = 0; j < 8; j++)
		w3[j] = tmp[j];
	cin >> tmp;
	for (int j = 0; j < 8; j++)
		w4[j] = tmp[j];

	int n, number, dir;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> number >> dir;
		if (dir == 1) {
			if (number == 1) {
				if (w1[2] != w2[6]) {
					if (w2[2] != w3[6]) {
						if (w3[2] != w4[6]) {
							clockmove(w1);
							reversclockmove(w2);
							clockmove(w3);
							reversclockmove(w4);
						}
						else {
							clockmove(w1);
							reversclockmove(w2);
							clockmove(w3);
						}
					}
					else {
						clockmove(w1);
						reversclockmove(w2);
					}
				}
				else
					clockmove(w1);
			}
			else if (number == 2) {
				if (w2[6] != w1[2]) {
					reversclockmove(w1);
				}
				if (w2[2] != w3[6]) {
					if (w3[2] != w4[6]) {
						clockmove(w2);
						reversclockmove(w3);
						clockmove(w4);
					}
					else {
						clockmove(w2);
						reversclockmove(w3);
					}
				}
				else
					clockmove(w2);
			}
			else if (number == 3) {
				if (w3[2] != w4[6]) {
					reversclockmove(w4);
				}
				if (w3[6] != w2[2]) {
					if (w2[6] != w1[2]) {
						clockmove(w3);
						reversclockmove(w2);
						clockmove(w1);
					}
					else {
						clockmove(w3);
						reversclockmove(w2);
					}
				}
				else
					clockmove(w3);
			}
			else if (number == 4) {
				if (w4[6] != w3[2]) {
					if (w3[6] != w2[2]) {
						if (w2[6] != w1[2]) {
							clockmove(w4);
							reversclockmove(w3);
							clockmove(w2);
							reversclockmove(w1);
						}
						else {
							clockmove(w4);
							reversclockmove(w3);
							clockmove(w2);
						}
					}
					else {
						clockmove(w4);
						reversclockmove(w3);
					}
				}
				else {
					clockmove(w4);
				}
			}
		}
		else {
			if (number == 1) {
				if (w1[2] != w2[6]) {
					if (w2[2] != w3[6]) {
						if (w3[2] != w4[6]) {
							reversclockmove(w1);
							clockmove(w2);
							reversclockmove(w3);
							clockmove(w4);
						}
						else {
							reversclockmove(w1);
							clockmove(w2);
							reversclockmove(w3);
						}
					}
					else {
						reversclockmove(w1);
						clockmove(w2);
					}
				}
				else
					reversclockmove(w1);
			}
			else if (number == 2) {
				if (w2[6] != w1[2]) {
					clockmove(w1);
				}
				if (w2[2] != w3[6]) {
					if (w3[2] != w4[6]) {
						reversclockmove(w2);
						clockmove(w3);
						reversclockmove(w4);
					}
					else {
						reversclockmove(w2);
						clockmove(w3);
					}
				}
				else
					reversclockmove(w2);
			}
			else if (number == 3) {
				if (w3[2] != w4[6]) {
					clockmove(w4);
				}
				if (w3[6] != w2[2]) {
					if (w2[6] != w1[2]) {
						reversclockmove(w3);
						clockmove(w2);
						reversclockmove(w1);
					}
					else {
						reversclockmove(w3);
						clockmove(w2);
					}
				}
				else
					reversclockmove(w3);
			}
			else if (number == 4) {
				if (w4[6] != w3[2]) {
					if (w3[6] != w2[2]) {
						if (w2[6] != w1[2]) {
							reversclockmove(w4);
							clockmove(w3);
							reversclockmove(w2);
							clockmove(w1);
						}
						else {
							reversclockmove(w4);
							clockmove(w3);
							reversclockmove(w2);
						}
					}
					else {
						reversclockmove(w4);
						clockmove(w3);
					}
				}
				else {
					reversclockmove(w4);
				}
			}
		}
	}
	int answer = 0;
	if (w1[0] == '1')
		answer += 1;
	if (w2[0] == '1')
		answer += 2;
	if (w3[0] == '1')
		answer += 4;
	if (w4[0] == '1')
		answer += 8;

	cout << answer << '\n';
}
