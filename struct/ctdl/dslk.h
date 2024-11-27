#include <stdlib.h>
#include <stdio.h>
typedef struct Node Node;
struct Node {
    int number;
    int hat;
    Node *next;
};

Node *createNode(int number, int hat) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->hat = hat;
    newNode->number = number;
    newNode->next = NULL;

    return newNode;
}

int countNode(Node *node) {
    int count = 0;
    if(node == NULL) return 0;

    while(node != NULL) {
        node = node->next;
        count++;
    }
    return count;
}

void pushNode(Node **node, int number, int hat) {
    Node *tmp = *node;
    Node *newNode = createNode(number, hat);

    if(*node == NULL) {
        *node = newNode;
        return;
    }

    //nếu danh sách không rỗng
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void displayNode(Node *node) {
    if(node == NULL) {
        printf("NULL");
        return;
    }
    while(node != NULL) {
        printf("(%d, %d)", node->number, node->hat);
        node = node->next;
    }
}
