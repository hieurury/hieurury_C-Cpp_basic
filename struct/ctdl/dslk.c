#include <stdio.h>
#include <math.h>
#include <string.h>
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

void pushNode(Node **head, int data) {

    Node *newNode = createNode(data);
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    Node *tmp = *head;
    while(tmp->link != NULL) {
        tmp = tmp->link;
    }
    tmp->link = newNode;
}
void insertNode(Node **head, int data, int index) {

}

void displayNode(Node *head) {
    if(head == NULL) {
        printf("Danh sach trong!\n");
        return;
    }
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->link;
    }
}

int main() {
    Node *myNode = NULL;
    for(int i = 1; i <= 5; i++) {
        pushNode(&myNode, i);
    }
    displayNode(myNode);
}