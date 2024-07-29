// 3273
#include<iostream>
#include<algorithm>

using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, x;
	int *a;
	int s, e, result;

	cin>>n;

	a = new int[n];
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	s=0; 
	e=n-1;
	result=0;

	cin>>x;

	// nlogn?
	sort(a, a+n);
	
	while (s<e)
	{
		if (a[s]+a[e]==x)
		{
			result++;
			s++;
			e--;
		}
		else
		{
			a[s]+a[e]>x ? e-- : s++;
		}
	}

	cout<<result<<endl;
		
	return 0;
}
