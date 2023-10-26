#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		string s;
		int k = 1, ans = 0;
		cin >> s;
		for (auto x : s){
			if (x == 'O') {
				ans += k;
				k++;
			}
			else {
				k = 1;
			}
		}
		cout << ans << endl;
	}
}