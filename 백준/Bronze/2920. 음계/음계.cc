#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int arr[8];
	for (int i = 0; i < 8; i++) {
		scanf("%d", &arr[i]);
	}
	int an[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int pn[8] = { 8, 7, 6, 5, 4, 3, 2, 1 };

	int flag = 1;
	for (int i = 0; i < 8; i++) {
		if (an[i] != arr[i]) {
			flag = -1;
			break;
		}
	}
	if (flag != 1) {
		for (int i = 0; i < 8; i++) {
			if (pn[i] != arr[i]) {
				flag = -1;
				break;
			}
			if (i == 7) {
				flag = 0;
			}
		}
	}
	if (flag == -1) {
		cout << "mixed";
	}
	else if (flag == 1) {
		cout << "ascending";
	}
	else {
		cout << "descending";
	}
}