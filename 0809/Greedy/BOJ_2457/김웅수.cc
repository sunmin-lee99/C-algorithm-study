// 2457
// still solving
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>>N;

    vector<pair<int, int> > flowers;

    for (int i=0;i<N;i++) 
    {
        int sm, sd, em, ed;
        cin>>sm>>sd>>em>>ed;
        int start = sm * 100 + sd;
        int end = em * 100 + ed;
        flowers.push_back(make_pair(start, end));
    }

    sort(flowers.begin(), flowers.end());

    int current_end = 301;
    int last_end = 301;
    int count = 0;
    bool possible = true;

    for (int i=0;i<N;) 
    {
        if (flowers[i].first>current_end) 
        {
            possible = false;
            break;
        }

        int max_end = current_end;
        while (i<N && flowers[i].first<=current_end) 
        {
            if (flowers[i].second>max_end) 
            {
                max_end = flowers[i].second;
            }
            i++;
        }

        count++;
        current_end = max_end;

        if (current_end > 1130) 
        {
            break;
        }
    }

    if (current_end<=1130) 
    {
        possible = false;
    }

    if (possible) 
    {
        cout<<count<<'\n';
    } 
    else 
    {
        cout<<0<<'\n';
    }

    return 0;
}

