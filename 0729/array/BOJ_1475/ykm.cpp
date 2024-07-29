#include <iostream>

int main(void){
    int num;
    std::cin >> num;
    int arr[10] = {0};
    while(num){
        if(num%10==6 || num%10==9){
            arr[6]++;
        }else{
            arr[num%10]+=2;
        }
        num/=10;
    }
    int M = 0;
    for(int i = 0 ; i< 10; i++){
        if(arr[i]>M){M = arr[i];}
    }
    std::cout << (M+1)/2;
}
