#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){    
    int N; cin >> N;
    stack<int> stk;
    stack<int> IntegerStack;
    for(int i = N; i > 0; i--){
        IntegerStack.push(i);
    }
    vector<char> answer;
    for(int i = 0; i < N; i++){
        int now; cin >> now;

        if(stk.empty() || stk.top() < now){
            bool flag = false;
            while(!IntegerStack.empty()){

                stk.push(IntegerStack.top());
                IntegerStack.pop();
                answer.push_back('+');
                if(stk.top() == now) {
                    stk.pop();
                    answer.push_back('-');
                    flag = true;
                    break;
                }
            }

            if(IntegerStack.empty() && !flag){
                cout << "NO\n";
                return 0;
            }
        }else if(stk.top() > now){
            bool flag = false;

            while(!stk.empty()){
                if(stk.top() == now) {
                    stk.pop();
                                        answer.push_back('-');

                    flag = true;
                    break;     
                }           
                else stk.pop();                
                answer.push_back('-');

            }

            if(stk.empty() && !flag){
                cout << "NO\n";
                return 0;
            }
        }else if(stk.top() == now){
            stk.pop();
            answer.push_back('-');
        }
    }

    for(char c : answer) cout << c << '\n';
}
