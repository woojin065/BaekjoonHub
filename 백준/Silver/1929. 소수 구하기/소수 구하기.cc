#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = n; i <= m; i++) {
		int flag = 1;
		if (i == 1)continue;
		for (int j = 2; j <= sqrt((double)i); j++) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}
		if (flag || i==2 )
			printf("%d\n", i);
	}
}
