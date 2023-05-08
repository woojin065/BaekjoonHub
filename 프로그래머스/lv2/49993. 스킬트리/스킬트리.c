#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// skill_trees_len은 배열 skill_trees의 길이입니다.

bool check(const char* skill, const char skill_tree[], int sk, int l){
    for(int p=0;p<sk;p++){
        for(int q=l;q<strlen(skill);q++){
            if(skill_tree[p]==skill[q]){
                return false;
            }
        }
    }
    return true;
}
int solution(const char* skill, const char* skill_trees[], size_t skill_trees_len) {
    int answer = skill_trees_len;
    int sk;
    for(int i=0;i<skill_trees_len;i++){
        for(int l=0;l<strlen(skill);l++){
            sk = strlen(skill_trees[i]);
            for(int j=0;j<sk;j++)
                if(skill[l]==skill_trees[i][j])
                    sk=j;
            if(!check(skill, skill_trees[i], sk, l+1)){
                printf("%d ", i);
                answer--;
                break;
            }
        }
    }
    
    return answer;
}