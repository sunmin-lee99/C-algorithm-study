#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt","r",stdin);

    int A, B;
    cin >> A >> B;
    int num_a[500001],num_b[500001];
    for(int i=0; i<A; i++){
        cin >> num_a[i];
    }for(int i=0; i<B; i++){
        cin >> num_b[i];
    }
    sort(num_b, num_b+B);
    sort(num_a, num_a+A);
    int cnt=0; vector<int> nums;
    for(int i=0; i<A; i++){
        int target = num_a[i];

        int l=0, r=B-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(num_b[mid]==target){
                break;
            }else if(num_b[mid]<target){
                l=mid+1;
            }else{ // target < mid
                r=mid-1;
            }
        }
        if(l>r) {
            cnt++;
            nums.push_back(target);
        }
    }
    cout << cnt << '\n';
    if(cnt>0){
        for(auto elem: nums){
            cout << elem << ' ';
        }
    }
    return 0;
}
