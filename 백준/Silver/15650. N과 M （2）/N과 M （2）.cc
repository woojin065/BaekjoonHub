#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> v(10);
int len = 0;
void con(int n, int m, int k) {
	if (m<=0) {
		for (int i = 0;i < len;i++) {
			printf("%d ", v[i]);
		}
		printf("\n");
		return;
	}
	for (int i = k;i <= n;i++) {
		v[len++] = i;
		con(n, m-1, i+1);
		len--;
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	con(n, m, 1);
}