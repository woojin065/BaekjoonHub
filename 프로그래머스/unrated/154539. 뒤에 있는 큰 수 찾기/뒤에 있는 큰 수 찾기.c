#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*numbers_len);
    int idx = numbers_len;

    int stack[1000001];
    int top = -1;

    for(int i=numbers_len-1;i>=0;i--)
    {
        int temp = numbers[i];

        while(top>-1)
        {
            if(temp < stack[top]) break;
            top--;
        }


        answer[--idx] = top<0 ? -1 : stack[top];
        stack[++top] = temp;
    }


    return answer;
}