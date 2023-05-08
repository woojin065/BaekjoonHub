#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int* answer;
int ch(int** arr, size_t len, int i1, int j1){
    int a1=0, a0=0;
    for(int i=i1;i<i1+len;i++){
        for(int j=j1;j<j1+len;j++){
            if(arr[i][j]==1)
                a1++;
            else
                a0++;
        }
    }
    if(a1==0)
        return 0;
    else if(a0==0)
        return 1;
    else
        return 2;
}
void im(int** arr, size_t len, int lev, int i1, int j1){
    if(len==0)
        return;
    for(int i=i1;i<i1+len;i+=lev){
        for(int j=j1;j<j1+len;j+=lev){
            int ch1=ch(arr, lev, i, j);
            if(ch1==1)
                answer[1]++;
            else if(ch1==0)
                answer[0]++;
            else
                im(arr, len/2, lev/2, i, j);
        }
    }
}
// arr_rows는 2차원 배열 arr의 행 길이, arr_cols는 2차원 배열 arr의 열 길이입니다.
int* solution(int** arr, size_t arr_rows, size_t arr_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    answer = (int*)malloc(sizeof(int) * 2);
    answer[0] = 0, answer[1] = 0;
    if(ch(arr, arr_rows, 0, 0)==2)
        im(arr, arr_rows, arr_rows/2, 0, 0);
    else
        im(arr, arr_rows, arr_rows, 0, 0);
    
    return answer;
}