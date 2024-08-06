#include<iostream>
#include<vector>
#include<string>
#define MAX 100

using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1, -1 , 0 , 0};

int N;

char Grid[MAX][MAX] = { '0' ,};
char Grid2[MAX][MAX];
bool visited[MAX][MAX] = { false , };


void setGrid() {
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;		
		for (int j = 0; j < N; j++) {
			Grid[i][j] = str[j];
		}
	}
}
void setGrid2() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Grid[i][j] == 'B')
				Grid2[i][j] = Grid[i][j];
			else
				Grid2[i][j] = 'R';
		}
	}
}
void DFS(int low, int col, char here) {
	if (visited[low][col] == true)
		return;

	visited[low][col] = true;

	for (int i = 0; i < 4; i++) {
		int tlow = low + dx[i];
		int tcol = col + dy[i];

		if (tlow > -1 && tlow < N && tcol > -1 && tcol < N && Grid[tlow][tcol] == here) {
			DFS(tlow, tcol, here);
		}
	}
}void DFS2(int low, int col, char here) {
	if (visited[low][col] == true)
		return;

	visited[low][col] = true;

	for (int i = 0; i < 4; i++) {
		int tlow = low + dx[i];
		int tcol = col + dy[i];

		if (tlow > -1 && tlow < N && tcol > -1 && tcol < N && Grid2[tlow][tcol] == here) {
			DFS2(tlow, tcol, here);
		}
	}
}

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			visited[i][j] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int cnt = 0;
	int cnt2 = 0;

	cin >> N;

	setGrid();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == false) {
				DFS(i, j, Grid[i][j]);
				cnt++;
			}
		}
	}

	setGrid2();
	init();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == false) {
				DFS2(i, j, Grid2[i][j]);
				cnt2++;
			}
		}
	}
	cout << cnt << endl;
	cout << cnt2 << endl;
}
