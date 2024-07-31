#include<iostream>
#include<queue>
using namespace std;

queue<int> dq;
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N; cin >> N;

    for(int i = 0; i < N; i++){
        string command;
        int num;
        cin >> command;

        if(command == "push"){
            cin >> num;
            dq.push(num);
        }else if(command == "front"){
            if(dq.empty()) cout << -1 << '\n';
            else cout << dq.front() << '\n';
        }else if(command == "back"){
            if(dq.empty()) cout << -1 << '\n';
            else cout << dq.back() << '\n';
        }else if(command == "size"){
            cout << dq.size() << '\n';
        }else if(command == "empty"){
            if(dq.empty()) cout << 1 << '\n';
            else cout << 0 << endl;
        }else if(command == "pop"){
            if(dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.front() << '\n';
                dq.pop();
            }
        }
    }
}
