#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}
	vector<int> len(n, 1);
	for (int i = 0;i < n;i++) {
		int max_p = i;
		for (int j = i - 1;j >= 0;j--) {
			if (len[max_p] <= len[j] && v[i]>v[j]) {
				max_p = j;
			}
		}
		if (max_p != i) {
			len[i] += len[max_p];
		}
	}
	int max = 0;
	for (int i = 0;i < n;i++) {
		max = max > len[i] ? max : len[i];
	}
	cout << max;
}