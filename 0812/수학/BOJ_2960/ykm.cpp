#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int N, K, i=1;
    cin >> N >> K;

    bool DP[N+1];
    fill(DP,DP+N+1,1);

    while(++i<N+1){
        //if(!DP[i])continue;
        for(int j=i; j<N+1; j+=i){
            if(!DP[j]){continue;}
            DP[j]=false;K--;
            if(K<1){cout << j;return 0;}
        }
    }
}
