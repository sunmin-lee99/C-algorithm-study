#include <iostream>
#include <stack>


int main(void){
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios::sync_with_stdio(0);

    std::stack<int> stack;
    int K, n;
    std::cin >> K;
    while(K--){
        std::cin >> n;
        if(n==0){
            stack.pop();
        }else{
            stack.push(n);
        }
    }
    K = 0;
    while(!stack.empty()){
        K+=stack.top();
        stack.pop();
    }
    std::cout << K;
}
