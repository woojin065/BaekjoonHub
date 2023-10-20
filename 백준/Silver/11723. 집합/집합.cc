#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	bool arr[21] = { 0, };
	while (T--) {
		char s[10];
		int n;
		scanf("%s", s);
		if (s[1] == 'd') {
			scanf("%d", &n);
			arr[n] = true;
		}
		if (s[0] == 'r') {
			scanf("%d", &n);
			arr[n] = false;
		}
		if (s[0] == 'c') {
			scanf("%d", &n);
			printf("%d\n", arr[n]);
		}
		if (s[0] == 't') {
			scanf("%d", &n);
			arr[n] = !arr[n];
		}
		if (s[1] == 'l') {
			fill(begin(arr), end(arr), true);
		}
		if (s[0] == 'e') {
			fill(begin(arr), end(arr), false);
		}
	}
}
