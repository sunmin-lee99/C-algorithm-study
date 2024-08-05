// 11559
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4]={0, 0, -1, 1};
int dy[4]={-1, 1, 0, 0};

char visited[12][6];

bool bfs(int x, int y, char color, vector<pair<int, int>>& puyo_to_pop) 
{
    queue<pair<int, int>> q;
    vector<pair<int, int>> puyo_list;
    q.push({x, y});
    puyo_list.push_back({x, y});
    visited[x][y]='.';  
    
    while(!q.empty())
    {
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();

        for(int i=0;i<4;i++) 
        {
            int nx=cx+dx[i];
            int ny=cy+dy[i];

            if(nx>=0&&nx<12&&ny>=0&&ny<6&&visited[nx][ny]==color) 
            {
                q.push({nx, ny});
                puyo_list.push_back({nx, ny});
                visited[nx][ny]='.'; 
            }
        }
    }

    if(puyo_list.size()>=4) 
    {
        puyo_to_pop.insert(puyo_to_pop.end(), puyo_list.begin(), puyo_list.end());
        return true;
    } 
    else 
    {
        for(auto& p:puyo_list) 
        {
            visited[p.first][p.second]=color;  // 복구
        }
        return false;
    }
}

void drop_puyo() 
{
    for(int j=0;j<6;j++) 
    {
        int empty_row=11;
        for(int i=11;i>=0;i--) 
        {
            if(visited[i][j]!='.') 
            {
                if(i!=empty_row) 
                {
                    visited[empty_row][j]=visited[i][j];
                    visited[i][j]='.';
                }
                empty_row--;
            }
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0;i<12;i++) 
    {
        for(int j=0;j<6;j++) 
        {
            cin>>visited[i][j];
        }
    }

    int chain_count=0;
    bool has_popped=true;

    while(has_popped)
    {
        has_popped=false;
        vector<pair<int, int>> puyo_to_pop;

        for(int i=0;i<12;i++) 
        {
            for(int j=0;j<6;j++) 
            {
                if(visited[i][j]!='.') 
                {
                    if(bfs(i, j, visited[i][j], puyo_to_pop)) 
                    {
                        has_popped=true;
                    }
                }
            }
        }

        for(auto& p:puyo_to_pop) 
        {
            visited[p.first][p.second]='.';
        }

        if(has_popped) 
        {
            drop_puyo();
            chain_count++;
        }
    }

    cout<<chain_count<<'\n';

    return 0;
}
