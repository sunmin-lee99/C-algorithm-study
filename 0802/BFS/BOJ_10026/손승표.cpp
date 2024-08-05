#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int boardSize;
char board[100][100];
bool visited[100][100];

typedef pair<int,int> Coordinate;

void bfs(Coordinate start, vector<char> key)
{
    queue<Coordinate> place2go;
    place2go.push(start);
    visited[start.first][start.second] = true;
    while(!place2go.empty())
    {
        Coordinate cur = place2go.front();
        place2go.pop();

        Coordinate possible[4] = {
                {cur.first - 1 ,cur.second},
                {cur.first, cur.second -1},
                {cur.first, cur.second + 1},
                {cur.first + 1, cur.second},
                };

        for(int i = 0; i < 4; i++)
        {
            int x = possible[i].first;
            int y = possible[i].second;
            if(x >= 0 && x < boardSize && y >= 0 && y < boardSize
            && !visited[x][y])
            {
                for(char a : key)
                {
                    if(board[x][y] == a)
                    {
                        place2go.push(possible[i]);
                        visited[x][y] = true;
                        break;
                    }
                }

            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    cin >> boardSize;
    for(int i = 0; i< boardSize; i++)
    {
        string a; cin >> a;
        for(int j = 0; j< boardSize; j++)
        {
            board[i][j] = a[j];
        }
    }

    int zoneCounts = 0;
    for(int i = 0; i< boardSize; i++)
    {
        for(int j = 0; j< boardSize; j++)
        {
            if(!visited[i][j])
            {
                bfs(make_pair(i,j), vector<char>{board[i][j]});
                zoneCounts++;
            }
        }
    }
    cout << zoneCounts << ' ';

    fill(&visited[0][0], &visited[boardSize-1][boardSize], 0);
    zoneCounts = 0;
    for(int i = 0; i< boardSize; i++)
    {
        for(int j = 0; j< boardSize; j++)
        {
            if(!visited[i][j])
            {
                vector<char> a;
                if(board[i][j] =='B')
                {
                    a.push_back('B');
                }
                else
                {
                    a.push_back('R');
                    a.push_back('G');
                }

                bfs(make_pair(i,j), a);
                zoneCounts++;
            }
        }
    }
    cout << zoneCounts;


    return 0;
}