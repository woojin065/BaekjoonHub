#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    while (n--) {
        int m;
        cin >> m;

        multiset<long long> arr;
        while (m--) {
            char c;
            long long temp;
            cin >> c >> temp;

            if (c == 'I') {
                arr.insert(temp);
            }
            else {
                if (!arr.empty()) {
                    if (temp == 1) {
                        arr.erase(prev(arr.end()));
                    } else {
                        arr.erase(arr.begin());
                    }
                }
            }
        }
        
        if (arr.empty()) {
            cout << "EMPTY" << "\n";
        }
        else {
            cout << *(prev(arr.end())) << " " << *(arr.begin()) << "\n";
        }
    }

    return 0;
}
