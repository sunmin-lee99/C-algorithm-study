#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

vector<int> commedline;
int dicemap[4][4] = { 0, };
int boad[MAX][MAX] = { 0, };

int n, m, r, c, commend;

void convert(int d) {
	if (d == 1) {	// east
		int tmp = dicemap[1][2];
		dicemap[1][2] = dicemap[3][1];
		dicemap[3][1] = dicemap[1][0];
		dicemap[1][0] = dicemap[1][1];
		dicemap[1][1] = tmp;
	}
	else if (d == 2) { // west
		int tmp = dicemap[1][2];
		dicemap[1][2] = dicemap[1][1];
		dicemap[1][1] = dicemap[1][0];
		dicemap[1][0] = dicemap[3][1];
		dicemap[3][1] = tmp;
	}
	else if (d == 3) { //north
		int tmp = dicemap[0][1];
		dicemap[0][1] = dicemap[3][1];
		dicemap[3][1] = dicemap[2][1];
		dicemap[2][1] = dicemap[1][1];
		dicemap[1][1] = tmp;
	}
	else if (d == 4) { // south
		int tmp = dicemap[0][1];
		dicemap[0][1] = dicemap[1][1];
		dicemap[1][1] = dicemap[2][1];
		dicemap[2][1] = dicemap[3][1];
		dicemap[3][1] = tmp;
	}
}

void dfs(int x, int y, int i, bool check) {
	if (i == commedline.size())
		return;
	if (check == true) {
		if (boad[x][y] == 0)
			boad[x][y] = dicemap[1][1];

		else {
			dicemap[1][1] = boad[x][y];
			boad[x][y] = 0;
		}
	}
	int nx = x;
	int ny = y;
	
	if (commedline[i] == 1) {
		ny++;
	}
	else if (commedline[i] == 2) { // west
		ny--;
	}
	else if (commedline[i] == 3) { // north
		nx--;
	}
	else { // south
		nx++;
	}

	if (nx < n && nx > -1 && ny < m && ny > -1) {
		convert(commedline[i]);
		cout << dicemap[3][1] << endl;
		dfs(nx, ny, i + 1, true);
	}
	else {
		dfs(x, y, i + 1, false);
	}
}

int main() {
	cin >> n >> m >> r >> c >> commend;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> boad[i][j];
		}
	}
	
	for (int i = 0; i < commend; i++) {
		int tmp;
		cin >> tmp;
		commedline.push_back(tmp);
	}
	dfs(r, c, 0, true);
}
