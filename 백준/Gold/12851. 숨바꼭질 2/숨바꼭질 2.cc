#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    queue<pair<int, int>> q;
    vector<bool> visited(100001, false);
    vector<int> time(100001, 0);
    vector<int> path(100001, 0);

    q.push({N, 0});
    visited[N] = true;
    path[N] = 1;

    while (!q.empty()) {
        int current = q.front().first;
        int t = q.front().second;
        q.pop();

        vector<int> nextPos = {current + 1, current - 1, current * 2};

        for (int next : nextPos) {
            if (next >= 0 && next <= 100000) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, t + 1});
                    time[next] = t + 1;
                    path[next] = path[current];
                } else if (time[next] == t + 1) {
                    path[next] += path[current];
                }
            }
        }
    }

    cout << time[K] << "\n";
    cout << path[K] << "\n";

    return 0;
}
