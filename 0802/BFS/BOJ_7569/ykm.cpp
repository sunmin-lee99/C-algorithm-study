#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,M,H;
    cin >> N >> M >> H;
    int tomato[100][100][100]={0};
    queue<tuple<int,int,int>> q;
    int cnt = 0, day=0;

    for(int k = 0; k<H; k++){
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                cin >> tomato[i][j][k];

                if(tomato[i][j][k]==1){
                    q.push({i,j,k});
                    cnt ++;
                }else if(tomato[i][j][k]==-1){cnt++;}
            }
        }
    }

    int dx[6]={0,0,-1,1,0,0};
    int dy[6]={-1,1,0,0,0,0};
    int dh[6]={0,0,0,0,-1,1};
    while(!q.empty()){
        tuple<int,int,int> curr = q.front();q.pop();
        int x=get<0>(curr);
        int y=get<1>(curr);
        int h=get<2>(curr);
        day = (tomato[x][y][h]>day)? tomato[x][y][h]: day;

        for(int i=0; i<6; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            int nh=h+dh[i];
            
            if(nx<0 || ny<0 || nh<0 || nx>=N || ny>=M || nh>=H){continue;}
            if(tomato[nx][ny][nh]!=0){continue;}
            q.push({nx,ny,nh});
            tomato[nx][ny][nh]=tomato[x][y][h]+1;
            cnt++;
        }
    }
    if(cnt!=N*M*H){
        cout << "-1";
    }else{cout << day-1;}
}
