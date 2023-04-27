#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  int N, k;
  scanf("%d %d", &N, &k);

  int* arr = (int*)malloc(sizeof(int)*N);
  for(int i=1;i<=N;i++) arr[i-1]=i;

  int m=k-1;
  printf("<");
  for(int i=N;i>1;i--){
    printf("%d, ", arr[m]);
    for(int j=m;j<i-1;j++)arr[j]=arr[j+1];
    m=(m+k-1)%(i-1);
  }
  printf("%d>", arr[0]);
}