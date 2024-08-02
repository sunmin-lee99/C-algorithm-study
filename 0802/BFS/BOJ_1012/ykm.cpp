#include <iostream>
#include <queue>
using namespace std;

int main(void){
    int T;
    cin >> T;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};

    while(T--){
        int M,N,K;
        cin >> M >> N >> K;
        int farm[55][55] = {0};

        for(int i= 0; i<K; i++){
            int x,y;
            cin >> x >> y;
            farm[x][y]=1;
            // 1 배추, 0 빈땅 , -1 방문
        }

        queue<pair<int,int>> q;
        int cnt = 0;
        for(int i=0; i<M;i++){
            for(int j =0; j<N;j++){
                if(farm[i][j]==1){
                    q.push({i,j});farm[i][j]=-1;
                    cnt++;
                }

                while(!q.empty()){
                    pair<int,int> curr = q.front();q.pop();
                    for(int k=0; k<4;k++){
                        int nx=curr.first + dx[k];
                        int ny=curr.second + dy[k];

                        if(nx<0 || ny<0 || nx>=M || ny>=N){continue;}
                        if(farm[nx][ny]!=1){continue;}

                        q.push({nx,ny});
                        farm[nx][ny]=-1;//방문표시
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
}
