#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

int towers[500001];
int answer[500001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

    int n; cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> towers[i];
    }

    stack<int> towerStack;
    stack<int> indexStack;

    towerStack.push(towers[n]);
    indexStack.push(n);
    for(int i = n-1; i > 0; i--)
    {
        while(!towerStack.empty() && towers[i] > towerStack.top())
        {
            int index = indexStack.top();
            answer[index] = i;

            towerStack.pop();
            indexStack.pop();
        }
        towerStack.push(towers[i]);
        indexStack.push(i);
    }

    for(int i = 1; i <= n; i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}