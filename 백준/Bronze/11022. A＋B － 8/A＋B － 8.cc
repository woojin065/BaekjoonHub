#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main() {
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d + %d = %d\n", i, a, b, a+b);
    }
}