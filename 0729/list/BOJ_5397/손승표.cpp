#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int cases;
    cin >> cases;


    for(int i = 0; i< cases; i++)
    {
        string input;
        cin >> input;

        list<char> password;
        auto it = password.begin();

        for(char i : input)
        {
            if(i == '<')
            {
                if(it != password.begin())
                {
                    it--;
                }
            }
            else if(i == '>')
            {
                if(it != password.end())
                {
                    it++;
                }
            }
            else if(i == '-')
            {
                if(it != password.begin())
                {
                    it = password.erase(--it);
                }
            }
            else
            {
                it = password.insert(it, i);
                it++;
            }
        }

        for(char i : password)
        {
            cout << i;
        }
        cout << '\n';
    }



    return 0;
}