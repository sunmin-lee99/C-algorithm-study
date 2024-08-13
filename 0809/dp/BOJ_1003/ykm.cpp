#include <iostream>
#include <vector>
using namespace std;

int T, N;
vector <pair<int,int>> fibo;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fibo.push_back({1,0});
    fibo.push_back({0,1});
    for(int i=2; i<=40; i++){
        pair<int,int> p=fibo[i-1];
        pair<int,int> pp=fibo[i-2];
        fibo.push_back({p.first+pp.first, p.second+pp.second});
    }

    cin >> T;
    while(T--){
        cin >> N;
        cout << fibo[N].first <<' '<<fibo[N].second<<'\n';
    }
}
