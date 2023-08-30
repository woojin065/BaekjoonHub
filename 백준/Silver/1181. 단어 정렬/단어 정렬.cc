#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
	if (a.length() != b.length()) {   //이름이 같으면, 나이가 적은순
		return a.length() < b.length();
	}
	else {                  //이름 다르면, 이름 사전순
		return a < b;
	}

}
int main()
{
	vector<string> arr;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end(), compare);
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
    for (const auto& word : arr) {
        cout << word << endl;
    }

}
