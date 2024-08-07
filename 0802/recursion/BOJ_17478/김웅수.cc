// 17478
#include<iostream>
using namespace std;

int N;

string loop_answer(string &answer, int depth)
{
    string prefix = "";
    for (int i=0;i<N-depth;i++)
    {
        prefix += "____";
    }

    answer += prefix + "\"재귀함수가 뭔가요?\"\n";
    if (depth == 0)
    {    
        answer += prefix + "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
    }
    else
    {
        answer += prefix + "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
        answer += prefix + "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
        answer += prefix + "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
        loop_answer(answer, --depth);
    }
    answer += prefix + "라고 답변하였지.\n";
    return answer;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin>>N;
    string result="어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";

    result = loop_answer(result, N);
    cout<<result;

    return 0;
}
