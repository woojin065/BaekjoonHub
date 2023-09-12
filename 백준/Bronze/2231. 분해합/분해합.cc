#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int temp = i, sum = i;
		while (temp > 0) {
			sum += temp % 10;
			temp /= 10;
		}
		if (n == sum) {
			ans = i;
			break;
		}
	}
	cout << ans << endl;
}
