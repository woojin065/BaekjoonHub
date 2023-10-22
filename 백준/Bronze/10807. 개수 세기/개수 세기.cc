#include <iostream>
using namespace std;

int main() {
	int arr[101];
	int n;
	cin >>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int v, con=0;
	cin >> v;
	for(int i=0;i<n;i++){
		if(arr[i]==v)
			con++;
	}
	cout << con;
	return 0;
}