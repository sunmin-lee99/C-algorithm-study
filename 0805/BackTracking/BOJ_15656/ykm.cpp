#include <iostream>
#include <algorithm>

using namespace std;
int N,M;
int number[10];
int output[10];

void NM(int cnt){
    if(cnt==M){
        for(int i=0; i<M; i++){
            cout << number[output[i]] << ' '; 
        }
        cout << '\n';
        return;
    }

    for(int i=0; i<N; i++){         
        output[cnt]=i;
        NM(cnt+1);
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> number[i];
    }
    sort(number,number+N);
    NM(0);
}
