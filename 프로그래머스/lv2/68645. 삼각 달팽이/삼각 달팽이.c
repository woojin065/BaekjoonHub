#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len =n * (n+1) / 2;
    int* answer = (int*)calloc(len, sizeof(int));
    for(int i=0;i<len;i++)
        answer[i]=0;
    int ans=1, k=0;
    
    int i=0;
    for(int p=0;p<n;p++){
        while(i+k<len){
            if(answer[i+k]!=0)
                break;
            k+=i;
            answer[k]=ans++;
            i++;
        }
        while(k<len-1){
            if(answer[k+1]!=0)
                break;
            k++;
            answer[k]=ans++;
        }
        while(i+k>0){
            if(answer[k-i]!=0)
                break;
            k-=i;
            answer[k]=ans++;
            i--;
        }
    }
    
    
    return answer;
}