#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int answer;
void ch(int k, int** dungeons, int len, int n, int* dun_c){
    answer=answer<n?n:answer;
    for(int i=0;i<len;i++){
        if(dun_c[i]==0){
            if(k>=dungeons[i][0]){
                dun_c[i]=1;
                ch(k-dungeons[i][1], dungeons, len, n+1, dun_c);
                dun_c[i]=0;
            }
        }
    }
}
// dungeons_rows는 2차원 배열 dungeons의 행 길이, dungeons_cols는 2차원 배열 dungeons의 열 길이입니다.
int solution(int k, int** dungeons, size_t dungeons_rows, size_t dungeons_cols) {
    int* dun_clear = (int*)malloc(sizeof(int)*dungeons_rows);
    for(int i=0;i<dungeons_rows;i++)dun_clear[i]=0;
    answer=0;
    ch(k, dungeons, dungeons_rows, 0, dun_clear);
    return answer;
}