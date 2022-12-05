#include <stdio.h>
#include <string.h>

#define BUFSIZE 60

void bubble_sort(char chars[]) {
    char temp = '\0';
    int len = strlen(chars);
    int swapped = 1;
    while(swapped != 0) {
        swapped = 0;
        for (int j=0; j<len-1; j++) {
            if (chars[j] > chars[j+1]) {
                temp = chars[j];
                chars[j] = chars[j+1];
                chars[j+1] = temp;
                swapped = 1;
            }
        }
    }
}

int main () {
    char one[BUFSIZE], two[BUFSIZE], three[BUFSIZE], badge;
    int priority, sum=0;
    FILE *pFile;
    pFile = fopen("input.txt","r");
    memset(one, 0, BUFSIZE);
    memset(two, 0, BUFSIZE);
    memset(three, 0, BUFSIZE);

    while(fscanf(pFile, "%s", one) == 1) {
        fscanf(pFile, "%s", two);
        fscanf(pFile, "%s", three);
        priority = 0;
        badge = '\0';

        for(char *idx = one; *idx != '\0'; idx++) {
            if (strchr(two, *idx) != NULL && strchr(three, *idx) != NULL) {
                badge = *idx;
                printf("badge is %c\n", badge);
                break;
            }
        }

        if (badge > 96) {
            priority = badge - 96;
        } else {
            priority = badge - 38;
        }
        printf("priority: %d\n", priority);

        sum += priority;

        memset(one, 0, BUFSIZE);
        memset(two, 0, BUFSIZE);
        memset(three, 0, BUFSIZE);
    }
    printf("sum of priorities: %d\n", sum);

    fclose (pFile);

    return 0;
}

