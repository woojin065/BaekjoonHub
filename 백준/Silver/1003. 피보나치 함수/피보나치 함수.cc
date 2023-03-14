#include <iostream>
#include <vector>
using namespace std;

int arr[41][2];
//0 1 1 2 3 5 
void fibo(int n){
  arr[0][0]=1;
  arr[0][1]=0;
  arr[1][0]=0;
  arr[1][1]=1;
  for(int i=2;i<=n;i++){
    arr[i][0]=arr[i-1][0]+arr[i-2][0];
    arr[i][1]=arr[i-1][1]+arr[i-2][1];
  }
}
int main() {
	int n;
	cin >> n;

	int max = 0;
	vector<int> p(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		max = max < p[i] ? p[i] : max;
	}

  fibo(max);
	for (int i = 0; i < n; i++) {
    cout<<arr[p[i]][0]<<" "<<arr[p[i]][1]<<endl;
	}
}