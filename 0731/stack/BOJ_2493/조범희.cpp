#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<pair<int, int>> stk;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;

		while (!stk.empty()) {
			int now = stk.top().second;
			int idx = stk.top().first;
			if (now >= tmp) { // 수신 가능
				cout << idx << " ";
				break;
			}
			else {
				stk.pop();
			}
		}
		
		if(stk.empty()){
			cout << 0 << " ";
		}

		stk.push({ i + 1, tmp });
	}
}
