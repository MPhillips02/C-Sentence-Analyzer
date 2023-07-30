#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int GetNumOfNonWSCharacters(const char str[]) {
    int chars = strlen(str);
    int whitespace = 0;

    for (int i = 0; i < chars; i++) {
        if (str[i] == ' ' || str[i] == '\n') {
            whitespace++;
        }
    }

    return strlen(str) - whitespace;
}

int GetNumOfWords(const char str[]) {
    int chars = strlen(str);
    int spaces = -5;

    for (int i = 0; i < chars; i++) {
        if (str[i] == ' ') {
            spaces += 1;
        }
    }

    return spaces;
}

char* FixCapitalization(char new[]) {
    int chars = strlen(new);

    for (int i = 0; i < chars; i++) {
        if (new[i] == '.') {
            new[i + 2] = toupper(new[i + 2]);
        }
    }

    return new;
}

char* ReplaceExclamation(char userString[]) {
    int chars = strlen(userString);

    for (int i = 0; i < chars; i++) {
        if (userString[i] == '!') {
            userString[i] = '.';
        }
    }

    return userString;
}

char* ShortenSpace(char str[]) {
    int chars = strlen(str);

    for (int i = 0; i < chars; i++) {
        if (str[i] == ' ' && str[i+1] == ' ') {
            for (int j = i; j < chars; j++) {
                str[j] = str[j + 1];
            }
        }
    }

    for (int i = 0; i < chars; i++) {
        if (str[i] == ' ' && str[i + 1] == ' ') {
            for (int j = i; j < chars; j++) {
                str[j] = str[j + 1];
            }
        }
    }

    for (int i = 0; i < chars; i++) {
        if (str[i] == ' ' && str[i + 1] == ' ') {
            for (int j = i; j < chars; j++) {
                str[j] = str[j + 1];
            }
        }
    }

    return str;
}

char PrintMenu() {
    char mChoice;

    printf("MENU\n");
    printf("c - Number of non-whitespace characters\n");
    printf("w - Number of words\n");
    printf("f - Fix capitalization\n");
    printf("r - Replace all !'s\n");
    printf("s - Shorten spaces\n");
    printf("q - Quit\n\n");

    printf("Choose an option:\n");
    scanf("%c", &mChoice);

    return mChoice;
}

int main(void) {
    char string[300];
    char choice;
    char trash;

    /* Type your code here. */
    printf("Enter a sample text:\n");
    fgets(string, 300, stdin);

    printf("\n");

    printf("You entered: %s\n", string);

    choice = PrintMenu();
    scanf("%c", &trash);

    while (choice != 'q') {
        if (choice == 'c') {
            int chars = GetNumOfNonWSCharacters(string);
            printf("Number of non-whitespace characters: %d\n\n", chars);
        }
        else if (choice == 'w') {
            int words = GetNumOfWords(string);
            printf("\nNumber of words: %d\n", words);
        }
        else if (choice == 'f') {
            printf("\nEdited text: %s\n", FixCapitalization(string));
        }
        else if (choice == 'r') {
            printf("\nEdited text: %s\n", ReplaceExclamation(string));
        }
        else if (choice == 's') {
            printf("\nEdited text: %s\n", ShortenSpace(string));
        }
        choice = PrintMenu();
        scanf("%c", &trash);
    }

    return 0;
}