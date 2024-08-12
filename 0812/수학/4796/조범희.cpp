#include <iostream>

using namespace std;

int main(){
    int L, P, V;
    cin >> L >> P >> V;
    int idx = 1;
    while(L != 0 && P != 0 && V != 0){
        int answer = V / P * L;

        if(V % P > L) answer += L;
        else answer += V % P;

        cout << "Case " << idx << ": " << answer << "\n";
        cin >> L >> P >> V;
        idx++;
    }
}
