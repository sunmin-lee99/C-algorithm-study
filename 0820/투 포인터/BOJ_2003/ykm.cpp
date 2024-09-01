#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    int arr[N];
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    int st=0, cnt=0, sum=0;
    for(int en=0; en<N; en++){
        sum+=arr[en];
        while(st<N && sum>=M){
            if(sum==M) cnt++;
            sum-=arr[st]; st++;
        }
    }
    cout << cnt;
    return 0;
}
