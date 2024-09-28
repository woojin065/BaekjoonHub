#include <string>
#include <iostream>
#include <vector>

using namespace std;


int solution(int n) {
    int count = 0;
    for(int i=0;i<=n;i++){
        int sum = 0, k = i;
        while(1){
            sum+=++k;
            if(sum==n){
                count++;
                break;
            }
            if(sum>n){
                break;
            }
        }
    }
    return count;
}