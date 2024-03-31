#include <stdio.h>
int main()
{
  int a, b;
  int arr[101][101];
  scanf("%d %d", &a, &b);
  for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
      scanf("%d", &arr[i][j]);
    }
  }
  for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
      int tmp;
      scanf("%d", &tmp);
      printf("%d ", arr[i][j]+tmp);
    }
    printf("\n");
  }
}