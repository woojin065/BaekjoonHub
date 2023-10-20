#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int p(int n) {
	int dp[1001];
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3;i <= n;i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 10007;
	}
	return dp[n];
}
int main() {
	int n;
	cin >> n;
	cout << p(n);
}
