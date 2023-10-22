#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string s; 
    string bomb; 
    string t = "";  
    cin >> s >> bomb;
    int s_len = s.length();
    int b_len = bomb.length();
    for (int i = 0; i < s_len; i++)
    {
        t += s[i];
        if (t.length() >= b_len) {
            bool flag = true; 
            for (int j = 0; j < b_len; j++) {
                if (t[t.length() - b_len + j] != bomb[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) 
                t.erase(t.end() - b_len, t.end());
        }
    }
    if (t.empty())
        cout << "FRULA" << '\n';
    else
        cout << t << '\n';
    return 0;
}