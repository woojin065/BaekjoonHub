#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n, long long left, long long right) {
    int* answer = (int*)malloc(sizeof(int)*(right-left+1));
    int len=0;
    for(long long i=left;i<=right;i++){
        int x=i/n, y=i%n;
        if(x>=y) answer[len++]=x+1;
        else if(x<y) answer[len++]=y+1;
    }
    return answer;
}