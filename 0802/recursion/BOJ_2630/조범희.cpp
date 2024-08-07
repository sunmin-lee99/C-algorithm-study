#include <iostream>
#define MAX 129
using namespace std;

int N;
int paper[MAX][MAX];
int blue = 0;
int white = 0;
void recussion(int sx, int sy, int ex, int ey, int n) {
	bool check = false;
	
	int tmp = paper[sx][sy];

	for (int i = sx; i < ex; i++) {
		for (int j = sy; j < ey; j++) {
			if (paper[i][j] != tmp) {
				check = true;
			}
		}
	}

	if (check) {
		//cout << 1 << endl;
		recussion(sx, sy, sx + n / 2, sy + n / 2, n / 2);
		//cout << 2 << endl;
		recussion(sx + n / 2, sy, ex, ey - n / 2, n / 2); // 0 0 8 8 -> 4 0 8 4 -> 2 0 8 2
		//cout << 3 << endl;
		recussion(sx, sy + n / 2, ex - n / 2, ey, n / 2);
		//cout << 4 << endl;
		recussion(sx + n / 2, sy + n / 2, ex, ey, n / 2);
	}
	else {
		if (paper[sx][sy] == 1) blue++;
		else white++;
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}

	recussion(0, 0, N, N, N);
	cout << white << '\n';
	cout << blue << '\n';
}
