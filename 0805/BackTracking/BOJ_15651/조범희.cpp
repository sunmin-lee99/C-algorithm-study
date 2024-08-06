#include<iostream>
#include<vector>

using namespace std;

int N, M;
vector<int> V;

void DFS(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < V.size(); i++) {
			cout << V[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		V.push_back(i + 1);
		DFS(cnt + 1);
		V.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	DFS(0);
}
