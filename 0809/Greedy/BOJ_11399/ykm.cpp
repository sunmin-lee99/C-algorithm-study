#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >>N;
    int time[N];
    for(int i=0; i<N; i++){
        cin >> time[i];
    }
    sort(time, time+N);
    int sum=0;
    for(int i=0; i<N; i++){
        sum += time[i]*(N-i);
    }
    cout << sum;
    return 0;
}
