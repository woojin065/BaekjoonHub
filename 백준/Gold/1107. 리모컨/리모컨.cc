#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
bool arr[10] = { 0, };
int p(int n) {
	if (n == 0) {
		if (arr[n]) {
			return 0;
		}
		else {
			return 1;
		}
	}
	int len = 0;
	while (n > 0) {
		if (arr[n % 10]) {
			return 0;
		}
		len += 1;
		n /= 10;
	}
	return len;
}
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		int temp;
		cin >> temp;
		arr[temp] = true;
	}

	int ans = abs(N - 100);

	for (int i = 0;i <= 1000000;i++) {
		int x = i;
		int len = p(x);
		if (len > 0) {
			int press = abs(x - N);
			if (ans > len + press) {
				ans = len + press;
			}
		}
	}
	cout << ans;
}
