#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
	char arr[101];
	scanf("%s", arr);
	int alpa[26];
	for (int i = 0;i < 26;i++) {
		alpa[i] = -1;
	}
	for (int i = 0;arr[i] != '\0';i++) {
		if(alpa[arr[i]-'a']==-1)
			alpa[arr[i] - 'a'] = i;
	}
	for (auto x : alpa) {
		cout << x << " ";
	}
}