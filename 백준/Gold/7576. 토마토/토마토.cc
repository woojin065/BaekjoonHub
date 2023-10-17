#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> m >> n;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}
	int temp = 0;
	while (1) {
		int ch = q.size();
		while (ch--) {
			pair<int, int> temp_one = q.front();
			int i = temp_one.first;
			int j = temp_one.second;
			if (i + 1 < n && arr[i + 1][j] == 0) {
				arr[i + 1][j] = 1;
				q.push(make_pair(i + 1, j));
			}
			if (i - 1 >= 0 && arr[i - 1][j] == 0) {
				arr[i - 1][j] = 1;
				q.push(make_pair(i - 1, j));
			}
			if (j + 1 < m && arr[i][j + 1] == 0) {
				arr[i][j + 1] = 1;
				q.push(make_pair(i, j + 1));
			}
			if (j - 1 >= 0 && arr[i][j - 1] == 0) {
				arr[i][j - 1] = 1;
				q.push(make_pair(i, j - 1));
			}
			q.pop();
		}
		if (q.empty())
			break;
		temp++;
	}

	int flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				flag = 1;
				break;
			}
		}
	}
	if (flag)temp = -1;
	cout << temp;
}
