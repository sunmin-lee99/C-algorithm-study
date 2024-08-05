// 14891
#include <iostream>
#include <vector>

using namespace std;

void rotate_clockwise(vector<int>& gear) 
{
    int last = gear.back();
    gear.pop_back();
    gear.insert(gear.begin(), last);
}

void rotate_counterclockwise(vector<int>& gear) 
{
    int first = gear.front();
    gear.erase(gear.begin());
    gear.push_back(first);
}

void rotate(vector<vector<int>>& gears, int gear_idx, int direction, vector<bool>& visited) 
{
    visited[gear_idx] = true;

    if (gear_idx>0 && !visited[gear_idx-1]) 
    {
        if (gears[gear_idx][6] != gears[gear_idx-1][2]) 
        {
            rotate(gears, gear_idx-1, -direction, visited);
        }
    }

    if (gear_idx<3 && !visited[gear_idx+1]) 
    {
        if (gears[gear_idx][2] != gears[gear_idx+1][6]) 
        {
            rotate(gears, gear_idx+1, -direction, visited);
        }
    }

    if (direction == 1) 
    {
        rotate_clockwise(gears[gear_idx]);
    } 
    else if (direction == -1) 
    {
        rotate_counterclockwise(gears[gear_idx]);
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> gears(4, vector<int>(8));

    for (int i=0;i<4;i++) 
    {
        string gear;
        cin>>gear;
        for (int j=0;j<8;j++) 
        {
            gears[i][j] = gear[j];
        }
    }

    int K;
    cin>>K;

    while (K--) 
    {
        int gear_idx, direction;
        cin>>gear_idx>>direction;

        vector<bool> visited(4, false);
        rotate(gears, gear_idx-1, direction, visited);
    }

    int score = 0;
    if (gears[0][0] == 1)
    {
        score += 1;
    } 
    if (gears[1][0] == 1)
    {
        score += 2;
    } 
    if (gears[2][0] == 1)
    {
        score += 4;
    } 
    if (gears[3][0] == 1)
    {
        score += 8;
    } 

    cout<<score<<'\n';

    return 0;
}