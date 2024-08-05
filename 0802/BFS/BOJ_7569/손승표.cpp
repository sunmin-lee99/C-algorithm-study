#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int m, n, h;
typedef tuple<int, int ,int> Coordinate;
queue<tuple<int,int,int>> q;
int box[100][100][100];

void PushInQueue(Coordinate node)
{
    int x = get<0>(node);
    int y = get<1>(node);
    int z = get<2>(node);
    Coordinate possible[6] ={
            {x-1,y,z},
            {x+1,y,z},
            {x,y-1,z},
            {x,y+1,z},
            {x,y,z-1},
            {x,y,z+1}
    };

    for(auto& i : possible)
    {
        int ix = get<0>(i);
        int iy = get<1>(i);
        int iz = get<2>(i);

        if(ix >= 0 && ix < m && iy >= 0 && iy < n && iz >= 0 && iz < h
        && box[iz][iy][ix] == 0)
        {
            q.emplace(ix, iy, iz);
            box[iz][iy][ix] = 1;
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

    cin >> m >> n >> h;

    for(int k = 0; k < h; k++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int i = 0; i <m; i++)
            {
                cin >> box[k][j][i];
            }
        }
    }

    for(int k = 0; k < h; k++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int i = 0; i <m; i++)
            {
                if(box[k][j][i] == 1)
                {
                    q.emplace(i,j,k);
                }
            }
        }
    }


    int days = -1;
    while(!q.empty())
    {
        int initSize = (int)q.size();
        for(int i = 0; i < initSize; i++)
        {
            auto start = q.front();
            q.pop();
            PushInQueue(start);
        }
        days++;
    }

    for(int k = 0; k < h; k++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int i = 0; i <m; i++)
            {
                if(box[k][j][i] == 0)
                {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << days;

    return 0;
}