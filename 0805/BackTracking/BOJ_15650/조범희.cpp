#include <iostream>

using namespace std;

#define MAX 9

int resultArr[MAX];
bool chackVis[MAX] = {false};

void Back(int _depth, int _cnt ,const int& _N, const int& _M)
{
    if (_depth == _M)
    {
        for (int i = 0; i < _M; i++)
        {
            printf("%d ", resultArr[i] + 1);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < _N; i++)
    {
        if (!chackVis[i] && _cnt < i + 1)
        {
            chackVis[i] = true;
            resultArr[_depth] = i;
            Back(_depth + 1, i, _N, _M);
            chackVis[i] = false;
        }
    }
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    Back(0, 0, N, M);

    return 0;
}
