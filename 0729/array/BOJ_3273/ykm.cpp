#include <iostream>

int main(void){
    int n, x;
    std::cin >> n;
    int arr[100000]={0};
    for(int i = 0; i<n; i++){
        std::cin >> arr[i];
    }
    std::cin >> x;

    char check[2000001]={0};
    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(check[x-arr[i]]){cnt+=check[x-arr[i]];}
        check[arr[i]]++;
    }
    std::cout << cnt;

    return 0;
}
