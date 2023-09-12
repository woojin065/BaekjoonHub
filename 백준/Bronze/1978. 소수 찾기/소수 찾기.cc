#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, temp, ans=0;
	cin >> n;
	while (n--) {
		cin >> temp;
		if(temp!=1)
			ans++;
		for (int i = 2; i < temp; i++)
			if (temp % i == 0) { 
				ans--;
				break;
			}
	}
	cout << ans << endl;
}
