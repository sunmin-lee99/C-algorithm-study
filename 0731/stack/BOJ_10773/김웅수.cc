// 10733
#include<iostream>
#include<stack>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> v;
    int K;
    int sum = 0;
    cin>>K;

    for (int i=0;i<K;i++)
    {
        int num;
        cin>>num;
        if (num == 0)
        {
            sum-=v.top();
            v.pop();
            continue;
        }
        v.push(num);
        sum+=num;
    }
    cout<<sum<<endl;
    
    return 0;
}