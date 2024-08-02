#include <iostream>
using namespace std;

int pic[65][65];

int recursion(int x, int y, int w){
    int t_0; 
    int t_1;
    int t_2;
    int t_3;

    if(w==2){
        t_0 = pic[x-1][y-1]; 
        t_1 = pic[x-1][y];
        t_2 = pic[x][y-1];
        t_3 = pic[x][y];

    }else{
        t_0 = recursion(x/2,y/2,w/2);
        t_1 = recursion(x/2,y,w/2);
        t_2 = recursion(x,y/2,w/2);
        t_3 = recursion(x,y,w/2);
    }
    if(t_0==t_1 && t_1==t_2 && t_2==t_3){
        return t_0;
    }else{
        cout<<'(' << t_0 << t_1 << t_2 << t_3;
    }
    cout <<')';
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i <n; i++){
        for(int j=0;j<n;j++){
            cin >> pic[i][j];
        }
    }
    recursion(n,n,n);
}
