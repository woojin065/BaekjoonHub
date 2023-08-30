#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> arr;
	string temp;
	cin >> temp;
	while(temp!="0") {
		arr.push_back(temp);
		cin >> temp;
	}
	for (int i = 0; i < arr.size(); i++) {
		temp = arr[i];
		reverse(arr[i].begin(), arr[i].end());
		if (arr[i] == temp)
			arr[i] = "yes";
		else
			arr[i] = "no";
	}
	for (const string& answer : arr) {
		cout << answer << endl;
	}

}
