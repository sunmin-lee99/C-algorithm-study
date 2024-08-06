#include <iostream>
#include <queue>

#define MAX 51
using namespace std;

bool visited[MAX][MAX] = { false, };
int board[MAX][MAX];

int N, M, K;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
void bfs(int sx, int sy) {
	queue<pair<int, int>> q;

	q.push({ sx, sy });
	visited[sx][sy] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < N && nx > -1 && ny < M && ny > -1 && !visited[nx][ny] && board[nx][ny] == 1) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;

		for (int j = 0; j < N; j++) {
			for(int k = 0; k < M; k++){
				board[j][k] = 0;
				visited[j][k] = false;
			}
		}

		for (int k = 0; k < K; k++) {
			int a, b;
			cin >> a >> b;

			board[b][a] = 1;
		}
		int answer = 0;
		for (int k = 0; k < N; k++) {
			for (int j = 0; j < M; j++) {
				if (!visited[k][j] && board[k][j] == 1) {
					answer++;
					bfs(k, j);
				}
			}
		}

		cout << answer << '\n';
	}
}
