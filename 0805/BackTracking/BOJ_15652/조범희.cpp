#include <iostream>
#include <vector>
using namespace std;

vector<int> res;
bool visited[8] = { false, };
int arr[8];
int N, M;

bool check() {
	for (int i = 0; i < res.size() - 1; i++) {
		if (res[i] > res[i + 1])
			return false;
	}
	return true;
}

void dfs(int cnt) {
	if (cnt == M) {
		if (check() == true) {
			for (int i = 0; i < res.size(); i++)
				cout << res[i] << " ";
			cout << endl;
			return;
		}
		else return;
	}

	for (int i = 0; i < N; i++) {
		res.push_back(arr[i]);
		dfs(cnt + 1);
		res.pop_back();
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		arr[i] = i + 1;
	}
	dfs(0);
}
