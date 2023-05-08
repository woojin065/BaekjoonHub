#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
int rep(int n, int k, char* arr){
    int len=0;
    while(n!=0){
        arr[len++]=n%k+'0';
        n/=k;
    }
    arr[len++]=0;
    return len;
}
int ch(long long tmp){
    if (tmp == 2) return 1;
    if (tmp % 2 == 0) return 0;
    int sqrtn = (int)sqrt(tmp);
    for(long long i=2;i<=sqrtn;i++){
        if(tmp%i==0) return 0;
    }
    return 1;
}
int solution(int n, int k) {
    int answer = 0;
    char* arr_n = (char*)malloc(sizeof(char)*10000000);
    int len = rep(n, k, arr_n);
    for(int i=len-1, f=len-2;i>=-1;i--){
        if(i==-1 || arr_n[i]=='0'){
            long long tmp=0, k=1;
            for(int j=i+1;j<=f;j++, k*=10){tmp+=(arr_n[j]-'0')*k;}
            f=i-1;
            if(tmp!=1&&tmp!=0) if(ch(tmp)) answer++;
        }
    }
    
    return answer;
}