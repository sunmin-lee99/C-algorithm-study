#include <iostream>
#include <string>

using namespace std;
int N, M;
//bool check[10];

void NM(int cnt, string str){
    if(cnt==M){
        cout << str <<'\n';
        return;
    }
    for(int i = 1; i<=N; i++){
        NM(cnt+1, str+to_string(i)+' ');
    }
}
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout.tie(0);
    
    cin >> N >> M;
    NM(0, "");
}
