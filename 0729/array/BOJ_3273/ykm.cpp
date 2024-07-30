#include <iostream>

int main(void){
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios::sync_with_stdio(0);
    const int MX = 2000005;
    int n, x;
    std::cin >> n;
    bool arr[MX]={false};
    for(int i = 0; i<n; i++){
        //서다 양의 정수
        std::cin >> x;
        arr[x]=true;
    }
    std::cin >> x;
    int cnt = 0;
    for(int i = 1; i<(x+1)/2; i++){ // x가 3일때 x/2시 동작하지 않았었음
        if(arr[i] && arr[x-i]){
            // std::cout << i << ' ';
            cnt++;
        }
    }
    std::cout << cnt;

    return 0;
}
