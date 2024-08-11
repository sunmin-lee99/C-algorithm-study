#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int>&a, pair<int, int>&b){
    if(a.first < b.first) return true;
    else if(a.first == b.first){
        return a.second > b.second;
    }else return false;
}

vector<pair<int, int>> vec;

int main(){
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        vec.push_back({a*100 + b, c*100 + d});
    }
    
    sort(vec.begin(), vec.end(), comp);
    
    int idx = 0;
    int end_day = 1201;
    int start_day = 301;
    int answer = 0;
    int nextStart = 0;
    while(start_day < end_day){
        bool flag = false;

        for(int i = idx; i < N; i++){
            if(vec[i].first > start_day) break; // 새로운 꽃 선택 할 수 없음. 이 꽃이 지는 날 보다 다음 꽃이 늦게 핌
            
            if(nextStart < vec[i].second){ // 새로운 꽃을 선택하고 꽃이 지는날을 시작일로 선택하기 위해 저장
                idx = i + 1;
                flag = true;
                nextStart = vec[i].second;
            }
        }
        
        if(flag){
            answer++;
            start_day = nextStart; // 다음 시작일 = 지금 꽃이 지는 날
        }else{
            break; // 꽃을 새로 선택하지 못했음.
        }
    }
    //cout << nextStart << " " << end_day << endl;
    if(nextStart < end_day) cout << 0 << '\n';
    else cout << answer << '\n';
    
    return 0;
}
