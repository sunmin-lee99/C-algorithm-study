#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<stack>
using namespace std;



int	binary_Serch(int* arr, int n, int val) {
	int high = n - 1;
	int low = 0;
	int mid;

	while (low <= high) {
		mid = (high + low) / 2;
		if (arr[mid] > val) {
			high = mid - 1;
		}
		else if (arr[mid] < val) {
			low = mid + 1;
		}
		else
			return 1;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
int N, M;
	int* list1;
	int* list2;
cin >> N;
	list1 = (int*)malloc(sizeof(int) * N);

	

	for (int i = 0; i < N; i++) {
		cin >> list1[i];
	}

	cin >> M;
	list2 = (int*)malloc(sizeof(int) * M);
	for (int i = 0; i < M; i++) {
		cin >> list2[i];
	}

	sort(list1, list1 + N);

	for (int i = 0; i < M; i++) {
		int A = binary_Serch(list1, N, list2[i]);
		cout << A << " ";
	}
}
