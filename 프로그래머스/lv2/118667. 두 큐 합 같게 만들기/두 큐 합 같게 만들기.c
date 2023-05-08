#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int S;
int addIndex(int idx) {
    return idx + 1 >= 2*S ? 0 : idx + 1;
}
int solution(int queue1[], size_t queue1_len, int queue2[], size_t queue2_len) {
    int answer = 0;
    int len=queue1_len*2;
    long long sum1=0, sum2=0;
    for(int i=0;i<queue1_len;i++) sum1+=queue1[i];
    for(int i=0;i<queue2_len;i++) sum2+=queue2[i];
    
    int* insert_q = (int*)malloc(sizeof(int)*len);
    int insert_l=0;
    for(int i=0;i<queue1_len;i++) insert_q[insert_l++]=queue1[i];
    for(int i=0;i<queue2_len;i++) insert_q[insert_l++]=queue2[i];
    
    S=queue1_len;
    int q1_1=0, q1_2=S-1;
    int q2_1=S, q2_2=S*2-1;
    
    while(answer<=4*S){
        if(sum1>sum2){
            sum1-=insert_q[q1_1];
            sum2+=insert_q[q1_1];
            
            q1_1 = addIndex(q1_1);
            q2_2 = addIndex(q2_2);
        }
        else if(sum1 < sum2) {
            sum2 -= insert_q[q2_1];
            sum1 += insert_q[q2_1];
            
            q2_1 = addIndex(q2_1);
            q1_2 = addIndex(q1_2);
        }
        else return answer;
        
        answer++;
    }
    
    return -1;
}