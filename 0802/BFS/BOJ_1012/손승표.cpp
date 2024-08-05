#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int row, col;
bool field[50][50];
bool visited[50][50];
vector<pair<int, int>> crops;

void bfs(pair<int,int> start)
{
    queue<pair<int,int>> will;
    will.push(start);
    visited[start.first][start.second] = true;
    while(!will.empty())
    {
        pair<int,int> lets = will.front();
        will.pop();
        vector<pair<int, int>> possible(4);
        possible.emplace_back(lets.first-1, lets.second);
        possible.emplace_back(lets.first, lets.second - 1);
        possible.emplace_back(lets.first, lets.second + 1);
        possible.emplace_back(lets.first+1, lets.second);

        for(auto i : possible)
        {
            int x = i.first;
            int y = i.second;
            if(x >= 0 && x < row && y >= 0 && y < col)
            {
                if(field[x][y] && !visited[x][y])
                {
                    will.emplace(x, y);
                    visited[x][y] = true;
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

    int cases; cin >> cases;
    for(int i = 0; i< cases; i++)
    {
        int cropCounts; cin >> row >> col >> cropCounts;

        for(int i = 0; i < cropCounts; i++)
        {
            int x, y; cin >> x >> y;
            field[x][y] = true;
            crops.emplace_back(x, y);
        }

        int worms = 0;
        for(int i = 0; i < cropCounts; i++)
        {
            if(!visited[crops[i].first][crops[i].second])
            {
                worms++;
                bfs(crops[i]);
            }
        }
        cout << worms << '\n';

        fill(&field[0][0], &field[row-1][col], false);
        fill(&visited[0][0], &visited[row-1][col], false);
        crops.clear();
    }

    return 0;
}