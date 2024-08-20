#include<iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int T; cin >> T;

    for(int t = 0; t < T; t++){
        int N; cin >> N;

        map<string, int> cloths;

        for(int i = 0; i < N; i++){
            string a, b;
            cin >> a >> b;

            cloths[b]++;
        }

        int answer = 1;

        for(auto a : cloths){
            answer *= a.second + 1;
        }

        cout << answer - 1 << '\n';
    }
}
