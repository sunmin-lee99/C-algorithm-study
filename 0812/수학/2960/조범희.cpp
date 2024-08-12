#include <iostream>

using namespace std;

bool check[1001] = {false,};

int main(){
    int N, K; cin >> N >> K;
    int idx = 0;
    check[1] = true;
    for(int i = 2; i <= N; i++){
        if(!check[i]){
            for(int j = i; j <= N; j += i){
                if(check[j] == false){
                    check[j] = true;
                    idx++;
                }
                if(idx == K){
                    cout << j << '\n';
                    return 0;
                }
            }
        }
    }
}
