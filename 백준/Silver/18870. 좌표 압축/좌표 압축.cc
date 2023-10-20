#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v(n), ranks(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}
	vector<int> sorted_v = v;
	sort(sorted_v.begin(), sorted_v.end());

	sorted_v.erase(unique(sorted_v.begin(), sorted_v.end()), sorted_v.end());

	for (int i = 0; i < n; ++i) {
		ranks[i] = lower_bound(sorted_v.begin(), sorted_v.end(), v[i]) - sorted_v.begin();
	}

	for (auto x : ranks) {
		cout << x << " ";
	}
}
