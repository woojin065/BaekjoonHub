#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int H, W, N;
		cin >> H >> W >> N;
		int floor = (N % H == 0) ? H : N % H;
		int room = (N % H == 0) ? N / H : N / H + 1;

		if (room < 10)
			cout << floor << '0' << room << '\n';
		else
			cout << floor << room << '\n';
	}
	return 0;
}