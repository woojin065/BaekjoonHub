#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		string command;
		cin >> command;

		int n;
		cin >> n;

		deque<int> arr;
		getchar();
		getchar();

		for (int i = 0; i < n; ++i) {
			int number;
			scanf("%d", &number);
			arr.push_back(number);

			if (i < n - 1) {
				getchar();
			}
		}
		getchar();

		bool isReversed = false;
		bool isError = false;
		for (auto& cmd : command) {
			if (cmd == 'R')
				isReversed = !isReversed;
			if (cmd == 'D') {
				if (arr.empty()) {
					isError = true;
					cout << "error" << endl;
					break;
				}
				if (isReversed) {
					arr.pop_back();
				}
				else {
					arr.pop_front();
				}
			}
		}

		if (!isError) {
			if (isReversed)
				reverse(arr.begin(), arr.end());
			cout << "[";
			for (int i = 0; i < arr.size();i++) {
				cout << arr[i];
				if (i != arr.size() - 1) {
					cout << ",";
				}
			}
			cout << "]" << endl;
		}
	}
}
