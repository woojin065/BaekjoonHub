#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main() {
    int arr[31]={0, };
    for(int i=1;i<=28;i++){
        int N;
        cin >> N;
        arr[N]=1;
    }
    for(int i=1;i<=30;i++)
        if(!arr[i])
            cout << i << "\n";
}