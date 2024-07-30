#include <iostream>
#include <algorithm>
#include <string>

const int MX=1000001;
char dat[MX];
int pre[MX], next[MX];

void traverse(){
    int curr = next[0];
    while(curr>0){
        std::cout << dat[curr];
        curr = next[curr];
    }
    std::cout << '\n';
}

int main(void){
    int n;
    std::cin >> n;
    while(n){
        std::fill(pre, pre+MX, -1);
        std::fill(next, next+MX, -1);
        int unused=1, cursor=0;

        std::string full;
        std::cin >> full;

        for(char c: full){
            if(c=='>'){
                if(next[cursor]!=-1){cursor=next[cursor];}
            }else if(c=='<'){
                if(pre[cursor]!=-1){cursor=pre[cursor];}
            }else if(c=='-'){
                if(pre[cursor]==-1){continue;} // 데이터가 없는 경우 삭제할수 없다는 부분을 잊었음
                next[pre[cursor]]=next[cursor];
                if(next[cursor]!=-1){pre[next[cursor]]=pre[cursor];}
                cursor = pre[cursor];
            }else{
                dat[unused] = c;
                pre[unused] = cursor;
                next[unused] = next[cursor];
                
                if(next[cursor]!=-1){pre[next[cursor]]=unused;}
                next[cursor] = unused;
                cursor = unused;
                unused++;
            }
        }
        n--;
        traverse();
    }

}
