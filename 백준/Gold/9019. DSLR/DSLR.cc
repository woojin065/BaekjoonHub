#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>


using namespace std;

int D(int n) { return (2 * n) % 10000; }
int S(int n) { return n - 1 < 0 ? 9999 : n - 1; }
int L(int n) { return n / 1000 + (n % 1000) * 10; }
int R(int n) { return n / 10 + (n % 10) * 1000; }

void dfs(int f, int* e) {
	bool visit[10000];
	memset(visit, false, sizeof(visit));
	queue<pair<int, string>> q;
	q.push(make_pair(f, ""));
	visit[f] = true;

	while (!q.empty()) {
		int num = q.front().first;
		string str = q.front().second;
		q.pop();

		if (num == *e) {
			cout << str << "\n";
			return;
		}
		int d = D(num), s = S(num), l = L(num), r = R(num);
		if (!visit[d]) {
			visit[d] = true;
			q.push(make_pair(d, str + "D"));
		}
		if (!visit[s]) {
			visit[s] = true;
			q.push(make_pair(s, str + "S"));
		}
		if (!visit[l]) {
			visit[l] = true;
			q.push(make_pair(l, str + "L"));
		}
		if (!visit[r]) {
			visit[r] = true;
			q.push(make_pair(r, str + "R"));
		}
	}
}

int main() {
    int n;
    cin >> n;
	while (n--)	{
		int f, e;
		cin >> f >> e;
		dfs(f, &e);
	}
}
