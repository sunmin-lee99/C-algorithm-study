// 스택을 이용한 정렬
#include <iostream>
#include <string>
#include <stack>

int main(void){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::stack<int> stack;
    std::string output;
    int n, val;
    std::cin >> n;

    int seq=0;
    for(int i = 0; i<n ; i++){
        std::cin >> val;
        while(val>seq){
            stack.push(++seq);
            output += "+\n";
        }
        if(stack.top()==val){
            stack.pop();
            output += "-\n";
        }else{
            std::cout << "NO\n";
            return 0;
        }
    }
    std::cout << output;
    return 0;
}
