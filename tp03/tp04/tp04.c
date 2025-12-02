#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    int ID;
    char Name[20];
    int Price;
} Product;

typedef struct Node {
    Product Prod;
    struct Node *next;
} Node;

Node* CreateEmptyList() {
    return NULL;
}

int IsEmpty(Node *head) {
    return (head == NULL);
}

Node* InsertAtBeginning(Node *head, Product P) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->Prod = P;

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

    return newNode;
}

Node* InsertAtEnd(Node *head, Product P) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->Prod = P;

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

    return head;
}

void DisplayList(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = head;

    do {
        printf("ID: %d | Name: %s | Price: %d\n",
               temp->Prod.ID,
               temp->Prod.Name,
               temp->Prod.Price);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    Node *head = CreateEmptyList();

    Product p1 = {1, "Milk", 120};
    Product p2 = {2, "Bread", 50};
    Product p3 = {3, "Coffee", 300};

    head = InsertAtBeginning(head, p1);
    head = InsertAtEnd(head, p2);
    head = InsertAtBeginning(head, p3);

    DisplayList(head);

    return 0;
}
