// 11399
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    
    vector<int> P(N);
    
    for (int i=0;i<N;i++) 
    {
        cin>>P[i];
    }

    sort(P.begin(), P.end());
    
    vector<int> result;
    int cum = 0;
    
    for (int i=0;i<N;i++) 
    {
        cum+=P[i];
        result.push_back(cum);
    }
    
    int total = 0;
    for (int i=0;i<N;i++) 
    {
        total+=result[i];
    }

    cout<<total<<endl;
    
    return 0;
}

