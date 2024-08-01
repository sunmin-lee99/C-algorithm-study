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

    int stackSize = 0;

    char cursor; cin >> cursor;
    char nextCursor = 0;

    int answer = 0;
    while(cin >> nextCursor)
    {
        if(cursor == '(' && nextCursor == ')')
        {
            answer += stackSize;
            stackSize++;
        }
        else if(cursor == '(')
        {
            answer += 1;
            stackSize++;
        }
        else
        {
            stackSize--;
        }

        cursor = nextCursor;
    }

    cout << answer;

    return 0;
}