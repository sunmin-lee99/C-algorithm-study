#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie();

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    list<int> table;

    int num, jump;
    cin >> num >> jump;
    for(int i = 1; i <= num; i++)
    {
        table.push_back(i);
    }

    vector<int> answer;

    auto it = table.begin();
    for(int i = 1; i <= num; i++)
    {
        for(int j = 1; j < jump; j++)
        {
            it++;
            if(it == table.end())
                it = table.begin();
        }
        answer.push_back(*it);
        it = table.erase(it);
        if(it == table.end())
            it = table.begin();
    }

    cout << '<';
    for(int i = 0; i <num-1; i++)
    {
        cout << answer[i] << ", ";
    }
    cout << answer[num-1] << '>';

}