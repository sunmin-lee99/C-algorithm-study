#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

bool check[2000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        check[num] = true;
    }

    int x;
    cin >> x;

    int counts = 0;
    for(int i = 1; i < (x+1)/2; i++)
    {
        if(check[i] && check[x - i])
        {
            counts++;
        }
    }

    cout << counts;

    return 0;
}