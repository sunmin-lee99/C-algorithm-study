#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int T, N, M;
int a[20000];
int b[20000];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T ;
    while(T--){
        cin >> N >> M;
        for(int i=0; i<N; i++){
            cin >> a[i];
        }
        for(int i=0; i<M; i++){
            cin >> b[i];
        }
        sort(a,a+N);
        sort(b,b+M);
        int aidx=0, bidx=0, cnt=0;
        while(true){
            if(bidx==M || aidx==N) break;

            if(a[aidx]<=b[bidx]) aidx++;
            else{
                cnt+=(N-aidx);
                bidx++;
            }
        } 
        cout << cnt <<'\n';
    }
    
}
