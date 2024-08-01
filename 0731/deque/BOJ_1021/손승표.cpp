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

    deque<int> circular;

    int total, extract;
    cin >> total >> extract;

    for(int i = 1; i <= total; i++)
    {
        circular.push_back(i);
    }

    int totalJump = 0;
    for(int i = 0; i < extract; i++)
    {
        int target; cin >> target;

        int first = circular.front();
        int jump = 0;
        while(first != target)
        {
            circular.pop_front();
            circular.push_back(first);
            jump++;
            first = circular.front();
        }

        jump = min(jump, (int)circular.size() - jump);
        circular.pop_front();

        totalJump += jump;
    }

    cout << totalJump;

    return 0;
}