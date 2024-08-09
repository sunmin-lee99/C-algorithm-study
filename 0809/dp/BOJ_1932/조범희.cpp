#include<iostream>
#include<algorithm>
using namespace std;

int DP[501][501];

int main() {

	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i < j)
				continue;
			cin >> DP[i][j];
		}
	}

	for (int i = n - 2; i > -1; i--) {
		for (int j = n - 2; j > -1; j--) {
			if (i < j)
				continue;
			DP[i][j] = max(DP[i + 1][j + 1] + DP[i][j], DP[i + 1][j] + DP[i][j]);
		}
	}

	cout << DP[0][0] << endl;
}
