#include <iostream>
#define ll long long
using namespace std;

ll prefix[10001];

int main(){
    ll N, M; cin >> N >> M;

    for(ll i = 1; i <= N; i++){
        ll tmp; cin >> tmp;
        prefix[i] = prefix[i - 1] + tmp;
    }

    int hi = 1;
    int lo = 0;
    int answer = 0;

    while(hi <= N){
        ll value = prefix[hi] - prefix[lo];

        if(value == M){
            answer++;
            lo++;
            hi++;
        }else if(value < M){
            hi++;
        }else if(value > M){
            lo++;
        }
    }

    cout << answer << '\n';
}
