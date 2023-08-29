#include <iostream>

using namespace std;

char a[50][50];
char p[2] = { 'W', 'B' };
int x, y;
int ch(int x1, int y1, int k) {
    int answer = 0;
    for (int i = x1; i < x1+8; i++) {
        for (int j = y1; j < y1+8; j++) {
            if (p[k] != a[i][j])
                answer++;
            k = (k + 1) % 2;
        }
        k = (k + 1) % 2;
    }
    return answer;
}
int main()
{
    int answer = 64;
    cin >> x;
    cin >> y;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < x - 7; i++) {
        for (int j = 0; j < y - 7; j++) {
            int n = ch(i, j, 0), m = ch(i, j, 1);
            n = n < m ? n : m;
            answer = n < answer ? n : answer;
        }
    }
    cout << answer;
}
