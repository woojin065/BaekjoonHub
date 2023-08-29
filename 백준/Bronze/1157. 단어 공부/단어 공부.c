#include<stdio.h>
#include<string.h>
int main(){
    char s[1000000];
    int abc[26];
    scanf("%s", s);
    
    for(int i=0;i<26;i++)
        abc[i]=0;
    
    int len1 = strlen(s);
    for(int i=0;i<len1;i++){
        if(s[i]>='a'&&s[i]<='z')
            abc[s[i]-'a']++;
        else
            abc[s[i]-'A']++;
    }
    
    int max=0;
    for(int i=0;i<26;i++){
        max = max > abc[i] ? max : abc[i];
    }
    
    int p=0, k;
    for(int i=0;i<26;i++){
        if(max==abc[i]){
            k=i;
            p++;
            if(p==2)
                break;
        }
    }
    if(p==2)
        printf("?");
    else
        printf("%c", k+'A');
    
        
}