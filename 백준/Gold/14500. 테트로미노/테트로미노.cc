#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m;
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };
int mmax = 0;
int v[501][501] = { 0, };
bool vi[501][501] = { 0, };
void dfs(int depth, int sum, int i, int j) {
	if (depth == 3) {
		mmax = mmax < sum ? sum : mmax;
		return;
	}
	for (int d = 0;d < 4;d++) {
		if (0 <= i + di[d] && 0 <= j + dj[d] &&
			n > i + di[d] && m > j + dj[d]&& !vi[i + di[d]][j + dj[d]]) {
			vi[i + di[d]][j + dj[d]] = true;
			dfs(depth + 1, sum + v[i + di[d]][j + dj[d]], i + di[d], j + dj[d]);
			vi[i + di[d]][j + dj[d]] = false;
		}
	}
}
void dfsh(int i, int j) {
	for (int d = 0;d < 4;d++) {
		if (0 <= i + di[d] && 0 <= j + dj[d] &&
			n > i + di[d] && m > j + dj[d]) {
			int temp = v[i][j] + v[i + di[d]][j + dj[d]];
			for (int h = 0;h < 4;h++) {
				if ((d + 2) % 4 == h)continue;
				if (0 <= i + di[h] + di[d] && 0 <= j + dj[h] + dj[d] &&
					n > i + di[h] + di[d] && m > j + dj[h] + dj[d]) {
					for (int k = 0;k < 4;k++) {
						if (h == k || (d + 2) % 4 == k)continue;
						if (0 <= i + di[k] + di[d] && 0 <= j + dj[k] + dj[d] &&
							n > i + di[k] + di[d] && m > j + dj[k] + dj[d]) {
							int t1 = temp + v[i + di[h] + di[d]][j + dj[h] + dj[d]] + v[i + di[k] + di[d]][j + dj[k] + dj[d]];
							mmax = t1 > mmax ? t1 : mmax;
						}
					}
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			scanf("%d", &v[i][j]);
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			vi[i][j] = true;
			dfs(0, v[i][j], i, j);
			vi[i][j] = false;
			dfsh(i, j);
		}
	}
	cout << mmax;
}
