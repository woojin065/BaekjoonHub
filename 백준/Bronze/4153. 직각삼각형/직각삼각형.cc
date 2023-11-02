#include <iostream>
using namespace std;
bool check(int a, int b, int c){
	if(a*a==b*b+c*c)
		return true;
	return false;
}
int main() {
	long long arr[3];
	for(int i=0;i<3;i++)
		cin >> arr[i];
	while(arr[0]!=0){
		if(arr[0]>=arr[1]){
			if(arr[0]>=arr[2]){
				if(check(arr[0], arr[1], arr[2])){
					cout<<"right\n";
				}
				else{
					cout<<"wrong\n";
				}
			}
			else{
				if(check(arr[2], arr[1], arr[0])){
					cout<<"right\n";
				}
				else{
					cout<<"wrong\n";
				}
			}
		}
		else{
			if(arr[1]>=arr[2]){
				if(check(arr[1], arr[0], arr[2])){
					cout<<"right\n";
				}
				else{
					cout<<"wrong\n";
				}
			}
			else{
				if(check(arr[2], arr[1], arr[0])){
					cout<<"right\n";
				}
				else{
					cout<<"wrong\n";
				}
			}
		}
		for(int i=0;i<3;i++)
			cin >> arr[i];
	}
	return 0;
}