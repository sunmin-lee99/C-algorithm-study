#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int date2int(int m, int d){
    int tmp = month[m-1];
    return tmp+d;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt","r",stdin);

    int N; cin >> N;
    int s_m, s_d, e_m, e_d;
    for(int i=1;i<=12;i++){
        month[i]+=month[i-1];
    }

    pair<int,int> flowers[N];
    for(int i=0; i<N; i++){
        cin >> s_m >> s_d >> e_m >> e_d;
        int start = date2int(s_m, s_d);
        int end = date2int(e_m,e_d);
        int length = end-start;
        flowers[i]={start, -end};
    }
    sort(flowers, flowers+N);
    int current = date2int(3,1);int cnt = 0;
    int i = 0;

    while(true){
        if(current>date2int(11,30)){break;} // 종료조건
        int prev=current;
        for(; i<N; i++){// 다음 꽃 후보
            if(flowers[i].first>=prev) break; // 이어지지 않으면 
            if(-flowers[i].second>current){ // 가장 넓은 범위를 커버하는 꽃선정
                current = -flowers[i].second;
            }
        }
        if(prev==current){cout << '0'; return 0;} // 필수구간내 꽃이 피지않는 경우가 있다
        cnt++;
    }
    
    cout << cnt;
    return 0;
}
