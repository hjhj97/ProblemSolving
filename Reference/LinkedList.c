#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _Node {
	struct _Node *next;
	int data;
}Node;
Node *head;

void init() {
	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
}
void add(Node *target, int key) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->next = target->next;
	new_node->data = key;

	target->next = new_node;
}
int deleteNode(Node *target) {
	Node *deleted = target->next;
	if (deleted == NULL) {
		printf("empty");
		return -1;
	}

	target->next = deleted->next;
	free(deleted);
	return 0;
}

void traverse() {
	Node* cur = head->next;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

int main() {
	int n;	scanf("%d",&n);
	init();

	while(n--){
		printf("%d ",n);
		char cmd[10];	scanf("%s",cmd);
		int result;
		if(strcmp(cmd,"add")==0){
			int x;	scanf("%d",&x);
			add(head,x);
		}
		else{
			result=deleteNode(head);
		}
		if(result!=-1) traverse();
		printf("\n");
	}

	return 0;
}