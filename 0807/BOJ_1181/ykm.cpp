#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<string> v;

bool cmp(string &a, string &b){
    if(a.length()==b.length()){return a<b;}
    return a.length()<b.length();
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >>N;
    for(int i=0; i<N; i++){
        string tmp;
        cin >> tmp;
        v.emplace_back(tmp);
    }

    sort(v.begin(),v.end(),cmp);

    cout << v[0] <<'\n';
    for(int i=1;i<N;i++){
        if(v[i]==v[i-1]) continue;
        cout << v[i] <<'\n';
    }
}
