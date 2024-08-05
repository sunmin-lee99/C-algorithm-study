// 15652
#include <iostream>
using namespace std;

int n, m;
int arr[10];

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
    int start = (k==0) ? 1 : arr[k-1]; // 이전 수보다 같거나 큰 수 선택
    for (int i=start;i<=n;i++)
    {
        arr[k] = i;
        func(k+1);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    arr[0] = 0;
    func(0);
    return 0;
}