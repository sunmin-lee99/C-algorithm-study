//1181
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> v;
bool compare(string str1, string str2)
{
    if (str1.length() < str2.length())
    {
        return true;
    }
    else if (str1.length() > str2.length())
    {
        return false;
    }
    else
    {
        return str1 < str2;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    for (int i=0;i<N;i++)
    {
        string str;
        cin>>str;
        v.push_back(str);
    }
    sort(v.begin(), v.end(), compare);
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i=0;i<v.size();i++)
    {
        cout<<v[i]<<'\n';
    }

    return 0;
}
