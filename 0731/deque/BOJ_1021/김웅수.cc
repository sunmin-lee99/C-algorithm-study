#include<iostream>
#include<deque>

using namespace std;

int main(void)
{
    int N, M;
    int input;
    int expected_move;
    int num_2 = 0;
    int num_3 = 0;
    deque<int> deq;

    cin>>N>>M;

    for (int i=1;i<=N;i++)
    {
        deq.push_back(i);
    }

    for (int i=0;i<M;i++)
    {
        cin>>input;

        for (int j=0;j<deq.size();j++)
        {
            if (deq[j] == input)
            {
                expected_move = j;
                break;
            }
        }

        if (input==deq.front())
        {
            deq.pop_front();
        }
        else if (expected_move <= deq.size() / 2)
        {
            while (deq.front() != input)
            {
                deq.push_back(deq.front());
                deq.pop_front();
                num_3++;
            }
            deq.pop_front();
        }
        else
        {
            while (deq.front() != input)
            {
                deq.push_front(deq.back());
                deq.pop_back();
                num_2++;
            }
            deq.pop_front();
        }
    }
    
    cout<<num_2+num_3<<"\n";

    return 0;
}