#define MY_LOCAL_TEST

#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string& input, string delimiter)
{
    vector<string> results;
    auto start = 0;
    auto end = input.find(delimiter);
    while(end != string::npos)
    {
        results.push_back(input.substr(start, end - start));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }
    results.push_back(input.substr(start));

    return results;
}

void PrintAnswer(string& instructions, deque<string>& numdeque)
{
    bool isForward = true;
    for(auto a : instructions)
    {
        if(a == 'R')
        {
            isForward = !isForward;
        }
        else if (a == 'D')
        {
            if(numdeque.empty())
            {
                cout << "error" << '\n';
                return;
            }
            else if(isForward)
            {
                numdeque.pop_front();
            }
            else
            {
                numdeque.pop_back();
            }
        }
    }

    vector<string> answer;
    if(isForward)
    {
        for(int i = 0; i < numdeque.size(); i++)
        {
            answer.push_back(numdeque[i]);
            answer.emplace_back(",");
        }
        if(!answer.empty())
        {
            answer.pop_back();
        }
    }
    else
    {
        for(int i = (int)numdeque.size()-1; i >= 0 ; i--)
        {
            answer.push_back(numdeque[i]);
            answer.emplace_back(",");
        }
        if(!answer.empty())
        {
            answer.pop_back();
        }
    }

    cout << '[';
    for(const auto& i : answer)
    {
        cout << i;
    }
    cout << ']';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef MY_LOCAL_TEST
    freopen("input.txt", "r", stdin);
#endif

   int cases; cin >> cases;

   for(int i =0; i< cases; i++)
   {
       string instructions; cin >>instructions;
       int size; cin >> size;
       string numbers; cin >> numbers;

       auto numvector = split(numbers.substr(1,numbers.size()-2), ",");

       deque<string> numdeque;
       if(size > 0)
       {
           copy(numvector.begin(), numvector.end(), back_inserter(numdeque));
       }

       PrintAnswer(instructions, numdeque);
   }

    return 0;
}