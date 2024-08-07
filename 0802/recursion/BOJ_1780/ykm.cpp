#include <iostream>
#include <list>
using namespace std;

int paper[2187][2187];
int cnt_paper[3]={0,0,0};

void cnt(int x_1, int y_1, int x_2, int y_2){
    bool is_same = true;
    int type = paper[x_1][y_1];

    for(int i = x_1; i<x_2;i++){
        for(int j=y_1; j<y_2;j++){
            if(!is_same) break;
            is_same = type==paper[i][j];
        }
        if(!is_same) break;
    }
    if(is_same){
        cnt_paper[type]++;
    }else{
        int step = (x_2-x_1)/3;
        cnt(x_1,y_1,x_1+step,y_1+step);
        cnt(x_1+step,y_1,x_1+step*2,y_1);
        cnt(x_1+step*2,y_1,x_2,y_1);

        cnt(x_1,y_1+step,x_1+step,y_1+step);
        cnt(x_1+step,y_1+step,x_1+step*2,y_1+step);
        cnt(x_1+step*2,y_1+step,x_2,y_1+step);

        cnt(x_1,y_2,x_1+step,y_2);
        cnt(x_1+step,y_2,x_1+step*2,y_2);
        cnt(x_1+step*2,y_2,x_2,y_2);
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j = 0 ; j<N; j++){
            int local;
            cin >> local;
            paper[i][j] = local+1;
        }
    }
    cnt(0,0,N,N);
    cout << cnt_paper[0] << '\n' << cnt_paper[1] << '\n' << cnt_paper[2];

}
