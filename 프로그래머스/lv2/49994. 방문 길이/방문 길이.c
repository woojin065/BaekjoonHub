#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* dirs) {
    int col[21][21]={0};
    int di=10, dj=10;
    col[di][dj]=2;
    int answer = 0;
    
    for(int i=0;i<strlen(dirs);i++){
        if(dirs[i]=='U'){
            if(di<20)
                di++;
            if(col[di][dj]==0)
                answer++;
            col[di][dj]=1;
            if(di<20)
                di++;
            col[di][dj]=1;
        }
        else if(dirs[i]=='D'){
            if(di>0)
                di--;
            if(col[di][dj]==0)
                answer++;
            col[di][dj]=1;
            if(di>0)
                di--;
            col[di][dj]=1;
        }
        else if(dirs[i]=='R'){
            if(dj<20)
                dj++;
            if(col[di][dj]==0)
                answer++;
            col[di][dj]=1;
            if(dj<20)
                dj++;
            col[di][dj]=1;
        }
        else if(dirs[i]=='L'){
            if(dj>0)
                dj--;
            if(col[di][dj]==0)
                answer++;
            col[di][dj]=1;
            if(dj>0)
                dj--;
            col[di][dj]=1;
        }
    }
    for(int i=0;i<21;i++){
        for(int j=0;j<21;j++){
            printf("%d ", col[i][j]);
        }
        printf("\n");
    }
    return answer;
}