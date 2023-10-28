#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int pac = 1;
	for(int i=1;i<=n;i++){
		pac*=i;
	}
	cout<<pac;
	return 0;
}