#include <iostream>
#include <string>
#include <math>

struct Stack {
	int data;
	Stack *link;
};

int count(Stack &head) {
	int count = 0;
	while(head != NULL) {
		count++;
		head = head->link;
	}
}

int main() {
	
}