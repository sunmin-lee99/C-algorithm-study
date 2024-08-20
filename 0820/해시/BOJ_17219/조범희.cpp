#include <iostream>
#include <map>

using namespace std;

map<string, string> password;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; cin >> N >> M;

    for(int i = 0; i < N; i++){
        string a, b; cin >> a >> b;

        password.insert({a, b});
    }

    for(int i = 0; i < M; i++){
        string tmp; cin >> tmp;
        cout << password[tmp] << '\n';
    }
}
