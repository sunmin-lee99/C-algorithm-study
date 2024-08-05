#include <iostream>

using namespace std;
int N, M;
bool check[10];

void NM(int start, int cnt){
    if(cnt==M){
        for(int i=1;i<=N;i++){
            if(check[i])cout << i << ' ';
        }
        cout << '\n';
    }
    for(int i = start; i<=N; i++){
        if(!check[i]){
            check[i]=true;
            NM(i+1,cnt+1);
            check[i]=false;
        }
    }
}
int main(void){
    cin >> N >> M;
    NM(1,0);
}
