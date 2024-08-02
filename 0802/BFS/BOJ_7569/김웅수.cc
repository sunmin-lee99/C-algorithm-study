#include <iostream>
#include <queue>
using namespace std;

int M, N, H;
int box[100][100][100];
int dist[100][100][100];
queue<pair<pair<int, int >, int > > q; // z, y, x
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N >> H;

    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < M; k++)
            {
                cin >> box[i][j][k];
                if(box[i][j][k] == 1)
                {
                    q.push(make_pair(make_pair(i, j), k));
                    dist[i][j][k] = 1;
                }
            }
        }
    }

    while(!q.empty())
    {
        int Z = q.front().first.first;
        int Y = q.front().first.second;
        int X = q.front().second;
        q.pop();

        for(int i = 0; i < 6; i++)
        {
            int z = Z + dz[i];
            int y = Y + dy[i];
            int x = X + dx[i];

            if(z >= 0 && z < H && y >= 0 && y < N && x >= 0 && x < M)
            {
                if(box[z][y][x] == 0 && dist[z][y][x] == 0)
                {
                    q.push(make_pair(make_pair(z, y), x));
                    dist[z][y][x] = dist[Z][Y][X] + 1;
                    box[z][y][x] = 1;  // 익힌 토마토를 표시
                }
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < M; k++)
            {
                if(box[i][j][k] == 0)
                {
                    cout << -1 << "\n";
                    return 0;
                }
                if(dist[i][j][k] > ans)
                {
                    ans = dist[i][j][k];
                }
            }
        }
    }

    cout << ans - 1 << "\n";

    return 0;
}
