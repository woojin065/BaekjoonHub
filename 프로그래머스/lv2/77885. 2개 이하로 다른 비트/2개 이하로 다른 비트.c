#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int ch(long long n){
    long long a = 1;
    for(int i=0;i<64;i++){
        if((n&a)!=a)
            return i;
        a*=2;
    }
}
// numbers_len은 배열 numbers의 길이입니다.
long long* solution(long long numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    long long* answer = (long long*)malloc(sizeof(long long)*numbers_len);
    int len=0;
    for(int i=0;i<numbers_len;i++){
        int k= ch(numbers[i]);
        long long a = 1;
        for(int j=1;j<k;j++)
            a*=2;
        answer[len++]=numbers[i]+a;    
    }
    return answer;
}