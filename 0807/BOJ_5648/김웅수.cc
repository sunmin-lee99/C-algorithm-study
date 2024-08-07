// 5648
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<long long> v;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    for (int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        reverse(str.begin(), str.end());
        v.push_back(stoll(str));
    }
    sort(v.begin(), v.end());
    for (int i=0;i<n;i++)
    {
        cout<<v[i]<<'\n';
    }
    return 0;
}

