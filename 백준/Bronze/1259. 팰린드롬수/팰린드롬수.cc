#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char arr[99999];
    
    while (true) {
        cin >> arr;
        
        if (arr[0] == '0') break;
        
        int len = strlen(arr);
        bool isPel = true; // 여기에서 초기화합니다.

        for(int i = 0; i < len/2; i++) { // for 루프를 사용해 코드를 간소화합니다.
            if (arr[i] != arr[len - 1 - i]) {
                isPel = false;
                break;
            }
        }

        if (isPel) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
