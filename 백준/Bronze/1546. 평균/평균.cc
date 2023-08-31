#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, arr[1000], max=0;
	double sum=0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		max = max < arr[i] ? arr[i] : max;
	}
	for (int i = 0; i < n; i++) {
		sum += (double)arr[i] / max * 100;

	}
	cout << sum/n << endl;
}
