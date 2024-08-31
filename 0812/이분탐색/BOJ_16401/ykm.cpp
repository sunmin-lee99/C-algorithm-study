#include <iostream>
#include <algorithm>
using namespace std;

// parametric search
// 최대 과자길이 범위 내에서 탐색
// 나눠줄수 있는지 확인
int M, N;
int snacks[1000001]={0};

bool spread(int x){
    int cnt = 0;
    for(int i=N-1; i>=0; i--){
        if(snacks[i]<x) break;
        cnt += snacks[i]/x;

        if(cnt>=M) return true;
    }
    return false;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt","r",stdin);

    cin >> M >> N;
    for(int i=0; i<N; i++){
        cin >> snacks[i];
    }
    sort(snacks, snacks+N);

    int l=0, r=1000000000, mid;
    while(l<r){
        // 같은 값이 유지되는 경우에 따라 mid를 (l+r)/2로 할지 1을 더할지 선택
        mid = (l+r+1)/2;
        if(spread(mid)){ 
            l=mid;
        }else{
            r=mid-1;
        }
    }
    cout << l ;
    return 0;
}
