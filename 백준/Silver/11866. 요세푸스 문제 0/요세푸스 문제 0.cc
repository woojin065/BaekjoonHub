#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cout << '<';

    vector<pair<int, bool>> arr;
    for (int i = 1; i <= n; i++) {
        arr.push_back({i, false});
    }

    for (int i = 0, k = -1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            k = (k + 1) % n;
            while (arr[k].second) {
                k = (k + 1) % n;
            }
        }
        arr[k].second = true;
        cout << arr[k].first;
        if (i != n - 1) {
            cout << ", ";
        }
    }

    cout << '>';
    return 0;
}
