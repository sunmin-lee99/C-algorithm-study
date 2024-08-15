#include <iostream>
#include <string>
using namespace std;

int n;
int tri[140000]; // 입력되는 값 저장
int val[140000]; // 현재 값을 포함한 최대 합

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    cin >> n;

    int stair = 1;
    int idx = 0;
    while(true){
        if(stair > n) break;

        for(int i=0; i<stair; i++){
            cin >> tri[idx+i];
            if(idx+i==0) val[0]=tri[0];
            else if(i==0){ // 왼쪽 벽
                val[idx+i]= val[idx-stair+1]+tri[idx+i];
            }else if(i==stair-1){ // 오른쪽 벽
                val[idx+i]= val[idx+i-stair]+tri[idx+1];
            }
            else { // 삼각형 내부
                val[idx+i]=max(val[idx+i-stair],val[idx+i-stair+1])+tri[idx+i];
            }
        }
        idx += stair; stair++; 
    }
    int max=0;
    for(int i=idx-1; i>idx-stair; i--){
        if(val[i]>max) max=val[i];
    }
    cout << max;
    return 0;
}
