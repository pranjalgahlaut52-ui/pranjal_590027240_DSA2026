#include <stdio.h>
#include <string.h>

int countVotes(char arr[][50], int n, char *name) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i], name) == 0)
            count++;
    }
    return count;
}

int main() {

    int n;
    scanf("%d", &n);

    char votes[1000][50];

    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    int maxVotes = 0;
    char winner[50] = "";

    for (int i = 0; i < n; i++) {

        int cnt = countVotes(votes, n, votes[i]);

        if (cnt > maxVotes) {
            maxVotes = cnt;
            strcpy(winner, votes[i]);
        }
        else if (cnt == maxVotes) {
            if (strcmp(votes[i], winner) < 0) {
                strcpy(winner, votes[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}