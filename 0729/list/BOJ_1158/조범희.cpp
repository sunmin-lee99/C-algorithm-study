#include <iostream>
#include <queue>

using namespace std;

int main(){
    int N, K; cin >> N >> K;
    queue<int> ysp;
    for (int i = 0; i < N; i++){
        ysp.push(i + 1);
    }
    int idx = 1;
    cout << '<';
    while(!ysp.empty()){
        int now = ysp.front();
        ysp.pop();

        if(idx == K){
            idx = 1;
            if(!ysp.empty())
                cout << now << ", ";
            else
                cout << now;
        }else{
            idx++;
            ysp.push(now);
        }
    }
    cout << '>' << '\n';
}
