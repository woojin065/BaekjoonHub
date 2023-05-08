#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sizes_rows는 2차원 배열 sizes의 행 길이, sizes_cols는 2차원 배열 sizes의 열 길이입니다.
int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
    int max1=0, max2=0;
    for(int i=0;i<sizes_rows;i++){
        if(sizes[i][0]>sizes[i][1]){
            max1=max1<sizes[i][0]?sizes[i][0]:max1;
            max2=max2<sizes[i][1]?sizes[i][1]:max2;
        }
        else{
            max1=max1<sizes[i][1]?sizes[i][1]:max1;
            max2=max2<sizes[i][0]?sizes[i][0]:max2;
        }
        
    }
    return max1*max2;
}