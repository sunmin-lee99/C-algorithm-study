#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M; 
vector<int> snacks;

bool check(int mid){
    int cnt = 0;

    for(int snack : snacks){
        cnt+= snack / mid;
    }
    return cnt >= N;
}

int main(){
    cin >> N >> M;
    snacks = vector<int>(M);
    for(int i = 0; i < M; i++) cin >> snacks[i];

    sort(snacks.begin(), snacks.end());

    int lo = 0;
    int hi = snacks[M - 1] + 1;
    int answer = 0;
    while(lo + 1 < hi){
        int mid = (hi + lo) / 2;
        if(check(mid)){
            lo = mid;
            answer = mid;
        }else{
            hi = mid;
        }
    }

    cout << answer << '\n';
}
