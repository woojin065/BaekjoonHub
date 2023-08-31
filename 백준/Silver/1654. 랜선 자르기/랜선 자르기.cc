#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, ans=0;
	int arr[10001], max = 0;
	long long mi, l, h;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		max = max < arr[i] ? arr[i] : max;
	}
	l = 1;
	h = max;
	while (l<=h) {
		mi = (l + h) / 2;
		int k = 0;
		for (int i = 0; i < n; i++)
			k += arr[i] / mi;
		if (k >= m) {
			l = mi + 1;
			if (ans < mi) ans = mi;
		}
		else
			h = mi - 1;
	}
	cout << ans << endl;
}
