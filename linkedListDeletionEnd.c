#include<stdio.h>
#include<stdlib.h>
struct Node* createNode(int);
void deleteFromEnd(struct Node*);

struct Node{
    int data;
    struct Node* next;
};

int main(){
    int n1,n2,n3,n4;
    printf("Enter the elements of the linked list: ");
    scanf("%d%d%d%d",&n1,&n2,&n3,&n4);
    struct Node* head = createNode(n1);
    struct Node* second = createNode(n2);
    struct Node* third = createNode(n3);
    struct Node* fourth = createNode(n4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    
    printf("Original linked list: ");
    struct Node* current = head;
    while(current!=NULL){
        printf("%d\t",current->data);
        current = current->next;
    }
    deleteFromEnd(head);
    
    printf("\nNew linked list: ");
    struct Node* newcurrent = head;
    while(newcurrent!=NULL){
        printf("%d\t",newcurrent->data);
        newcurrent = newcurrent->next;
    }
    return 0;
}
struct Node* createNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
void deleteFromEnd(struct Node* head){
    struct Node* temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    struct Node* del = temp->next;
    free(del);
    temp->next=NULL;
}