#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// queries_row_len은 2차원 배열 queries의 행(세로) 길이입니다.
// queries_col_len은 2차원 배열 queries의 열(가로) 길이입니다.
// queries[i][j]는 queries의 i번째 행의 j번째 열에 저장된 값을 의미합니다.
int* solution(int rows, int columns, int **queries, size_t queries_row_len, size_t queries_col_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(4*queries_row_len);
    int a[101][101];
    int k,sx,sy,x,xt,yt,y,i,j,t,t1,c=1,min;
    for(i=0;i<rows;i++)
         for(j=0;j<columns;j++)
            a[i][j]=c++;
    for(i=0;i<queries_row_len;i++)
    {
        sx=x=queries[i][0]-1; sy=y=queries[i][1]-1;
        xt=queries[i][2]-1; yt=queries[i][3]-1;
        min=t1=a[x][y];
        while(y<yt) {t=a[x][y+1];a[x][y+1]=t1;t1=t;y++;if(min>a[x][y])min=a[x][y];}
        while(x<xt) {t=a[x+1][y];a[x+1][y]=t1;t1=t;x++;if(min>a[x][y])min=a[x][y];}
        while(sy<y) {t=a[x][y-1];a[x][y-1]=t1;t1=t;y--;if(min>a[x][y])min=a[x][y];}
        while(sx<x) {t=a[x-1][y];a[x-1][y]=t1;t1=t;x--;if(min>a[x][y])min=a[x][y];}
        answer[i]=min;
    }
    return answer;
}
