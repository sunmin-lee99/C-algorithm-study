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

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int cmdCounts; cin >> cmdCounts;

    queue<int> _que;

    for(int i =0;i < cmdCounts;i++)
    {
        string cmd; cin >> cmd;

        if(cmd == "push")
        {
            int num; cin >> num;
            _que.push(num);
        }
        else if(cmd == "pop"){
            if(_que.empty())
            {
                cout<< -1 << "\n";
            }
            else
            {
                cout << _que.front() << "\n";
                _que.pop();
            }

        }
        else if(cmd == "size"){
            cout << _que.size() << "\n";
        }
        else if(cmd == "empty"){
            cout << _que.empty() << "\n";
        }
        else if(cmd == "front"){
            if(_que.empty())
            {
                cout<< -1 << "\n";
            }
            else {
                cout << _que.front() << "\n";
            }

        }
        else if(cmd == "back"){
            if(_que.empty())
            {
                cout<< -1 << "\n";
            }
            else
            {
                cout << _que.back() << "\n";
            }
        }
        else
        {

        }
    }
    return 0;
}
