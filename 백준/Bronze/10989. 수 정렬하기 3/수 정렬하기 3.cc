#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(10001, 0);
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        v[temp]++;
    }
    for(int i=0;i<10001;i++){
        for(int j=0;j<v[i];j++){
            cout << i << "\n";
        }
    }
}