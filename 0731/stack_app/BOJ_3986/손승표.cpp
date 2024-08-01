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

    int cases; cin >> cases;

    int answer = 0;
    for(int i =0; i< cases; i++)
    {
        stack<char> alphabet;
        string word; cin >> word;
        for(auto a : word)
        {
            if(alphabet.empty())
            {
                alphabet.push(a);
            }
            else if(alphabet.size() == 1)
            {
                if(alphabet.top() == a)
                {
                    alphabet.pop();
                }
                else
                {
                    alphabet.push(a);
                }
            }
            else
            {
                if(alphabet.top() == a)
                {
                    alphabet.pop();
                }
                else
                {
                    alphabet.push(a);
                }
            }
        }

        if(alphabet.empty())
        {
            answer++;
        }
    }

    cout << answer;

    return 0;
}