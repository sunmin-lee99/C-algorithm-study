#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int N; cin >> N;

    vector<long long> vec;

    for(int i = 0; i < N; i++){
        string str; cin >> str;

        reverse(str.begin(), str.end());
        vec.push_back(stol(str));
    }

    sort(vec.begin(), vec.end());

    for(auto a : vec){
        cout << a << '\n';
    }
}
