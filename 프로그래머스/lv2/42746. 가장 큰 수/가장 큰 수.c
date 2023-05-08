#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// numbers_len은 배열 numbers의 길이입니다.

int com(const void* a, const void* b){
    int f=*(int*)a;
    int s=*(int*)b;
    
    int k=1;
    while(f/k!=0)
        k*=10;
    int f_1=s*k+f;
    k=1;
    while(s/k!=0)
        k*=10;
    int f_2=f*k+s;
    
    if(f==0)return 1;
    else if(s==0)return -1;
    else{
        if(f_1<f_2)return -1;
        else if(f_1>f_2)return 1;
        else return 0;
    }
}


char* solution(int numbers[], size_t numbers_len) {
    char* answer;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    qsort(numbers, numbers_len, sizeof(int), com);
    int len=0;
    for(int i=0;i<numbers_len;i++){
        int k=1; 
        while(numbers[i]/k!=0){
            k*=10;
            len++;
        }
        if(numbers[i]==0)
            len++;
    }   
    
    if(numbers[0]==0){
        answer = (char*)malloc(sizeof(char)*(2));
        answer[0]='0';
        answer[1]='\0';
    }
    else{
        answer = (char*)malloc(sizeof(char)*(len+1));
        answer[0]=0;
        for(int i=0;i<numbers_len;i++){
            char a[8] = "";
            sprintf(a, "%d", numbers[i]);
            strcat(answer, a);
        }
        
    }
    
    
    return answer;
}