#include<stdio.h>
int main(){
    long long n, sum=1;
    for(int i=0;i<3;i++){
        scanf("%ld", &n);
        sum*=n;
    }
    int a[10];
    for(int i=0;i<10;i++)
        a[i]=0;
    while(sum>0){
        a[sum%10]++;
        sum/=10;
    }
    for(int i=0;i<10;i++)
        printf("%d\n", a[i]);
}