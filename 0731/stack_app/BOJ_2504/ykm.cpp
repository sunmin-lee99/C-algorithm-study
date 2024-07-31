#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main(void){
    string str;
    cin >> str;
    stack<char> s;
    int output = 0, local = 1, cnt = 0;;
    for(char c : str){
        if(c=='['){
            cnt++;
            s.push(c);
            if(local>1){
                output += local;
                local = 1;
            }
        }else if(c=='('){
            cnt++;
            s.push(c);
            if(local>1){
                output += local;
                local = 1;
            }
        }else if(c==')'){
            cnt--;
            if(s.top()!='('){cout << '0';return 0;}
            if(cnt==0){output+=local;output *=2;local=1;}
            else{local *= 2;}
            s.pop();
        }else if(c==']'){
            cnt--;
            if(s.top()!='['){cout << '0';return 0;}
            if(cnt==0){output+=local;output *=3;local=1;}
            else{local *= 3;}
            s.pop();
        }
    }
    cout << output;
}
