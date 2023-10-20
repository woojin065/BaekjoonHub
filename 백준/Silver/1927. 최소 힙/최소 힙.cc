#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	priority_queue<int, vector<int>, greater<int>> p_queue;
	while (n--) {
		int temp;
		scanf("%d", &temp);

		if (temp == 0) {
			if (p_queue.empty()) {
				printf("0\n");
			}
			else {
				printf("%d\n", p_queue.top());
				p_queue.pop();
			}
		}
		else {
			p_queue.push(temp);
		}
	}
}
