#include<iostream>
using namespace std;

int main(void)
{
	int N;
	int tmp, result;
	int rooms[10] = {0,};
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	result = 0;

	while (N>0)
	{
		tmp=N%10;
		if (tmp==6 || tmp==9)
		{
			rooms[6]>rooms[9] ? tmp=9 : tmp=6;
		}
		rooms[tmp]++;
		result<rooms[tmp] ? result=rooms[tmp] : tmp;
		N/=10;
	}
	cout<<result<<endl;
	return 0;
}
