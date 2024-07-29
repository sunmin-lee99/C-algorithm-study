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

    int a, b, c;
    cin >> a >> b >>c;

    string target = to_string(a*b*c);

    for(char i : target)
    {
        counts[i - '0']++;
    }

    for(int i = 0; i< 10; i++)
    {
        cout << counts[i] << '\n';
    }

    return 0;
}