#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    
    int a[3]={0,1,1};
    for(int i=2;i<=n;i++){
        a[i%3]=(a[(i-1)%3]+a[(i-2)%3])%1234567;
    }   
    answer=a[n%3];
    return answer;
}