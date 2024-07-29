// 1158

#include<iostream>
#include<list>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin>>T;

    for (int i=0;i<T;i++)
    {
        string s;
        list<char> L;

        cin>>s;

        auto cursor = L.begin();

        for (auto c:s)
        {
            if (c == '<')
            {
                cursor != L.begin() ? cursor-- : cursor;
            }
            else if (c == '>')
            {
                cursor != L.end() ? cursor++ : cursor;
            }
            else if (c == '-')
            {
                cursor != L.begin() ? cursor = L.erase(--cursor) : cursor;
            }
            else
            {
                L.insert(cursor, c);
            }
        }
        for (auto c:L)
        {
            cout<<c;
        }
        cout<<endl;
        /** 
         * vector의 경우 :
        vector<char> V;

        cin >> s;

        auto cursor = V.begin();

        for (auto c : s)
        {
            if (c == '<')
            {
                cursor != V.begin() ? cursor-- : cursor;
            }
            else if (c == '>')
            {
                cursor != V.end() ? cursor++ : cursor;
            }
            else if (c == '-')
            {
                if (cursor != V.begin())
                {
                    cursor = V.erase(cursor - 1);
                }
            }
            else
            {
                cursor = V.insert(cursor, c);
                cursor++;
            }
        }
        */
    }
    
    return 0;
}