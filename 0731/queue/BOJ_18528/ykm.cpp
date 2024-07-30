#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    queue<int> q;
    while(N--){
        string command;
        cin >> command;
        if(!command.compare("push")){
            int val;
            cin >> val;
            q.push(val);
        }else if(!command.compare("pop")){
            if(q.empty()){cout << "-1\n";continue;}
            cout << q.front() << '\n';
            q.pop();
        }else if(!command.compare("front")){
            if(q.empty()){cout << "-1\n";continue;}
            cout << q.front() << '\n';
        }else if(!command.compare("back")){
            if(q.empty()){cout << "-1\n";continue;}
            cout << q.back() << '\n';
        }else if(!command.compare("size")){
            cout << q.size() << '\n';
        }else if(!command.compare("empty")){
            if(q.empty()){cout << "1\n";continue;}
            cout <<'0' << '\n';
        }
    }
}
