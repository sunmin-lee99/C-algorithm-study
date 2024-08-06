#include <iostream>
#include <map>

using namespace std;

const int MAX = 2188;
int paper[MAX][MAX];

int ans[3] = {0,};

void recusion(int x, int y, int len){
    int tmp = paper[x][y];
    bool check = true;

    for(int i = x; i < x + len; i++){
        for(int j = y; j < y + len; j++){
            if(tmp != paper[i][j]){
                check = false;
            }
        }
    }

    if(check){
        ans[tmp + 1]++;
    }else{
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                recusion(x + len / 3 * i, y + len / 3 * j, len / 3);
            }
        }
    }
}

int main(){
    int N; cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> paper[i][j];
        }
    }

    recusion(0,0,N);

    for(int i = 0; i < 3; i++){
        cout << ans[i] << '\n';
    }
}
