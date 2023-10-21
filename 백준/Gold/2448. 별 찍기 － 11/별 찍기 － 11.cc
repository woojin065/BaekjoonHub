#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int n;
void ck(vector<vector<bool>>& v, int x, int y, int dep) {
	if (dep==0) {
		v[x][y] = true;
		v[x + 1][y + 1] = true;
		v[x + 1][y - 1] = true;
		for (int i = 0;i < 5;i++)
			v[x + 2][y - 2 + i] = true;
		return;
	}
	ck(v, x, y, dep / 2);
	ck(v, x + 3 * dep, y + 3 * dep, dep / 2);
	ck(v, x + 3 * dep, y - 3 * dep, dep / 2);
}
int main() {
	cin >> n;
	int x = n;
	int y = (n / 3) * 5;
	if(n!=3) y += (n / 3) - 1;
	n /= 3;
	vector<vector<bool>> v(x, vector<bool>(y, false));

	ck(v, 0, y / 2, n / 2);

	for (int i = 0;i < x;i++) {
		for (int j = 0;j < y;j++) {
			if (v[i][j])
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}
