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

    int n;
    cin >> n;

    stack<int> nums;

    for(int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        if(input > 0)
        {
            nums.push(input);
        }
        else if(input == 0)
        {
            if(!nums.empty())
                nums.pop();
        }
    }

    int sum = 0;
    while(!nums.empty())
    {
        sum += nums.top();
        nums.pop();
    }

    cout << sum;

    return 0;
}