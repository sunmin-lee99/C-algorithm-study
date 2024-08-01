#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main(void){
    string str;
    cin >> str;
    stack<char> s;
    int stick = 0;
    for(int i = 0; i<str.size(); i++){
        if(str[i]=='('){
            s.push(str[i]);
        }else{
            s.pop();
            if(str[i-1]!=str[i]){stick += s.size();}
            else{stick++;}
        }
    }
    cout << stick;
}
