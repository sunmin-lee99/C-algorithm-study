#include <iostream>
#include <string>

using namespace std;
char map[12][6];

bool bomb[12][6];
bool check[12][6];

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

void gravity(){
    bool flag=false;
    for(int i=11;i>-1;i--){
        for(int j = 0 ; j<6; j++){
            if(bomb[i][j])
            {map[i][j]=map[i-1][j];
            map[i-1][j]='.';
            if(map[i][j]!='.')flag=true;
            }
        }
    }
    if(flag) gravity();
}

bool baaaamb(){
    bool flag=false;
    for(int i=0; i<12; i++){
        for(int j=0; j<6; j++){
            if(bomb[i][j]) map[i][j]='.';
            flag=true;
        }
    }
    return flag;
}

int DFS(int x, int y, int count){
    if(check[x][y]) return false;
    check[x][y]=true;
    if(map[x][y]=='.') return false;

    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx<0 || ny<0 || nx>11 || ny>11) continue;
        if(check[nx][ny]) continue;
        if(map[x][y]!=map[nx][ny]) continue;

        count=DFS(nx,ny,count+1);
        if(count>=4){bomb[nx][ny]=true;map[nx][ny]='.';}
    }
    cout << map[x][y] << count << '\n';
    return count;
}

void currentState(){
    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            cout << map[i][j];
        }
        cout<<'\n';
    }
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<12;i++){
        string line;
        cin >> line;
        for(int j = 0 ; j<6; j++){
            map[i][j]=line[j];
        }
    }

    int cnt = 0;
    while(true){
        bomb[12][6]={0}; //초기화
        check[12][6]={0};
        bool flag = false;

        for(int i=11; i>-1; i--){
            for(int j=0;j<6; j++){
                char type = map[i][j];
                if(type=='.' || check[i][j]) continue;
                int count = DFS(i,j,1);
                if(count>=4) {
                    map[i][j]='.';
                    bomb[i][j]=true;
                    flag=true;
                }
            }
        }
        if(flag) {
            baaaamb();
            gravity();
            currentState();
        }
        else {
            break;
        }
        cnt++;
    }
    cout << cnt;
}
