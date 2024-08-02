// 1780
#include<iostream>
#include<unordered_map>
#include<cmath>
using namespace std;

int N;
int input;
int paper[3*3*3*3*3*3*3][3*3*3*3*3*3*3];
unordered_map<int, int> um;

void finder(int size, int x_start, int y_start)
{
    int check_num=100;
    bool is_same=true;

    for (int i=x_start;i<x_start+size;i++)
    {
        for (int j=y_start;j<y_start+size;j++)
        {
            if(i==x_start && j==y_start)
            {
                check_num = paper[i][j];
            }
            else if(paper[i][j] != check_num)
            {
                is_same = false;
                break;
            }
        }
        if (is_same == false)
        {
            break;
        }
    }
    if (is_same)
    {
        um[check_num]++;
    }
    else
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                finder(size/3, x_start + size/3*i, y_start + size/3*j);
            }
        }
    }
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    int check_num=100;
    bool is_same=true;
    um.insert(make_pair(-1, 0));
    um.insert(make_pair(0, 0));
    um.insert(make_pair(1, 0));

    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            cin>>input;
            paper[i][j] = input;
            if (i==0 && j==0)
            {
                is_same=input;
            }
            else if (input!=check_num)
            {
                is_same=false;
            }
        }
    }
    finder(N, 0, 0);
    cout<<um[-1]<<"\n"<<um[0]<<"\n"<<um[1]<<"\n";

    return 0;
}

