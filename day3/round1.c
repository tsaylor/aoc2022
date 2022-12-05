#include <stdio.h>
#include <string.h>

int main () {
    char contents[60], one[30], two[30], *halfway, match;
    int len, priority, sum=0;
    FILE *pFile;

    pFile = fopen("input.txt","r");

    while(fscanf(pFile, "%s", contents) == 1) {
        memset(one, 0, 30);
        memset(two, 0, 30);
        match = '\0';
        priority = 0;

        len = strlen(contents);
        halfway = &contents[len / 2];
        strncpy(one, contents, len / 2);
        strncpy(two, halfway, len / 2);
        printf("%d %s %s %s %s\n", len, contents, halfway, one, two);

        for (int i = 0; i < len / 2; i++) {
            for (int j = 0; j < len / 2; j++) {
                if (one[i] == two[j]) {
                    match = one[i];
                }
            }
        }
        if (match != '\0') {
            printf("both contain %c\n", match);
        } else {
            printf("no match\n");
        }

        if (match > 96) {
            priority = match - 96;
        } else {
            priority = match - 38;
        }
        printf("priority: %d\n", priority);

        sum += priority;
    }
    printf("sum of priorities: %d\n", sum);

    fclose (pFile);

    return 0;
}


