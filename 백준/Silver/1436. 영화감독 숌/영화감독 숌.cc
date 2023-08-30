#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k, m=0;
	cin >> n;
	for(int i=1;;i++){
		int temp = i;
		k = 0;
		while (temp > 0) {
			if (temp % 10 == 6)
				k++;
			else
				k = 0;
			if (k == 3) {
				m++;
				break;
			}
			temp /= 10;
		}
		if (m == n) {
			cout << i << endl;
			break;
		}
	}

}
