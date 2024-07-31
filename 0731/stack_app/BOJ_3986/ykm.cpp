#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    string pair;

    cin >> N;
    int count = 0;
    while(N--){
        cin >> pair;
        stack<char> s;
        for(char c:pair){
            if(c=='A'){
                if(s.empty()){
                    s.push(c);
                }else if(s.top()=='A'){
                    s.pop();
                }else{
                    s.push(c);
                }
            }else{
                if(s.empty()){
                    s.push(c);
                }else if(s.top()=='B'){
                    s.pop();
                }else{
                    s.push(c);
                }
            }
        }
        if(s.empty()){count ++;}
    }
    cout << count;
}
