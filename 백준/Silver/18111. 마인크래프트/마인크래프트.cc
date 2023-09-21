#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, b;
int ch(vector<vector<int>>& arr, int hight) {
    int crash = 0, add = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int diff = arr[i][j] - hight;
            if (diff > 0)
                crash+=diff;
            if (diff < 0)
                add-=diff;
        }
    }
    if (crash + b < add) {
        return 2000000000;
    }
    return add + crash * 2;
}

int main() {
    cin >> n >> m >> b;
    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int time = 2000000000, hight=0;
    for (int i = 0; i <= 256; i++) {
        int time_i = ch(arr, i);
        if (time >= time_i) {
            time = time_i;
            if(hight<i)
            hight = i;
        }
    }
    cout << time << " " << hight << endl;
}
