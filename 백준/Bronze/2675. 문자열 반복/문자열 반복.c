#include<stdio.h>
#include<string.h>
int main(){
    int n, num;
    char arr[50];
    scanf("%d", &n);
    while(n--){
        scanf("%d", &num);
        scanf("%s", arr);
        int len1 = strlen(arr);
        for(int i=0;i<len1;i++){
            for(int j=0;j<num;j++){
                printf("%c", arr[i]);
            }
        }
        printf("\n");
    }
}