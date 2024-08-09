#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<vector<int> > triangle(n);

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<=i;j++)
        {
            int val;
            cin>>val;
            triangle[i].push_back(val);
        }
    }

    vector<vector<int> > dp(1, triangle[n-1]);

    for (int i=n-2;i>=0;i--) 
    {
        vector<int> curList;
        for (int j=0;j<triangle[i].size();j++) 
        {
            int max_val = max(dp.back()[j] + triangle[i][j], dp.back()[j+1] + triangle[i][j]);
            curList.push_back(max_val);
        }
        dp.push_back(curList);
    }

    cout<<dp.back()[0]<<'\n';

    return 0;
}

