#include <iostream>
#include <stack>
using namespace std;

int main(){    
    int N; cin >> N;

    stack<int> stk;

    for(int i = 0; i < N; i++){
        int a; cin >> a;
        if(a == 0) stk.pop();
        else stk.push(a);
    }
    int ans = 0;
    while(!stk.empty()){
        ans += stk.top();
        stk.pop();
    }

    cout << ans << '\n';
}
