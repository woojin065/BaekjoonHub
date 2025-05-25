#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main() {
    int T;
    cin >> T;
    while(T--){
        string str;
        cin >> str;
        cout<<str[0]<<str[str.length()-1]<<"\n";
    }
}