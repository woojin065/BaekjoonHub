#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int n) {
    long long answer = 0;
    
    long long arr[2001];
    arr[1]=1;
    arr[2]=2;
    arr[3]=3;
    for(int i=4;i<=n;i++){
        arr[i]=(arr[i-1]+arr[i-2])%1234567;
    }
    answer=arr[n];
    
    return answer;
}