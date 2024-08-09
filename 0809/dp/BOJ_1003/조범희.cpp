#include <iostream>

using namespace std;

int dp[41][2];

int main(){
    int N; 
    cin >> N;

    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;

    for(int i = 2; i < 41; i++){
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }

    int n;
    for(int i = 0; i < N; i++){
        cin >> n;
        cout << dp[n][0] << ' ' << dp[n][1] << '\n';
    }
}
