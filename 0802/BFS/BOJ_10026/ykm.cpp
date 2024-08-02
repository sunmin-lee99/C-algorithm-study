#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N;
char paint[100][100];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int cnt_space(bool isRG){
    bool visit[100][100]={0};
    queue<pair<int,int>> q;
    int cnt=0;
    for(int i=0; i< N; i++){
        for(int j=0; j< N; j++){
            if(!visit[i][j]){
                q.push({i,j});
                visit[i][j]=true;
                cnt++;
            }

            while(!q.empty()){
                pair<int,int> curr = q.front(); q.pop();
                char type = paint[curr.first][curr.second];

                for(int k=0; k<4; k++){
                    int nx = curr.first + dx[k];
                    int ny = curr.second + dy[k];

                    if(nx<0 || ny<0 || nx>=N || ny>=N || visit[nx][ny]){continue;}
                    if(isRG){
                        if(type+paint[nx][ny]=='R'+'B'){continue;}
                        if(type+paint[nx][ny]=='G'+'B'){continue;}
                    }
                    else if(paint[nx][ny]!=type){continue;}


                    q.push({nx,ny});
                    visit[nx][ny]=true;
                }
                

            }
        }
    }
    return cnt;
}
int main(void){
    cin >> N;
    for(int i=0; i< N; i++){
        string str;
        cin >> str;
        for(int j=0; j< N; j++){
            paint[i][j]=str[j];
        }
    }

    cout << cnt_space(false) << ' ' << cnt_space(true);

}
