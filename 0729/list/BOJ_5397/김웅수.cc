// 5397

#include<iostream>
#include<list>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    list<int> L;
    
    cin>>N>>K;
    for (int i=1;i<=N;i++)
    {
        L.push_back(i);
    }
    
    auto cursor = L.begin(); 
    cout<<"<";
    while (true)
    {
        for (int i=0;i<K-1;i++)
        {
            cursor++;
            cursor == L.end()? cursor = L.begin() : cursor;
        }
        cout<<*cursor;
        cursor = L.erase(cursor);
        cursor == L.end()? cursor = L.begin() : cursor;
        
        if (L.size() == 0)
        {
            break;
        }
        cout<<", ";
    }

    cout<<">"<<endl;

    return 0;
}