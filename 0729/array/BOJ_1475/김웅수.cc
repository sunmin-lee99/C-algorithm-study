#include<iostream>
//#include<unordered_map>
using namespace std;

int main(void)
{
	int A, B, C;
	int result;
	int counter[10] = {0,};
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>A>>B>>C;
	
	result = A*B*C;
	while (result>0)
	{
		counter[result%10]++;
		result = int(result/10);
	}
	for (int i=0;i<10;i++)
	{
		cout<<counter[i]<<endl;
	}
	return 0;

	/*
	unordered_map<int, int> um;

	cin>>A>>B>>C;	
	result = A*B*C;
	while (result>0)
	{
		um[result%10]++;
		result = int(result/10);
	}
	for (int i=0;i<10;i++)
	{
		cout<<um[i]<<endl;
	}
	return 0;
	*/
}
