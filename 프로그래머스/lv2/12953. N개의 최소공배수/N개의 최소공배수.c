#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int maxlv(int a, int b){
    if(a%b==0)
        return b;
    else
        return maxlv(b, a%b);
}
int minlv(int a, int b){
    int lv=a>b?maxlv(a, b):maxlv(b, a);
    a=a/lv;
    b=b/lv;
    
    return a*b*lv;
}
int solution(int arr[], size_t arr_len) {
    int answer = 1;
    
    for(int i=0;i<arr_len;i++){
        answer=minlv(answer, arr[i]);
    }
    
    
    return answer;
}