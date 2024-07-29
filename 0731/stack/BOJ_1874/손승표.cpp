#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif


    int counts; cin >> counts;

    stack<int> _stack;
    vector<char> answer;

    answer.reserve(4*counts);

    int remain = 1;
    for(int i = 1 ;i <= counts; i++)
    {
        int num; cin >> num;
        while(remain <= num)
        {
            _stack.push(remain);
            answer.push_back('+');
            answer.push_back('\n');
            remain++;
        }

        if(_stack.top() == num)
        {
            _stack.pop();
            answer.push_back('-');
            answer.push_back('\n');
        }
        else
        {
            answer.clear();
            answer.push_back('N');
            answer.push_back('O');
            answer.push_back('\n');
            break;
        }
    }


    answer.push_back(0);
    cout << answer.data();

    return 0;
}