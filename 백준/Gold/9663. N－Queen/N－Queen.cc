#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int col[15];
int N, total = 0;
bool check(int lev) {
    for (int i = 0;i < lev;i++) {
        if (col[i] == col[lev] || abs(col[lev] - col[i]) == lev - i)
            return false;
    }
    return true;
}
void nqueen(int x) {
    if (x == N) {
        total++;
        return;
    }
    for (int i = 0;i < N;i++) {
        col[x] = i;
        if (check(x))
            nqueen(x + 1);
    }
}
int main() {
    cin >> N;
    nqueen(0);
    cout << total;
}