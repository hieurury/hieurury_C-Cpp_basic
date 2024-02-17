#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct Node Node;

struct Node {
    int number;
    Node *left;
    Node *right;
};

Node *create(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->number = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int countNode(Node *head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->right;
    }
    return count;
}
void pushHead(Node **head, int data) {
    Node *newNode = create(data);
    (*head)->left = newNode;
    newNode->right = *head;
    *head = newNode;


}

void pushMid(Node **head, int data, int index) {
    int length = countNode(*head);
    if(length == 0) {
        pushHead(head, data);
        return;
    }
    if(index > length) {
        return;
    }
    Node *tmp = *head;
    Node *newNode = create(data);
    for(int i = 0; i < index; i++) {
        tmp = tmp->right;
    }
    newNode->right = tmp->right;
    newNode->left = tmp;

}

void printNode(Node *head) {
    while(head != NULL) {
        printf("%d ", head->number);
        head = head->right;
    }
}


int main() {

    Node *myNode = NULL;
    for(int i = 1; i < 6; i++) {
        pushHead(&myNode, i);

    }
    printNode(myNode);
    
}