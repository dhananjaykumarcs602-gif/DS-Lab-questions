#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
};
struct Node* createNode(int n){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	
	newNode->data=n;
	newNode->next=NULL;
	return newNode;
}
int main(){
	struct Node* head = NULL;
	int n1,n2;
	scanf("%d%d",&n1,&n2);
	struct Node* first = createNode(n1);
	struct Node* second = createNode(n2);
	
	head = first;
	first->next = second;
	
	struct Node* current = head;
	printf("\nLinked List: ");
	while(current!=NULL){
		printf("%d\t",current->data);
		current = current->next;
		
	}
	return 0;
	
}
