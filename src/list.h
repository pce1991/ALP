
#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* next;
    char *data;
};

int Length(struct Node* head) {
    struct Node* current = head;
    int count = 1;
    while (current->next != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

Node *Push(struct Node* head, char *data) {
    struct Node* newNode = (Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = head;
    return newNode;
}

Node *Pop(struct Node* head) {
    Node *newHead = head->next;
    free(head);
    return newHead;
}

//push
//pop
//add on end
//concat
