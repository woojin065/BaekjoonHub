#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int di(const char *word, int n){
    char ap[6]="AEIOU";
    int cnt=0;
    for(int i=0;i<5;i++){
        if(word[n]==ap[i]){
            if(word[n+1] != 0){
                cnt+=di(word, n+1);
            }
            cnt++;
            break;
        }
        else{
            for(int j=0, d=1;j<5-n;j++, d*=5){
                cnt+=d;
            }
        }
    }
    return cnt;
}

int solution(const char* word) {
    int answer = di(word, 0);
    
    return answer;
}