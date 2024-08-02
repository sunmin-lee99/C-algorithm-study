// 1012
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N, K, result;
int ground[50][50];
bool visited[50][50];
int x, y;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int> > q;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin>>T;

    for (int i=0;i<T;i++)
    {
        result = 0;
        cin>>M>>N>>K;

        for (int Y=0;Y<N;Y++)
        {
            fill(ground[Y], ground[Y]+M, 0);
            fill(visited[Y], visited[Y]+M, false);
        }

        for (int j=0;j<K;j++)
        {
            cin>>x>>y;
            ground[y][x] = 1;
        }
        
        for (int Y=0;Y<N;Y++)
        {
            for (int X=0;X<M;X++)
            {
                if (ground[Y][X]==1 && visited[Y][X]==false)
                {
                    result++;
                    q.push(make_pair(X, Y));
                    visited[Y][X] = true;
                    while (!q.empty())
                    {
                        x = q.front().first;
                        y = q.front().second;
                        q.pop();
                        for (int dir=0;dir<4;dir++)
                        {
                            int cur_x = x + dx[dir];
                            int cur_y = y + dy[dir];
                            if (cur_x>=0 && cur_x<M && cur_y>=0 && cur_y<N)
                            {
                                if (ground[cur_y][cur_x]==1 && visited[cur_y][cur_x]==false)
                                {
                                    q.push(make_pair(cur_x, cur_y));
                                    visited[cur_y][cur_x] = true;
                                }   
                            }
                        }
                    }
                }
            }
        }
        cout<<result<<"\n";
    }
    
    return 0;
}