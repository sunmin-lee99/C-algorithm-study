#include <iostream>
#include <queue>

using namespace std;

int N;
char map[100][100];
bool visited[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int startY, int startX) {
    queue<pair<int, int> > q;
    q.push(make_pair(startY, startX));
    visited[startY][startX] = true;
    char currentColor = map[startY][startX];

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];

            if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
                if (!visited[ny][nx] && map[ny][nx] == currentColor) {
                    q.push(make_pair(ny, nx));
                    visited[ny][nx] = true;
                }
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    int ans1 = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                bfs(i, j);
                ans1++;
            }
        }
    }

    // 색맹 처리를 위해 'G'를 'R'로 변경
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 'G') {
                map[i][j] = 'R';
            }
        }
    }

    // 방문 배열 초기화
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }

    int ans2 = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                bfs(i, j);
                ans2++;
            }
        }
    }

    cout << ans1 << " " << ans2 << "\n";

    return 0;
}
