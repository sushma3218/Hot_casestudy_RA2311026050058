#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE 1000
#define THRESHOLD 5   

int countTokens(char line[]) {
    int count = 0, inToken = 0;
    int i;
    for ( i = 0; line[i] != '\0'; i++) {
        if (isalnum(line[i])) {
            if (!inToken) {
                count++;
                inToken = 1;
            }
        } else {
            inToken = 0;
        }
    }
    return count;
}

int main() {
    FILE *file;
    char line[MAX_LINE];
    int totalTokens = 0, totalLines = 0;

    file = fopen("input.c", "r");  // Input file
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        totalLines++;
        totalTokens += countTokens(line);
    }

    fclose(file);

    float density = (float)totalTokens / totalLines;

    printf("Total Lines: %d\n", totalLines);
    printf("Total Tokens: %d\n", totalTokens);
    printf("Token Density: %.2f\n", density);

    if (density > THRESHOLD)
        printf("Is_Token_Heavy: YES\n");
    else
        printf("Is_Token_Heavy: NO\n");

    return 0;
}
