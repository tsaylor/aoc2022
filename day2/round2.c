#include <stdio.h>
#include <string.h>

int score(char opponent, char outcome) {
    int throw_score = 0;
    int outcome_score = 0;
    char throw = opponent + (outcome - 'Y');

    if (throw > 'C')
        throw = 'A';
    if (throw < 'A')
        throw = 'C';
    throw_score = throw - 'A' + 1;
    switch(outcome) {
        case 'Z': outcome_score +=3;
        case 'Y': outcome_score +=3;
    }
    printf("%c %c %c %d %d\n", opponent, outcome, throw, throw_score, outcome_score);
    return throw_score + outcome_score;
}
 // > 9660
int main () {
    char opponent[2];
    char self[2];
    FILE *pFile;
    int round_score = 0;
    int total_score = 0;

    pFile = fopen("input.txt","r");

    while(fscanf(pFile, "%s%s", opponent, self) == 2) {
        round_score = score(opponent[0], self[0]);
        total_score += round_score;
        printf ("%s, %s : %d, %d\n", opponent, self, round_score, total_score);
    }

    fclose (pFile);

    return 0;
}


