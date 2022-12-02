#include <stdio.h>
#include <string.h>

int score(char opponent, char self) {
//    printf("%d %d ", opponent, self);
    int throw_score = self - 87;
    int outcome_score = 0;
    switch(self - opponent) {
        case 21:
        case 24:
            outcome_score +=3;
        case 23:
            outcome_score +=3;
    }
    return throw_score + outcome_score;
}

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


