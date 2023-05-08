#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// ranges_rows는 2차원 배열 ranges의 행 길이, ranges_cols는 2차원 배열 ranges의 열 길이입니다.
double* solution(int k, int** ranges, size_t ranges_rows, size_t ranges_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int arr[200]={0};
    int arr_l=0;
    arr[arr_l++]=k;
    while(k!=1){
        if(k%2==0) k/=2;
        else k=k*3+1;
        arr[arr_l++]=k;
    }
    double arr_m[200]={0};
    int arr_m_l=0;
    for(int i=0;i<arr_l-1;i++)
        arr_m[arr_m_l++]=(arr[i]+arr[i+1])/(double)2;
    
    double* answer = (double*)malloc(sizeof(double)*ranges_rows);
    
    for(int i=0;i<ranges_rows;i++){
        if(ranges[i][0]>ranges[i][1]+arr_l-1){answer[i]=-1;continue;}
        for(int j=ranges[i][0];j<ranges[i][1]+arr_l-1;j++){
            answer[i]+=arr_m[j];
        }
    }
    
    
    return answer;
}