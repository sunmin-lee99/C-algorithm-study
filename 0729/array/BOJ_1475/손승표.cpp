#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int counts[10];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int a;
    cin >> a;
    string room = to_string(a);

    for(char i : room)
    {
        counts[i-'0']++;
    }

    counts[6] = static_cast<int>(ceil((counts[6] + counts[9])/2.0));
    counts[9] = counts[6];

    int max = 0;
    for(int i : counts)
    {
        if(i > max)
        {
            max = i;
        }
    }

    cout << max;

    return 0;
}