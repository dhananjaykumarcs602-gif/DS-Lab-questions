#include<stdio.h>
#include<stdlib.h>

struct Node* createNode(int);
struct Node* insertNodeAtStart(int,struct Node*);
struct Node{
	int val;
	struct Node* next;
};

int main(){
	int n1,n2,n3,n4;
	printf("Enter values: ");
	scanf("%d%d%d%d",&n1,&n2,&n3,&n4);
	
	struct Node* first = createNode(n1);    
	struct Node* second = createNode(n2);
	struct Node* third = createNode(n3);
	struct Node* fourth = createNode(n4);
	
	struct Node* head = NULL;
	head = first;
	first->next=second;
	second->next=third;
	third->next=fourth;
	
	struct Node* current = head;
	while(current != NULL){
		printf("%d\t",current->val);
		current = current-> next;
	}
	
	int n;
	printf("\nEnter Element to insert at start: ");
	scanf("%d",&n);
	head = insertNodeAtStart(n,head);
	
	while(head != NULL){
		printf("%d\t",head->val);
		head = head-> next;
	}
	return 0;
}
struct Node* createNode(int val){   // Creating New Elements for Linked List
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}
struct Node* insertNodeAtStart(int n,struct Node* head){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	struct Node* newNode = createNode(n);
	newNode->next = head;
	return newNode;
}

