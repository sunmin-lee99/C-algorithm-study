//1003
#include <iostream>
#include <vector>
using namespace std;
/**
 * default fibo
int fibonacci(int n) {
    if (n == 0) {
        printf("0");
        return 0;
    } else if (n == 1) {
        printf("1");
        return 1;
    } else {
        return fibonacci(n‐1) + fibonacci(n‐2);
    }
}
*/
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    for (int i=0;i<T;i++)
    {
        int N;
        cin>>N;
        if (N==0)
        {
            cout<<"1 0\n";
        }
        else if (N==1)
        {
            cout<< "0 1\n";
        }
        else
        {
            vector<int> dp0;
            vector<int> dp1;
            dp0.push_back(1);
            dp0.push_back(0);
            dp1.push_back(0);
            dp1.push_back(1);
            for (int j=2;j<=N;j++)
            {
                dp0.push_back(dp0[j-1] + dp0[j-2]);
                dp1.push_back(dp1[j-1] + dp1[j-2]);
            }
            cout<<dp0.back()<<" "<<dp1.back()<<'\n';
        }
    }

    return 0;
}
