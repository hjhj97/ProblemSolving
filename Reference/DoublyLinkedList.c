#include<stdio.h>
#include<stdlib.h>
typedef struct _Node {
	struct _Node *prev,*next;
	int data;
}Node;
Node *head, *tail;

void init() {
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	
	head->prev = NULL;
	head->next = tail;

	tail->prev = head;
	tail->next = NULL;
}
void add_next(Node *target, int key) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->prev = target;
	new_node->next = target->next;
	new_node->data = key;

	target->next->prev = new_node;
	target->next = new_node;
}
void delete_next(Node *target) {
	Node *deleted = target->next;
	if (deleted == NULL) {
		printf("Already tail Node!\n");
		return;
	}

	deleted->next->prev = target;
	target->next = deleted->next;
	free(deleted);
	return;
}
void traverse_forward() {
	Node* cur = head->next;
	printf("All elements in Linked list forward :");
	while (cur != tail) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
void traverse_backward() {
	Node* cur = tail->prev;
	printf("All elements in Linked list backward :");
	while (cur != head) {
		printf("%d ", cur->data);
		cur = cur->prev;
	}
	printf("\n");
}
int main() {
	 init();
	 add_next(head,1);
	 add_next(head,2);
	 traverse_forward();
	 traverse_backward();
	 delete_next(head);
	return 0;
}