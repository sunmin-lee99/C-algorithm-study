#include <iostream>
#include <queue>

int main(void){
    int N;
    std::cin >> N;
    std::queue<int> q;

    for(int i = 1 ; i < N+1 ; i ++){
        q.push(i);
    }
    while(q.size()>1){
        q.pop();
        int save = q.front();
        q.pop();
        q.push(save);
    }
    std::cout << q.front();
    return 0;
}
