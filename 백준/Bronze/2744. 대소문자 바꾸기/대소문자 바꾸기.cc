#include<stdio.h>
int main(){
    char arr[101];
    scanf("%s", arr);
    for(int i=0;arr[i]!=0;i++){
        if(arr[i]>'Z'){
            printf("%c", arr[i]-'a'+'A');
        }
        else{
            printf("%c", arr[i]-'A'+'a');
        }
    }
}