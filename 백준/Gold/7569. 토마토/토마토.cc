#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int n, m, h;
	cin >> m >> n >> h;
	int*** arr = new int** [h];
	for (int i = 0; i < h; i++) {
		arr[i] = new int* [n];
		for (int j = 0; j < n; j++) {
			arr[i][j] = new int[m];
		}
	}
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[k][i][j];
			}
		}
	}

	queue<pair<int, pair<int, int>>> q;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[k][i][j] == 1) {
					q.push(make_pair(k, make_pair(i, j)));
				}
			}
		}
	}
	int temp = 0;
	while (1) {
		int ch = q.size();
		while (ch--) {
			pair<int, pair<int, int>> temp_one = q.front();
			int i = temp_one.second.first;
			int j = temp_one.second.second;
			int k = temp_one.first;
			if (i + 1 < n && arr[k][i + 1][j] == 0) {
				arr[k][i + 1][j] = 1;
				q.push(make_pair(k, make_pair(i + 1, j)));
			}
			if (i - 1 >= 0 && arr[k][i - 1][j] == 0) {
				arr[k][i - 1][j] = 1;
				q.push(make_pair(k, make_pair(i - 1, j)));
			}
			if (j + 1 < m && arr[k][i][j + 1] == 0) {
				arr[k][i][j + 1] = 1;
				q.push(make_pair(k, make_pair(i, j + 1)));
			}
			if (j - 1 >= 0 && arr[k][i][j - 1] == 0) {
				arr[k][i][j - 1] = 1;
				q.push(make_pair(k, make_pair(i, j - 1)));
			}
			if (k + 1 < h && arr[k + 1][i][j]== 0) {
				arr[k + 1][i][j] = 1;
				q.push(make_pair(k + 1, make_pair(i, j)));
			}
			if (k - 1 >= 0 && arr[k - 1][i][j] == 0) {
				arr[k - 1][i][j] = 1;
				q.push(make_pair(k - 1, make_pair(i, j)));
			}
			q.pop();
		}
		if (q.empty())
			break;
		temp++;
	}

	int flag = 0;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[k][i][j] == 0) {
					flag = 1;
					break;
				}
			}
		}
	}
	if (flag)temp = -1;
	cout << temp;
}
