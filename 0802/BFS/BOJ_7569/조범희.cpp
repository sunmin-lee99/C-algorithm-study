#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

const int MAX = 101;
int n, m, l;

int tomato[MAX][MAX][MAX];
int ans = 0;
bool visited[MAX][MAX][MAX];

queue<pair<pair<int, int>, pair<int,int>>> q;

int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,-1,1,0,0};
int dz[] = {0,0,0,0,1,-1};

bool range(int x, int y, int z){
    return x > -1 && x < m && y > -1 && y < n && z > -1 && z < l;
}

void bfs(){
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        ans = cnt;

        for(int i = 0; i < 6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if(range(nx, ny, nz) && !visited[nx][ny][nz] && tomato[nx][ny][nz] == 0){
                visited[nx][ny][nz] = true;
                tomato[nx][ny][nz] = 1;
                q.push({{nx, ny}, {nz, cnt + 1}});
            }
        }
    }

     for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < l; k++){
                if(!visited[i][j][k]){
                    cout << -1 << '\n';
                    return;
                }
            }
        }
    }

    cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    memset(tomato, false, sizeof tomato);

    cin >> n >> m >> l;
for(int k = 0; k < l; k++){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
                cin >> tomato[i][j][k];
                if(tomato[i][j][k] == 1){
                    q.push({{i,j}, {k, 0}});
                    visited[i][j][k] = true;
                }else if(tomato[i][j][k] == -1){
                    visited[i][j][k] = true;
                }

            }
        }
    }
    
    bfs();
}
