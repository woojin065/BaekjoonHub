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
	cin >> s;

	stack<char> op;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            cout << s[i];
        }
        else
        {
            if (s[i] == '(')
                op.push(s[i]);
            else if (s[i] == '*' || s[i] == '/')
            {
                while (!op.empty() && (op.top() == '*' || op.top() == '/'))
                {
                    cout << op.top();
                    op.pop();
                }
                op.push(s[i]);
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                while (!op.empty() && op.top() != '(')
                {
                    cout << op.top();
                    op.pop();
                }
                op.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (!op.empty() && op.top() != '(')
                {
                    cout << op.top();
                    op.pop();
                }
                op.pop();
            }
        }
    }
    while (!op.empty())
    {
        cout << op.top();
        op.pop();
    }
	
}
