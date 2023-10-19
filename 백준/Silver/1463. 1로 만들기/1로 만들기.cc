#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int main() {
	int n, m=0;
	cin >> n;
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	while (q.front().first!=1) {
		n = q.front().first;
		m = q.front().second + 1;
		if (n % 3 == 0) {
			q.push(make_pair(n / 3, m));
		}
		if (n % 2 == 0) {
			q.push(make_pair(n / 2, m));
		}
		q.push(make_pair(n - 1, m));
		q.pop();
	}
	cout << q.front().second;
}
