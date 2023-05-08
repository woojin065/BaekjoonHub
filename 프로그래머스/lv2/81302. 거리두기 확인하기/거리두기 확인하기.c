#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// places_rows는 2차원 배열 places의 행 길이, places_cols는 2차원 배열 places의 열 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char*** places, size_t places_rows, size_t places_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*5);
    for(int i=0;i<5;i++)
        answer[i]=1;
    int ans_l = 0;
    int di[4]={1, 0, -1, 0};
    int dj[4]={0, 1, 0, -1};
    bool ch;
    for(int k=0;k<5;k++){
        ch = true;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(places[k][i][j]=='P'){
                    for(int d=0;d<4;d++){
                        int x=i+di[d], y=j+dj[d];
                        if(0<=x&&x<5&&
                          0<=y&&y<5){
                            if(places[k][x][y]=='P'){ch = false;break;}
                            else if(places[k][x][y]=='O'){
                                if(di[d]==0){
                                    if(x+1<5){if(places[k][x+1][y]=='P'){ch = false;break;}}
                                    if(0<=x-1){if(places[k][x-1][y]=='P'){ch = false;break;}}
                                    if(0<=y+dj[d]&&y+dj[d]<5){if(places[k][x][y+dj[d]]=='P'){ch = false;break;}}
                                }
                                else{
                                    if(y+1<5){if(places[k][x][y+1]=='P'){ch = false;break;}}
                                    if(0<=y-1){if(places[k][x][y-1]=='P'){ch = false;break;}}
                                    if(0<=x+di[d]&&x+di[d]<5){if(places[k][x+di[d]][y]=='P'){ch = false;break;}}
                                }
                            }
                        }
                    }
                if(!ch)break;
                }
            }
            if(!ch){answer[ans_l] = 0;break;}
        }
        ans_l++;
    }
    return answer;
}