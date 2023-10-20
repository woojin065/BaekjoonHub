#include <iostream>
#include <stdio.h>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
int p(int n, int r, int c) {
	if (n == 0)return 0;
	int N = pow(2, n);
	if (N / 2 < r) {
		if (N / 2 < c) {//4
			return p(n - 1, r - N / 2, c - N / 2) + (N / 2) * (N / 2) * 3;
		}
		else {//3
			return p(n - 1, r - N / 2, c) + (N / 2) * (N / 2) * 2;
		}
	}
	else {
		if (N / 2 < c) {//2
			return p(n - 1, r, c - N / 2) + (N / 2) * (N / 2);
		}
		else {//1
			return p(n - 1, r, c);
		}
	}
}
int main() {
	int n, r, c;
	cin >> n >> r >> c;
	cout << p(n, r + 1, c + 1);
}
