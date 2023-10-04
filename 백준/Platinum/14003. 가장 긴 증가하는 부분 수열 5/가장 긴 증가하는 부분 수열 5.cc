#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> lis;
    vector<int> idx(n, -1);
    vector<int> prev(n, -1);

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
        int position = distance(lis.begin(), it);

        if (it == lis.end())
            lis.push_back(arr[i]);
        else
            *it = arr[i];

        idx[position] = i;

        if (position > 0)
            prev[i] = idx[position - 1];

    }

    cout << lis.size() << "\n";

    int lastIndex = idx[lis.size() - 1];
    vector<int> ans;
    while (lastIndex != -1) {
        ans.push_back(arr[lastIndex]);
        lastIndex = prev[lastIndex];
    }
    reverse(ans.begin(), ans.end());
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
