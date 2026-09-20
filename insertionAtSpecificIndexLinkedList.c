#include<stdio.h>
#include<stdlib.h>

struct Node* createNode(int);
struct Node* insertNodeAtSpecificIndex(int,int,struct Node*);
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
	
	int n,newn;
	printf("\nEnter Index for the element to be inserted at: ");
	scanf("%d",&n);
	if(n<=0&&n>=6){
		printf("Enter valid index, from 1-4");
		return 0;
	}
	printf("Enter Element to insert at index: ");
	scanf("%d",&newn);
	head = insertNodeAtSpecificIndex(n,newn,head);
	
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

struct Node* insertNodeAtSpecificIndex(int n,int newn,struct Node* head){ // Inserting Element at a Specific Index of Linked List
	if(n==1){//insertion at start
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		
		temp->val = newn;
		temp->next = head;
		newNode = temp;
		return newNode;
	}
	else if(n==5){//insertion at the end
		struct Node* temp = head;
		struct Node* newNode = createNode(newn);
	
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = newNode;
		return head;
	}
	else{//insertion at specific index
		struct Node* temp = head;
		struct Node* tempNext = temp;
		struct Node* newNode = createNode(newn);
		while(n!=2){
			temp = temp->next;
			n--;
		}
		tempNext = temp->next;
		temp->next = newNode;
		newNode->next = tempNext;
		return head;
		
	}
}