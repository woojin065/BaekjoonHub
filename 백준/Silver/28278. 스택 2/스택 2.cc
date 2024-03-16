#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	stack<int> st;
	while (n--) {
		int m;
		cin >> m;
		if (m == 1) {
			int temp;
			cin >> temp;
			st.push(temp);
		}
		if (m == 2) {
			if (!st.empty()) {
				cout << st.top() << "\n";
				st.pop();
			}
			else {
				cout << -1 << "\n";
			}
		}
		if (m == 3) {
			cout << st.size() << "\n";
		}
		if (m == 4) {
			cout << st.empty() << "\n";
		}
		if (m == 5) {
			if (!st.empty()) {
				cout << st.top() << "\n";
			}
			else {
				cout << -1 << "\n";
			}
		}
	}
}