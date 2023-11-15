#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int main(void) {
	int n, arr[501][501];
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < i + 1;j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1;i < n;i++) {
		for (int j = 0;j < i + 1;j++) {
			if (j == 0) {
				arr[i][j] += arr[i - 1][j];
			}
			else if (j == i) {
				arr[i][j] += arr[i - 1][j - 1];
			}
			else {
				arr[i][j] += max(arr[i - 1][j], arr[i - 1][j - 1]);
			}
		}
	}
	int mx = 0;
	for (int i = 0;i < n;i++) {
		mx = arr[n - 1][i] < mx ? mx : arr[n - 1][i];
	}
	cout << mx;
}