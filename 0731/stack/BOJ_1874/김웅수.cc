// 1874 
// endl 사용 금지.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void)
{
    /*
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int num;
    int idx = 1;
    stack<int> st;
    string result = "";

    cin>>n;

    for (int i=0;i<n;i++)
    {
        cin>>num;
        
        for (int i=1;i<=n;i++)
        {
            while (!st.empty())
            {
                if (st.top() == num)
                {
                    break;
                }
                st.pop();
                num;
                result.push_back('-');
            }
            st.push(i);
            result.push_back('+\n');
        }

    }
    return 0;
    */
    /**
     * timeout
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int seq_idx = 0;
    vector<int> seq;
    vector<int> stack;
    vector<char> result;

    cin>>n;

    for (int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        seq.push_back(num);
    }

    for (int i=1;i<=n;i++)
    {
        stack.push_back(i);
        result.push_back('+');
        while (stack.back() == seq[seq_idx] && !stack.empty())
        {
            stack.pop_back();
            seq_idx++;
            result.push_back('-');
        }
    }

    if (!stack.empty())
    {
        cout<<"NO"<<endl;
    }
    else
    {
        for (int i=0;i<result.size();i++)
        {
            cout<<result[i]<<endl;
        }
    }

    return 0;
    */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int seq_idx = 0;
    vector<int> seq;
    stack<int> st;
    string result = "";

    cin>>n;

    for (int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        seq.push_back(num);
    }

    for (int i=1;i<=n;i++)
    {
        st.push(i);
        result += "+\n";
        while (!st.empty() && st.top() == seq[seq_idx])
        {
            st.pop();
            seq_idx++;
            result += "-\n";
        }
    }

    if (!st.empty())
    {
        cout<<"NO\n";
    }
    else
    {
        cout<<result;
    }

    return 0;
}