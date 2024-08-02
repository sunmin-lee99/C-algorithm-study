// 2630
#include<iostream>

using namespace std;

int n;
int paper[128][128];
int blue, white;

void solve(int y, int x, int size)
{
    int check = paper[y][x];
    bool is_divided = false;

    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (paper[i][j] != check)
            {
                is_divided = true;
                break;
            }
        }
        if (is_divided)
        {
            break;
        }
    }

    if (is_divided)
    {
        int half = size / 2;
        solve(y, x, half);
        solve(y, x + half, half);
        solve(y + half, x, half);
        solve(y + half, x + half, half);
    }
    else
    {
        if (check == 0)
            white++;
        else
            blue++;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> paper[i][j];
        }
    }

    solve(0, 0, n);

    cout << white << '\n';
    cout << blue << '\n';

    return 0;
}
