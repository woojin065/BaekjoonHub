#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
char** solution(int** line, size_t line_rows, size_t line_cols) {
    int len = line_rows;
    int arr[len*(len+1)][2];
    int arr_len=0;
    int max_x=-2000000000, min_x=2000000000;
    int max_y=-2000000000, min_y=2000000000;
    for(int i=0;i<len-1;i++){
        for(int j=i+1;j<len;j++){
            long long a = line[i][0], b = line[i][1], e = line[i][2], c = line[j][0], d = line[j][1], f = line[j][2];
            long long mod = a * d - b * c;
            if (!mod) continue;
            long long xNumerator = b * f - e * d, yNumerator = e * c - a * f;
            if (xNumerator % mod || yNumerator % mod) continue;
            int x = xNumerator / mod, y = yNumerator / mod;
            arr[arr_len][0]=(int)x;
            arr[arr_len][1]=(int)y;
            max_x = x>max_x?x:max_x, min_x = x<min_x?x:min_x;
            max_y = y>max_y?y:max_y, min_y = y<min_y?y:min_y;
            arr_len++;
        }
    }
    int mx=max_x-min_x+1, my=max_y-min_y+1;
    char** answer = (char**)malloc((my)*sizeof(char*));
    for (int i = 0; i < my; i++){
        answer[i] = (char*)malloc((mx+1)*sizeof(char));
        for(int j=0;j<mx;j++)
            answer[i][j] = '.';
        answer[i][mx]=0;
    }
    for(int i=0;i<arr_len;i++)
        answer[max_y+arr[i][1]*-1][arr[i][0]-min_x]='*';
    return answer;
}