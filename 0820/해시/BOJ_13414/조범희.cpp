#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string, int> cnt;
map<string, int> order;
vector<pair<int, string>> vec;

bool comp(pair<int, string>& a, pair<int, string>& b){
    return a.first < b.first;
}

int main(){
    int N, M; cin >> N >> M;
    for(int i = 0; i < M; i++) {
        string tmp; cin >> tmp;
        order[tmp] = i;
    }

    for(auto o : order){
        vec.push_back({o.second, o.first});
    }

    sort(vec.begin(), vec.end(), comp);

    for(int i = 0; i < vec.size(); i++){
        if(i == N) break;
        
        cout << vec[i].second << "\n";
    }
}
