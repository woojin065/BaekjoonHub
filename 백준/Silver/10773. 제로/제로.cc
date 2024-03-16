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
	int sum = 0;
	while (n--) {
		int temp;
		cin >> temp;
		if (temp == 0) {
			sum -= st.top();
			st.pop();
		}
		else {
			st.push(temp);
			sum += temp;
		}
	}
	cout << sum;
}