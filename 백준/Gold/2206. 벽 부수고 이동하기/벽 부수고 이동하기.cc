#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int r, c;
int visit[1000][1000][2];
int bfs(vector<string>& v) {
    queue<pair<pair<int, int>, int>> q;
    q.push({ {0,0},1 });
    visit[0][0][1] = 1;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int b = q.front().second;
        q.pop();

        if (x == r - 1 && y == c - 1) {
            return visit[x][y][b];
        }

        for (int i = 0; i < 4; i++) {
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if (dx >= 0 && dx < r && dy >= 0 && dy < c) {
                if (v[dx][dy] == '1' && b) {
                    q.push({ {dx,dy} ,0 });
                    visit[dx][dy][b - 1] = visit[x][y][b] + 1;
                }
                else if (v[dx][dy] == '0' && visit[dx][dy][b] == 0) {
                    q.push({ {dx,dy},b });
                    visit[dx][dy][b] = visit[x][y][b] + 1;
                }
            }
        }

    }
    return -1;

}

int main() {
    cin >> r >> c;
    vector<string> v(r);
    for (int i = 0; i < r; i++) {
        cin >> v[i];
    }
    cout << bfs(v);
    return 0;
}