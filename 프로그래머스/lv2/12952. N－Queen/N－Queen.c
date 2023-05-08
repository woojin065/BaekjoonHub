#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int N_queen(int num, int N, int * board){
    if(num==N)
        return 1;
    else{
        //count: 경우의 수
        int count=0;
        //num 번째 줄에 queen 위치
        for(int i=0; i<N; i++){
            //0~num-1 번째 줄에 겹치는 queen 있는가 확인
            int overlap = 0;
            for(int j=0; j<num; j++){
                int column = board[j];  //queen의 위치: (j, column)
                if(column==i || abs(num-j)==abs(i-column)){
                    overlap = 1;
                    break;
                }
            }
            if(!overlap){   //겹치지 않을 경우
                board[num]=i;
                count += N_queen(num+1, N, board);
            }
        }
        return count;
    }
}


int solution(int n) {
    int answer = 0;
    int* arr=(int*)malloc(sizeof(int)*(n));
    for(int i=0;i<n;i++)
        arr[i]=0;
    answer=N_queen(0, n, arr);
    return answer;
}