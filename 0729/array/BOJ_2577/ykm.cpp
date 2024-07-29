#include <iostream>

int main(void){
    int num, mul=1;
    for(int i = 0; i<3; i++){
        std::cin >> num;
        mul *= num;
    }
    int arr[10] = {0};
    while(mul){
        arr[mul%10]++;
        mul /= 10;
    }
    for(int i = 0 ; i<10; i++){
        std::cout << arr[i] << "\n";
    }
    return 0;
}
