#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int di[4]={-1, 0, 1, 0};
int dj[4]={0, 1, 0, -1};
int L_n[4]={3, 0, 1, 2};
int R_n[4]={1, 2, 3, 0};
int first_arr[3]={0};
compare(const void* a, const void* b){return *(int*)a-*(int*)b;}
int next_ch_cycle(const char* grid[], int*** arr, int g_i, int g_j, int x, int y, int k){
    if(arr[x][y][k]==0) return cycle_ch(grid, arr, g_i, g_j, x, y, k)+1;
    else {
        if(first_arr[0]==x&&first_arr[1]==y&&first_arr[2]==k)return 1;
        else return -999999999;
    }
}
int next_ch(const char* grid[], int*** arr, int g_i, int g_j, int x, int y, int k){
    if(grid[x][y]=='S') return next_ch_cycle(grid, arr, g_i, g_j, x, y, k);
    else if(grid[x][y]=='L') return next_ch_cycle(grid, arr, g_i, g_j, x, y, L_n[k]);
    else if(grid[x][y]=='R') return next_ch_cycle(grid, arr, g_i, g_j, x, y, R_n[k]);
}
int cycle_ch(const char* grid[], int*** arr, int g_i, int g_j, int i, int j, int k){
    arr[i][j][k]=1;
    int x=i+di[k], y=j+dj[k];
    if(0<=x&&x<g_i&&
      0<=y&&y<g_j){
        return next_ch(grid, arr, g_i, g_j, x, y, k);
    }
    else if(0<=y&&y<g_j){
        if(0>x)x=g_i-1;
        else x=0;
        return next_ch(grid, arr, g_i, g_j, x, y, k);
    }
    else if(0<=x&&x<g_i){
        if(0>y) y=g_j-1;
        else y=0;
        return next_ch(grid, arr, g_i, g_j, x, y, k);
    }
}
int* solution(const char* grid[], size_t grid_len) {
    int g_i = grid_len, g_j = strlen(*grid), ans_l=0;
    int*** arr;
    arr = (int***)malloc(sizeof(int**)*g_i);
    for(int i=0;i<g_i;i++){
        arr[i] = (int**)malloc(sizeof(int*)*g_j);
        for(int j=0;j<g_j;j++){
            arr[i][j] = (int*)malloc(sizeof(int)*4);
            for(int k=0;k<4;k++)
                arr[i][j][k]=0;
        }
    }
    int* answer = (int*)malloc(sizeof(int)*g_i*g_j*4);
    for(int i=0;i<g_i;i++)
        for(int j=0;j<g_j;j++)
            for(int k=0;k<4;k++){
                first_arr[0]=i, first_arr[1]=j, first_arr[2]=k;
                int anstmp=cycle_ch(grid, arr, g_i, g_j, i, j, k);
                if(anstmp>0)
                    answer[ans_l++]=anstmp;
            }
    qsort(answer, ans_l, sizeof(int), compare);
    return answer;
}