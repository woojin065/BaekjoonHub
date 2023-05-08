#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// deliveries_len은 배열 deliveries의 길이입니다.
// pickups_len은 배열 pickups의 길이입니다.
long long solution(int cap, int n, int deliveries[], size_t deliveries_len, int pickups[], size_t pickups_len) {
    long long answer = 0;
    
    int start = -1;
    int idx = -1;
    int give = 0;
    int get = 0;
    for(int i=n-1 ;i>=0;i--)
    {
        if(deliveries[i]!=0 || pickups[i]!=0)
        {
            int cnt=0;
            while(give < deliveries[i] || get< pickups[i])
            {
                ++cnt;
                give+=cap;
                get+=cap;
            }
            give -= deliveries[i];
            get -=  pickups[i];
            answer = answer + (long long)((i+1)*cnt*2);
        }
    }
    return answer;
}