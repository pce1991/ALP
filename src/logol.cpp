
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "alp.h"

const char *ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// TODO: change these to take const char * instead of char[]

char circular_alpha(int n) {
    char c;
    c = (char)ALPHABET[n % 26];
    return c;
}

int word_count(char str[]) {
    int c;
    int wc = 0;
    for(int c = 0; c <= strlen(str); c++) {
        if (str[c] == ' ' || str[c] == 0) {
            wc++;
        }
    }
    return wc;
}

char **Words(char str[]) {
    char **result;
    result = (char **)malloc(sizeof(char *) * word_count(str));

    char *token;
    token = strtok(str, " ");
    int i = 0;
    while (token != NULL) {
        result[i++] = token;
        token = strtok(NULL, " ");
    }

    return result;
}

// This is case sensitive
// May want to return bool, a lipogram is supposed to lack certain characters, so it's odd here that true = 0;
void Lipogram(char str[], char omissions[], char *present) {
    for (int i = 0; i < strlen(omissions); i++) {
        if (strchr((char *)str, omissions[i]) != NULL) {
            char *hit = &omissions[i];
            strncat(present, hit, 1);
        }
    }
}

// check every word to see if it has all of the characters in includes.
void Antillipo(char str[], char includes[]) {
    
}

// Pangram
// Isogram: only makes sense for words?
// Acrostic: determine the scheme which is not only the sequence of letters, but where to look for them,
//           like after a new line, at the beginnig of every sentence, etcetera.
// Telestic is the inverse of acrostic: it checks the last letter


char *strrev(char str[]) {
    char *rev = (char *) malloc(sizeof(char) * strlen(str));
    int end = strlen(str) - 1;
    for (int i = 0; i < strlen(str); i++) {
        rev[end] = str[i];
        end--;
    }
    return rev;
}


int Pallindrome(char str[]) {
    return (strcmp(str, strrev(str)) == 0);
}

// Acronym: create one out of a string (take the first letters);
// Generate all partitions of an Acronym


int main() {
    char str[] = "the words are here.";
    char **w = Words(str);
    char *the = w[0];
    char *are = w[2];
    //    printf("%s\n", w[1]);

    struct Node *head = NULL;
    head = (Node *)malloc(sizeof(struct Node));
    head->data = the;

    // struct Node *second = NULL;
    // second = (Node *)malloc(sizeof(struct Node));
    // second->data = are;

    head = Push(head, are);
    // printf("%s\n", head->data);
    //printf("%d\n", Length(head));

    char pal[] = "dad";
    printf("%d\n", Pallindrome(pal));
    
    head = Pop(head);
    

    //    printf("%s\n", head->data);

    // char omissions[] = "ab";
    // char *present = (char *)malloc(sizeof(char *));
    // char sen[] = "Finnegan I love you.";
    // Lipogram(sen, omissions, present);
    // if (strlen(present) == 0) {
    //     printf("none found.\n");
    // }
    // else {
    //     printf("%s\n", present);   
    // }


    return 0;
}
