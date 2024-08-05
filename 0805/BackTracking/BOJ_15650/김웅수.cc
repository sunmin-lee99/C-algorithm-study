// 15650 
#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool used[10];

void func(int k)
{
    if (k==m)
    {
        for (int i=0;i<m;i++)
        {
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for (int i=1;i<=n;i++)
    {
        if (!used[i])
        {
            if (k>0&&arr[k-1]>i)
            {
                continue;
            }
            arr[k] = i;
            used[i] = true;
            func(k+1);
            used[i] = false;
        }
    }
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    func(0);
    return 0;
}