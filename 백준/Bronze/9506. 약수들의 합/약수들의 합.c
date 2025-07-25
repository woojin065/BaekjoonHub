#include <stdio.h>

int main(){
    int n;
    
    while(1){
        scanf("%d", &n);
        if(n == -1) {
            break;
        }
        int arr[100001] = {0, };
        int sum = 0, end = 0;
        for(int i=1;i<n;i++){
            if(n%i==0){
                sum+=i;
                arr[end++]=i;
            }
        }
        if(sum == n){
            printf("%d =", n);
            for(int i=0;i<end;i++){
                if(i==0)
                    printf(" %d", arr[i]);
                else
                    printf(" + %d", arr[i]);
            }
            printf("\n");
        }
        else{
            printf("%d is NOT perfect.\n", n);
        }
        
    }
    return 0;
}
