#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int N;

vector<int> arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a;
	int sum = 0;
	int sum2 = 0;
	int* summer;

	cin >> N;

	summer = (int*)malloc(sizeof(int) * N);
	
	for (int i = 0; i < N; i++) {
		cin >> a;
		arr.push_back(a);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++) {
		sum += arr[i];
		summer[i] = sum;
		sum2 += summer[i];
	}

	cout << sum2;
}
