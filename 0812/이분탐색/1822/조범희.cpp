#include <iostream>
#include <algorithm>
using namespace std;

bool check[500001] = {false,};

int main(){
    int A, B; cin >> A >> B;

    vector<int> groupA(A);
    vector<int> groupB(B);

    for(int i = 0; i < A; i++) cin >> groupA[i];
    for(int j = 0; j < B; j++) cin >> groupB[j];

    sort(groupA.begin(), groupA.end());
    sort(groupB.begin(), groupB.end());

    int a = 0, b = 0;
    int size = 0;
    while(a < A && b < B){
        if(groupA[a] == groupB[b]) {
            check[a] = true;
            a++, b++;
            size++;
        }else if(groupA[a] < groupB[b]){
            a++;
        }else if(groupA[a] > groupB[b]){
            b++;
        }
    }

    if(size == A) cout << 0 << '\n';
    else {
        cout << A - size << '\n';
        for(int i = 0; i < A; i++){
            if(!check[i]) cout << groupA[i] << ' ';
        }
    }
}
