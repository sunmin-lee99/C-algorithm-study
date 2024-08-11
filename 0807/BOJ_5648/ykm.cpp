#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
long long arr[1000000];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;
        reverse(temp.begin(), temp.end());
        arr[i]=stoll(temp);
    }
    sort(arr, arr+n);
    for(int i=0; i<n;i++){
        cout << arr[i] <<'\n';
    }
}
