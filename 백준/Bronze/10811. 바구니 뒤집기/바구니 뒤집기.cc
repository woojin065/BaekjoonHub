#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    int arr[101];
    for(int i=1;i<=N;i++)
        arr[i]=i;
    for(int i=0;i<M;i++){
        int a, b;
        cin >>a>>b;
        while(a<=b){
            int temp = arr[a];
            arr[a]=arr[b];
            arr[b]=temp;
            a++;
            b--;
        }
    }
    for(int i=1;i<=N;i++)
        cout << arr[i] << " ";
}