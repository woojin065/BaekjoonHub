#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int max;
int rr[11] = { 0 };
void p(int n, int info[], int lev, int rian[], int ii) {
    if (lev == n) {
        int r = 0, o = 0;
        for (int i = 0; i < 11; i++) {
            if(info[i]==0&&rian[i]==0)continue;
            if (info[i] < rian[i]) r += 10 - i;
            else o += 10 - i;
        }
        if (max < r-o) {
            for (int i = 0; i < 11; i++)rr[i] = rian[i];
            max = r-o;
            return;
        }
        else if(max==r-o){
            int a=0, b=0;
            for(int i=0;i<11;i++) a+=rian[i]*i, b+=rr[i]*i;
            if(a>b) for (int i = 0; i < 11; i++)rr[i] = rian[i];
            return;
            
        }
        else return;
    }
    for (int i = ii; i < 11; i++) {
        rian[i]++;
        p(n, info, lev + 1, rian, i);
        rian[i]--;
    }
}
int* solution(int n, int info[], size_t info_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * 10);
    for (int i = 0; i < 11; i++)answer[i] = 0;
    max = 0;
    p(n, info, 0, answer, 0);
    if (max > 0) for (int i = 0; i < 11; i++)answer[i] = rr[i];
    else answer[0] = -1;
    return answer;
}