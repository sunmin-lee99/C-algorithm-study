#include <iostream>
#include <string>

using namespace std;
int N, M;
//bool check[10];

void NM(int start, int cnt, string str){
    if(cnt==M){
        cout << str <<'\n';
        return;
    }
    for(int i = start; i<=N; i++){
        NM(i, cnt+1, str+to_string(i)+' ');
    }
}
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout.tie(0);

    cin >> N >> M;
    NM(1, 0, "");
}
