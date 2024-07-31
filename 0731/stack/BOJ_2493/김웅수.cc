// 2493
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    int input;
    int current_min = 1e9;
    vector<int> tower;
    stack<int> lazer;
    stack<int> pos;
    unordered_map<int, int> result;

    cin>>N;
    for (int i=0;i<N;i++)
    {
        cin>>input;
        tower.push_back(input);
    }

    for (int i=tower.size()-1;i>=0;i--)
    {
        if (lazer.empty())
        {
            lazer.push(tower[i]);
            pos.push(i);
        }
        else if (lazer.top() > tower[i])
        {
            lazer.push(tower[i]);
            pos.push(i);
        }
        else
        {
            while (!lazer.empty() && lazer.top() <= tower[i])
            {
                result[pos.top()] = i+1;
                pos.pop();
                lazer.pop();                
            }
            lazer.push(tower[i]);
            pos.push(i);
        }
    }
    while (!lazer.empty())
    {
        result[pos.top()] = 0;
        pos.pop();
        lazer.pop();
    }

    for (int i=0;i<N-1;i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<result[N-1]<<"\n";

    return 0;
}