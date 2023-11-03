#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	int max = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				int temp = v[i]+v[j]+v[k];
				if(max < temp && temp <= m){
					max=temp;
				}
			}
		}
	}
	cout << max;
	return 0;
}