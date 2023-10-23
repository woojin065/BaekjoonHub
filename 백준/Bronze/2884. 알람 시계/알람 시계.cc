#include <iostream>
using namespace std;

int main() {
	int h, m;
	cin >>h>>m;
	int al = h*60+m-45+24*60;
	cout << (al/60)%24<<" "<<al%60;
}