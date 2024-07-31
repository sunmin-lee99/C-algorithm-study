//5430

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    int n;
    string input;
    string p; // == command

    cin>>T;
    for (int i=0;i<T;i++)
    {
        cin>>p;
        deque<int> integers;
        bool reversed = false; // false == reverse, true == normal
        bool e = false;
        cin>>n;

        // input
        cin>>input;
        input = input.substr(1, input.size()-2);

        stringstream ss(input);
        string buffer;

        while (getline(ss, buffer, ','))
        {
            integers.push_back(stoi(buffer));
        }

        // do command
        for (auto c:p)
        {
            if (c=='R')
            {
                reversed = !reversed;
            }
            else if (c=='D')
            {
                if (integers.empty())
                {
                    e = true;
                    break;
                }
                if (reversed)
                {
                    integers.pop_back();
                }
                else
                {
                    integers.pop_front();
                }
                
            }
        }

        // print result
        if (e)
        {
            cout<<"error\n";
        }
        else
        {
            cout<<"[";
            if (reversed)
            {
                for (int k=integers.size()-1;k>=0;k--)
                {
                    cout<<integers[k];
                    if (k!=0)
                    {
                        cout<<",";
                    }
                }
            }
            else
            {
                for (int k=0;k<integers.size();k++)
                {
                    cout<<integers[k];
                    if (k!=integers.size()-1)
                    {
                        cout<<",";
                    }
                }

            }
            cout<<"]\n";
        }
    }

    return 0;
}