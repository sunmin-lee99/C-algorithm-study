#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt","r",stdin);

    int N, M; int arr[500001]; 
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    cin >> M; int target[500001]; 
    for(int i=0; i<M; i++){
        cin >> target[i];
    }
    sort(arr, arr+N);

    for(int i=0; i<M; i++){
        int elem = target[i];
        int l=0, r=N-1;
        while(l<r){
            int mid = (l+r)/2;
            
            if(arr[mid]==elem){
                break;
            }else if(arr[mid] < elem){
                l = mid+1;
            }else{//target<mid
                r = mid-1;
            }
        }
        if(l>=r)cout << "0\n";
        else cout << "1\n";
    }
    return 0;
}
