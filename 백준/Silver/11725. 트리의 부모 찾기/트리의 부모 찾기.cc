#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int arr[100001];
bool visit[100001];
vector<int> v[100001];

void dfs(int k) {
    visit[k] = true;
    for (int i = 0;i < v[k].size();i++) {
        int next = v[k][i];
        if (!visit[next]) {
            arr[next] = k;
            dfs(next);
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0;i < n;i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1);

    for (int i = 2;i <= n;i++) {
        cout << arr[i] << "\n";
    }
}