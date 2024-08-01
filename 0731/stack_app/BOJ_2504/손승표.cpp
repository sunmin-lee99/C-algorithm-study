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

    int temp = 1;

    int answer = 0;


    char input;
    char beforeInput = '0';

    stack<char> operators;

    while(cin >> input)
    {
        if(input == '(')
        {
            operators.push('(');
            temp *= 2;
        }
        else if(input == '[')
        {
            operators.push('[');
            temp *= 3;
        }
        else if(input == ')')
        {
            if(operators.empty() || operators.top() != '(')
            {
                answer =0;
                break;
            }

            if(beforeInput == '(')
            {
                operators.pop();
                answer += temp;
                temp /= 2;
            }
            else if(beforeInput == ')' || beforeInput == ']')
            {
                operators.pop();
                temp /= 2;
            }
            else
            {
                answer = 0;
                break;
            }
        }
        else if(input == ']')
        {
            if(operators.empty() || operators.top() != '[')
            {
                answer =0;
                break;
            }

            if(beforeInput == '[')
            {
                operators.pop();
                answer += temp;
                temp /= 3;
            }
            else if(beforeInput == ')' || beforeInput == ']')
            {
                operators.pop();
                temp /= 3;
            }
            else
            {
                answer = 0;
                break;
            }
        }

        beforeInput = input;
    }

    if(temp != 1) answer = 0;

    cout << answer;

    return 0;
}