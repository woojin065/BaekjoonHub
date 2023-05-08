#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
char* solution(const char* number, int k) {
    int len = strlen(number);
    char* answer = (char*)malloc(sizeof(char) * (len));
    int top = -1, K=k;
    
    for(int i=0;i<len;i++){
        while(answer[top]<number[i]&&top>=0&&k!=0){
            answer[top--]=0;
            k--;
        }
        answer[++top]=number[i];
    }
    answer[len-K]=0;
    return answer;
}