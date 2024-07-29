#include <iostream>
#include <cstring>
using namespace std;

int arr[10] = {0,};

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    int x = a * b * c;
    while(x > 0){
        arr[ x % 10]++;

        x /= 10;

    }

    for(int i = 0; i < 10; i++){
        cout << arr[i] << '\n';
    }
}
