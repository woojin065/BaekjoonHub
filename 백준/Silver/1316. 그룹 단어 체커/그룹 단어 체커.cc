#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int n, groupWordCount = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char word[101];
        bool charMap[26] = {false};
        bool isGroupWord = true;

        scanf("%s", word);
        int len = strlen(word);

        for (int j = 0; j < len; j++) {
            if (j > 0 && word[j] != word[j - 1] && charMap[word[j] - 'a']) {
                isGroupWord = false;
                break;
            }
            charMap[word[j] - 'a'] = true;
        }

        if (isGroupWord) {
            groupWordCount++;
        }
    }

    printf("%d\n", groupWordCount);

    return 0;
}
