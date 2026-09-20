#include<stdio.h>
#include<stdlib.h>
struct node* createNode(int);
struct node* insertNode(struct node*,int,int);
struct node* deleteNode(struct node*,int);
void traverseLinkedList(struct node*);
int searchingDoubleLinkedList(struct node*,int);
struct node{
	struct node* prev;
	int data;
	struct node* next;
};
int main(){
	int n1,n2,n3,n4;
	printf("Enter the value of linked list: ");
	scanf("%d%d%d%d",&n1,&n2,&n3,&n4);
	
	struct node* head = createNode(n1);
	struct node* second = createNode(n2);
	struct node* third = createNode(n3);
	struct node* fourth = createNode(n4);
	
	head->next = second;
	second->prev = head;
	second->next = third;
	third->prev = second;
	third->next = fourth;
	fourth->prev = third;
	
	printf("\nOriginal Linked List: ");
	traverseLinkedList(head);
	
	int newn,index;
	printf("\nEnter new node value and index: ");
	scanf("%d%d",&newn,&index);
	if(index>5){
		printf("\nError Linked list last index is 4;terminating");
		return 0;
	}
	head = insertNode(head,index,newn);
	printf("\nLinked List after insertion: ");
	traverseLinkedList(head);
	
	printf("\nEnter index of node to be deleted: ");
	scanf("%d",&index);
	head = deleteNode(head,index);
	traverseLinkedList(head);
	
	int find;
	printf("Enter value to be found: ");
	scanf("%d",&find);
	int out = searchingDoubleLinkedList(head,find);
	if(out==-1){
		printf("Element not found!");
	}
	else{
		printf("Element found at index %d",out);
	}
	return 0;
}
struct node* createNode(int val){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	
	newNode->prev = NULL;
	newNode->data = val;
	newNode->next = NULL;
	
	return newNode;
}
struct node* insertNode(struct node* head,int position,int val){
	struct node* newNode = createNode(val);
	struct node* temp = head;
	if(position==1){
		newNode->next = temp;
		temp->prev = newNode;
		return newNode;
	}
	else if(position==5){
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
		return head;
	}
	else{
		while(position!=2){
			temp = temp->next;
			position--;
		}
		struct node* tempNext = temp->next;
		temp->next = newNode;
		newNode->prev = temp;
		newNode->next = tempNext;
		tempNext->prev = newNode;
		return head;
	}
}
struct node* deleteNode(struct node* head,int position){
	struct node* temp=head;
	if(position==1){
		head = head->next;
		head->prev = NULL;
		free(temp);
		return head;
	}
	else if(position==4){
		while(temp->next->next!=NULL){
			temp = temp->next;
		}
		struct node* tempNext = temp->next;
		temp->next = NULL;
		free(tempNext);
	}
	else{
		while(position!=1){
			temp = temp->next;
			position--;
			
		}
		struct node* tempPrev = head;
		while(tempPrev->next!=temp){
			tempPrev = tempPrev->next;
		}
		tempPrev->next = temp->next;
		tempPrev = tempPrev->next;
		tempPrev->prev = temp->prev;
		free(temp);
		return head;
	}
}
int searchingDoubleLinkedList(struct node* head, int val){
	int index=1;
	struct node* temp = head;
	int found = 0;
	while(temp->next!=NULL){
		if(temp->data==val){
			found=1;
			break;
		}
		index++;
		temp = temp->next;
	}
	if(found==1)
	return index;
	else
	return -1;
}
void traverseLinkedList(struct node* head){
	struct node* current = head;
	while(current!=NULL){
		printf("%d\t",current->data);
		current = current->next;
	}
	printf("\n");
}