#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int data;
    Node *link;
};

Node *createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

int countNode(Node *node) {
    int count = 0;

    while(node != NULL) {
        count++;
        node = node->link;
    }
    return count;
}

void display(Node *node) {
    while(node != NULL) {
        printf("%d ", node->data);
        node = node->link;
    }
}
void displayRevert(Node *node) {
    if(node == NULL) return;
    displayRevert(node->link);
    printf("%d ", node->data);
}

void pushNode(Node **node, int data) {
    Node* newNode = createNode(data);

    if(*node == NULL) {
        *node = newNode;
        return;
    }

    Node* tmp = *node;

    while(tmp->link != NULL) {
        tmp = tmp->link;
    }

    tmp->link = newNode;

}

int main() {
    Node *myNode = NULL;

    for(int i = 1; i <= 5; i++) {
        pushNode(&myNode, i);
    }

    displayRevert(myNode); 
}