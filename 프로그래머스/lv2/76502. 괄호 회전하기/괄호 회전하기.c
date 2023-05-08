#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
bool ch(char* s){
    int arr[1000] = {0};
    int top=-1;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='[')
            arr[++top]=0;
        else if(s[i]=='{')
            arr[++top]=1;
        else if(s[i]=='(')
            arr[++top]=2;
        else if(s[i]==']'&&arr[top]==0)
            top--;
        else if(s[i]=='}'&&arr[top]==1)
            top--;
        else if(s[i]==')'&&arr[top]==2)
            top--;
        else
            return false;
    }  
    if(top==-1)
        return true;
    else
        return false;
}
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int len = strlen(s);
    int answer = 0;
    char* arr = (char*)malloc(sizeof(char)*(len*2+1));
    strcpy(arr, s);
    strcat(arr, s);
    char* arr1 = (char*)malloc(sizeof(char)*(len+1));
    arr1[len]=0;
    for(int i=0;i<len;i++){
        strncpy(arr1, arr+i, len);
        if(ch(arr1)){
            answer++;
        }
    }
    
    
    return answer;
}