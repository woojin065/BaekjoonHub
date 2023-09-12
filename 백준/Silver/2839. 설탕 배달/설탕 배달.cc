#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int bagsOf5 = N / 5;
    while (bagsOf5 >= 0) {
        int remaining = N - bagsOf5 * 5;
        if (remaining % 3 == 0) {
            cout << bagsOf5 + (remaining / 3) << '\n';
            return 0;
        }
        bagsOf5--;
    }
    cout << -1 << '\n';
    return 0;
}
