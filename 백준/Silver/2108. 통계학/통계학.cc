#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main () {
    int n;
    int minval = 4000, maxval = -4000;
    int maxElem;
    double avg = 0;
    vector<int> numCount(8001);
    cin >> n;
    int * arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
        avg += arr[i]; 
        maxval = max(maxval, arr[i]); 
        minval = min(minval, arr[i]); 
        numCount[arr[i] + 4000]++;
    }

    avg /= n;

    sort(arr, arr + n); 

    auto maxIndex = max_element(numCount.begin(), numCount.end()); 
    auto maxIndex1 = max_element(maxIndex+1, numCount.end());
    if (*maxIndex != *maxIndex1) 
        maxElem = (int)(maxIndex - numCount.begin()) - 4000; 
    else
        maxElem = (int)(maxIndex1 - numCount.begin()) - 4000; // 그 다음 최빈값의 위치로 동일한 과정.
    
    cout << (int)round(avg) << '\n'; 
    cout << arr[n / 2] << '\n'; 
    cout << maxElem << '\n';  
    cout << maxval - minval << '\n';
}
