#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
int ans = 0;
void dfs(int n, int max, int time) {
	if (n < 0||time>=ans) {
		return;
	}
	else if (n == 0) {
		ans = ans > time ? time : ans;
	}
	for (int i = 0;i < max;i++) {
		dfs(n - (max - i) * (max - i), max - i, time + 1);
	}
}
int main() {
	int n;
	cin >> n; 
	int max = floor(sqrt(n));
	int m = n;
	while (n > 0) {
		int temp = floor(sqrt(n));
		n -= temp * temp;
		ans++;
	}
	dfs(m, max, 0);
	cout << ans;
}
