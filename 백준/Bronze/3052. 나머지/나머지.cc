#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;


int main() {
	vector<int> v(10);
	for (int i = 0;i < 10;i++) {
		int temp;
		cin >> temp;
		v[i] = temp % 42;
	}
	int cnt[42] = { 0, };

	for (int i = 0;i < 10;i++) {
		cnt[v[i]] = 1;
	}
	int ans = 0;
	for (int i = 0;i < 42;i++) {
		if (cnt[i] == 1) {
			ans++;
		}
	}
	cout << ans;
	
}