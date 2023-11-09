#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int v[10];
vector<int> pr(10);
bool visit[10] = { 0, };
int len = 0;
void con(int n, int m, int k) {
	if (m<=0) {
		for (int i = 0;i < len;i++) {
			printf("%d ", pr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = k;i < n;i++) {
		if (!visit[i]) {
			pr[len++] = v[i];
			visit[i] = 1;
			con(n, m - 1, 0);
			visit[i] = 0;
			len--;
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}
	sort(v, v+n);
	con(n, m, 0);
}