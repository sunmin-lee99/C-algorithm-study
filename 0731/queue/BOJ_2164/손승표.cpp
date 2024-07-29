//
// Created by seungpyo on 2023-02-08.
//
#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    queue<int> _que;

    int size;
    cin >> size;

    for(int i =1; i<=size;i++ )
    {
        _que.push(i);
    }

    while(_que.size() > 1 )
    {
        _que.pop();
        if(_que.size() <= 1)
        {
            break;
        }
        _que.push(_que.front());
        _que.pop();
    }

    cout << _que.front();

    return 0;
}
