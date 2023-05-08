#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int com(const void* a, const void* b){return *(int*)a-*(int*)b;}
int* solution(int fees[], size_t fees_len, const char* records[], size_t records_len) {
    int car_len=0;
    int car_l[10000];
    int car[10000]={0};
    for(int i=0;i<records_len;i++){
        if(records[i][11]=='I'){
            int ch=1;
            for(int j=0;j<car_len;j++)if(car_l[j]==atoi(records[i]+6)){ch=0;break;}
            if(ch) car_l[car_len++]=atoi(records[i]+6);
            car[atoi(records[i]+6)]-=atoi(records[i])*60+atoi(records[i]+3)+1;
        }
        else car[atoi(records[i]+6)]+=atoi(records[i])*60+atoi(records[i]+3)+1;
    }
    qsort(car_l, car_len, sizeof(int), com);
    int* answer = (int*)malloc(sizeof(int)*car_len);
    for(int i=0;i<car_len;i++){
        if(car[car_l[i]]<0) car[car_l[i]]+=24*60;
        if(car[car_l[i]]==0) answer[i]=0;
        else if(car[car_l[i]]<=fees[0]) answer[i]=fees[1];
        else{
            answer[i]=fees[1]+((car[car_l[i]]-fees[0])/fees[2])*fees[3];
            if((car[car_l[i]]-fees[0])%fees[2]!=0)
                answer[i]+=fees[3];
        } 
    }
    return answer;
}