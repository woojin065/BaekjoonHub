#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<bool> isPrime(m + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= m; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= m; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = n; i <= m; ++i) {
        if (isPrime[i]) {
            printf("%d\n", i);
        }
    }

    return 0;
}
