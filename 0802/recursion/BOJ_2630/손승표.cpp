#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;
int paper[128][128];
int paperSize;
int zero;
int one;

bool CheckWithRecursion(int x, int y, int checkLength)
{
    int key = paper[x][y];
    for(int i = x; i < x + checkLength; i++)
    {
        for(int j = y; j < y + checkLength; j++)
        {
            if(paper[i][j] != key)
            {
                return false;
            }
        }
    }

    return true;
}

void Recursion(int x, int y, int checkLength)
{
    int key = paper[x][y];
    if(!CheckWithRecursion(x,y,checkLength))
    {
        for(int i = x; i < x + checkLength; i+=checkLength/2)
        {
            for(int j = y; j < y + checkLength; j += checkLength/2)
            {
                Recursion(i, j, checkLength/2);
            }
        }
    }
    else
    {
        if(key == 0)
        {
            zero++;
        }
        else
        {
            one++;
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

    cin >> paperSize;
    for(int i = 0; i < paperSize; i++)
    {
        for(int j = 0; j< paperSize; j++)
        {
            cin >> paper[i][j];
        }
    }

    Recursion(0,0,paperSize);

    cout << zero<< '\n';
    cout << one<< '\n';

    return 0;
}