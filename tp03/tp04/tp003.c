#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* ========== Stack Node ========== */
typedef struct SNode {
    char data;
    struct SNode *next;
} SNode;

/* ========== Queue Node ========== */
typedef struct QNode {
    char data;
    struct QNode *next;
} QNode;

/* ========== Queue Structure ========== */
typedef struct {
    QNode *front;
    QNode *rear;
} Queue;

/* ========== Stack Functions ========== */
SNode* push(SNode *top, char ch) {
    SNode *newNode = (SNode*)malloc(sizeof(SNode));
    newNode->data = ch;
    newNode->next = top;
    return newNode;   // new top
}

SNode* pop(SNode *top, char *value) {
    if (top == NULL)
        return NULL;

    SNode *temp = top;
    *value = temp->data;
    top = temp->next;
    free(temp);
    return top;   // new top
}

/* ========== Queue Functions ========== */
void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

void enqueue(Queue *q, char ch) {
    QNode *newNode = (QNode*)malloc(sizeof(QNode));
    newNode->data = ch;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

char dequeue(Queue *q) {
    if (q->front == NULL)
        return '\0';

    QNode *temp = q->front;
    char value = temp->data;
    q->front = temp->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return value;
}

/* ========== Main ========== */
int main() {
    char str[200];
    SNode *top = NULL;
    Queue q;

    initQueue(&q);

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    /* Step 1–3: uppercase, ignore spaces, push & enqueue */
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            char ch = toupper(str[i]);
            top = push(top, ch);
            enqueue(&q, ch);
        }
    }

    /* Step 4–5: Compare stack and queue */
    int palindrome = 1;
    char sChar, qChar;

    while (top != NULL && q.front != NULL) {
        top = pop(top, &sChar);
        qChar = dequeue(&q);

        if (sChar != qChar) {
            palindrome = 0;
            break;
        }
    }

    if (palindrome)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}

