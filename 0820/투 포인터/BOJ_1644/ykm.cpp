#include <iostream>
#include <vector>
using namespace std;

int N;
bool arr[4000001];
vector<int> pri;

void primary(){
    fill(arr, arr+N+1, true);
    arr[0]=false, arr[1]=false;
    for(int i=2;i<=N;i++){
        if(!arr[i]) {continue; }
        pri.push_back(i); 

        for(int j=i*2; j<=N; j+=i){
            arr[j]=false;
        }
    }
}
int main(void){
    cin >> N;
    primary(); // 사용할 범위내의 소수 구하기
    int st=0, en=1, sum=0, cnt=0;
    for(int en=0; en<pri.size(); en++){
        sum += pri[en];
        while(st<pri.size() && sum>=N){
            if(sum==N) cnt++;
            sum-=pri[st];
            st++;
        }
    }
    cout << cnt;
    return 0;
}
