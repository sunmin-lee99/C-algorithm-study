#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<int, pair<int, int>> cnt;

bool comp(int a, int b){
    if(cnt[a].first == cnt[b].first) return cnt[a].second < cnt[b].second;
    else return cnt[a].first > cnt[b].first;
}

int main(){
    int N; cin >> N;
    int C; cin >> C;

    vector<int> vec(N);

    for(int i = 0; i < N; i++){
        int tmp; cin >> tmp;
        vec[i] = tmp;
        if(cnt.find(tmp) == cnt.end()){
            cnt.insert({tmp, {0, i}});
        }else{
            cnt[tmp].first++;
        }
    }

    sort(vec.begin(), vec.end(), comp);

    for(auto a : vec) cout << a << ' ';
}
