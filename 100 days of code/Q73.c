#include <stdio.h>
#include <string.h>

int main() {

    char s[1000];
    scanf("%s", s);

    int freq[26] = {0};

    int len = strlen(s);

    // count frequency
    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }

    // find first non-repeating
    for (int i = 0; i < len; i++) {
        if (freq[s[i] - 'a'] == 1) {
            printf("%c", s[i]);
            return 0;
        }
    }

    // if none found
    printf("$");

    return 0;
}