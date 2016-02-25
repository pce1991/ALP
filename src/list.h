
#include <stdlib.h>

struct Node {
    struct Node* next;
    void *data;
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

Node *Nth(struct Node* head, int n) {
    struct Node* current = head;
    int at = 0;
    while (at != n) {
        current = current->next;
        at++;
    }
    return current;
}

// Reverse in place or create a new list?
Node *Reverse(struct Node* head) {
    
}
