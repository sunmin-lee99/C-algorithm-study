#include <iostream>

#define MAX_SIZE 2000000

using namespace std;

int q[MAX_SIZE];
int head = 0;
int tail = 0;

void push(int x)
{
	q[tail++]=x;
}

int pop()
{
	int ret_val = q[head++];
	if (tail-head < 0)
	{
		head = tail;
		ret_val = -1;
	}
	return ret_val;
}

int size()
{
	return tail-head;
}

bool empty()
{
	bool result;
	(tail - head) == 0 ? result = true : result = false;
	return result;
}

int front()
{
	if (empty())
	{
		return -1;
	}
	return q[head];
}

int back()
{
	if (empty())
	{
		return -1;
	}
	return q[tail-1];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	int check;
	string input;
	cin>>N;
	
	for (int i=0;i<N;i++)
	{
		cin>>input;

		if (input=="push")
		{
			cin>>check;
			push(check);
		}
		else if (input=="pop")
		{
			cout<<pop()<<"\n";
		}
		else if (input=="front")
		{
			cout<<front()<<"\n";
		}
		else if (input=="back")
		{
			cout<<back()<<"\n";
		}
		else if (input == "empty")
		{
			cout<<empty()<<"\n";
		}
		else if (input == "size")
		{
			cout<<size()<<"\n";
		}
		else
		{
			cout<<"error"<<"\n";
		}
	}
	return 0;
}