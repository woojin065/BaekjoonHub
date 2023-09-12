#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int compare(int a, int b) {
	return a < b;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	vector<int> arr;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < n; i++)
		cout << arr[i] << '\n';
}
