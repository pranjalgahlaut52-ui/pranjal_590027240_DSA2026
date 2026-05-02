#include <stdio.h>
#include <string.h>

int main() {

    char s[1000];
    scanf("%s", s);

    int firstIndex[26];

    for (int i = 0; i < 26; i++)
        firstIndex[i] = -1;

    int minSecondIndex = 100000;
    char result = '-';

    int len = strlen(s);

    for (int i = 0; i < len; i++) {

        int idx = s[i] - 'a';

        if (firstIndex[idx] == -1) {
            firstIndex[idx] = i;
        }
        else {
            // repeated character found
            if (firstIndex[idx] < minSecondIndex) {
                minSecondIndex = firstIndex[idx];
                result = s[i];
            }
        }
    }

    if (result == '-') {
        printf("-1");
    } else {
        printf("%c", result);
    }

    return 0;
}