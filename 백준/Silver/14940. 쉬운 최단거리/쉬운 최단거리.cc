#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                q.push(make_pair(i, j));
            }
        }
    }

    int di[4] = { 0, 1, 0, -1 };
    int dj[4] = { 1, 0, -1, 0 };

    while (!q.empty()) {
        int temp = arr[q.front().first][q.front().second];
        for (int d = 0;d < 4;d++) {
            int x = q.front().first + di[d];
            int y = q.front().second + dj[d];
            if (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] == 1) {
                q.push(make_pair( x, y ));
                arr[x][y] = temp + 1;
            }
        }
        q.pop();
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            printf("%d ", arr[i][j] == 0 ? 0 : arr[i][j] - 2);
        }
        printf("\n");
    }

}