#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;

struct Node {
    int data;
    Node *link;
};

int sizeNode(Node *node) {
    int count = 0;
    while(node != NULL) {
        count++;
        node = node->link;
    }
    return count;
}

Node *createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    return newNode;
}

void popNode(Node **top, int data) {
    Node *newNode = createNode(data);
    if(*top == NULL) {
        *top = newNode;
    }
    newNode->link = (*top)->link;
    *top = newNode;
}

int main() {
    Node *myNode = NULL;
    for(int i = 1; i <= 5; i++) {
        popNode(&myNode, i);
    }
    printf("%d", sizeNode(myNode));
}