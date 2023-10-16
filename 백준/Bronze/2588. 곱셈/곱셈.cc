#include <stdio.h>

int main()
{
    int A, B, C;
    scanf("%d %d", &A, &B);
    C=A*B;
    while(B>0){
        printf("%d\n", A*(B%10));
        B/=10;
    }
    printf("%d", C);
}
