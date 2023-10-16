#include <iostream>
#include <queue>
#include <set>
#include <stdio.h>

using namespace std;
char arr[2][101][101];
int n;

int di[4] = { 0, 1, 0, -1 };
int dj[4] = { 1, 0, -1, 0 };

void dfs(int x, int y, char temp, int p) {
    for (int d = 0;d < 4;d++) {
        if (x + di[d] >= 0 && x + di[d] < n && y + dj[d] >= 0 && y + dj[d] < n) {
            if (temp == arr[p][x + di[d]][y + dj[d]]) {
                arr[p][x + di[d]][y + dj[d]] = 'k';
                dfs(x + di[d], y + dj[d], temp, p);
            }
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        scanf("%s", arr[0][i]);
        for (int j = 0;j < n;j++) {
            arr[1][i][j] = arr[0][i][j] == 'G'?'R':arr[0][i][j];
        }
    }

    int t[2] = { 0, };
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            for (int p = 0;p < 2;p++) {
                if (arr[p][i][j] != 'k') {
                    dfs(i, j, arr[p][i][j], p);
                    t[p]++;
                }
            }
        }
    }
    cout<<t[0]<<" "<<t[1];

}
