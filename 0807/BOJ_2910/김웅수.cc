//2910
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map<int, int> freq;
unordered_map<int, int> first_appear; 
vector<int> v;

bool compare_freq(int num1, int num2)
{
    if (freq[num1] != freq[num2])
    {
        return freq[num1] > freq[num2];
    }
    else
    {
        return first_appear[num1] < first_appear[num2];
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, C;
    cin>>N>>C;
    int num;
    for (int i=0;i<N;i++)
    {
        cin>>num;
        v.push_back(num);
        if (freq.find(num)==freq.end())
        {
            first_appear[num]=i;
        }
        freq[num]++;
    }

    sort(v.begin(), v.end(), compare_freq);

    for (int i=0;i<v.size();i++)
    {
        cout<<v[i]<<' ';
    }
    cout<<'\n';
    return 0;
}

