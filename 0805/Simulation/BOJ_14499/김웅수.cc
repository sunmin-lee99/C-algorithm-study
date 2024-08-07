// 14499
#include <iostream>
#include <vector>

using namespace std;

// E, W, N, S
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int N, M, x, y, K;
vector<vector<int>> board;
vector<int> commands;

int dice[6] = {0, 0, 0, 0, 0, 0};

void roll(int direction) {
    int temp[6];
    for (int i=0;i<6;i++) 
    {
        temp[i] = dice[i];        
    }

    if (direction==1)
    {
        dice[0] = temp[3];
        dice[2] = temp[0];
        dice[5] = temp[2];
        dice[3] = temp[5];
    }
    else if (direction==2)
    {
        dice[0] = temp[2];
        dice[3] = temp[0];
        dice[5] = temp[3];
        dice[2] = temp[5];
    }
    else if (direction==3)
    {
        dice[0] = temp[4];
        dice[1] = temp[0];
        dice[5] = temp[1];
        dice[4] = temp[5];
    }
    else if (direction==4)
    {
        dice[0] = temp[1];
        dice[4] = temp[0];
        dice[5] = temp[4];
        dice[1] = temp[5];
    }
}

void move_dice() {
    for (int i=0;i<K;i++) 
    {
        int direction = commands[i];
        int nx = x + dx[direction-1];
        int ny = y + dy[direction-1];

        if (nx<0 || nx>=N || ny<0 || ny>=M) 
        {
            continue;
        }

        x = nx;
        y = ny;
        roll(direction);

        if (board[x][y]==0) 
        {
            board[x][y] = dice[5];
        } 
        else 
        {
            dice[5] = board[x][y];
            board[x][y] = 0;
        }

        cout << dice[0] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>M>>x>>y>>K;
    board.resize(N, vector<int>(M));
    commands.resize(K);

    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin>>board[i][j];
        }
    }

    for (int i=0;i<K;i++) {
        cin>>commands[i];
    }

    move_dice();

    return 0;
}
