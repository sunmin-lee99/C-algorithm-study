#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];

int main(){
    int n, x;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> x;
    sort(arr, arr + n);

    int hi = n - 1;
    int lo = 0;
    int answer = 0;
    while(lo < hi){
        int sum = arr[lo] + arr[hi];

        if(sum < x){
            lo++;
        }else if(sum > x){
            hi--;
        }else{
            lo++;
            hi--;

            answer++;
        }
    }

    cout << answer << '\n';
}
