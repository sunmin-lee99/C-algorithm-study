#include <iostream>

const int MX=10000;
int dat[MX], nxt[MX], pre[MX];

int main(void){
    std::fill(nxt, nxt+MX, -1);
    int n, k;
    std::cin >> n >> k;
    for(int i = 1; i<n+1; i++){
        dat[i]=i;
        pre[i]=i-1;
        nxt[i]=i+1;
        if(i==n){
            nxt[n]=1;
            pre[1]=n;
        }
    }
    int curr=1;
    int step=1;
    std::cout << "<";
    while(true){
        if(curr==nxt[curr]){
            std::cout << dat[curr];
            break;
        }

        if(step%k==0){
            std::cout << dat[curr] << ", ";
            nxt[pre[curr]]=nxt[curr];
            pre[nxt[curr]]=pre[curr];
        }
        curr = nxt[curr];
        step++;
    }
    std::cout << ">";
}
