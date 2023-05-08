#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// order_len은 배열 order의 길이입니다.
int solution(int order[], size_t order_len) {
    int answer = 0;
    int* stack = (int*)malloc(sizeof(int)*order_len);
    int top = -1;
    int o_l = 0;
    for(int i=1;i<=order_len+1;i++){
        if(order[o_l]==i){
            answer++;
            if(o_l<order_len) o_l++;
        }
        else if(top>-1&&stack[top]==order[o_l]){
            answer++;
            if(o_l<order_len) o_l++;
            top--;
            i--;
        }
        else{
            if(i!=order_len) stack[++top]=i;
        }
        
    }
    
    return answer;
    
}