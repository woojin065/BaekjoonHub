#include <iostream>
using namespace std;

int main() {
	long long n, m;
	cin >> n >> m;
	long long ans = n-m<0?(n-m)*-1:n-m;
	cout << ans;
	return 0;
}