
#include<stdio.h>
#include<stdlib.h>
struct Node {
 int  data;
 struct Node*next;	
};
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
    }
    void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 40); 
    head = insertAtBeginning(head, 50); 
    head = insertAtBeginning(head, 60); 
    head = insertAtBeginning(head, 70); 
    head = insertAtBeginning(head, 80); 
    
    display(head); 
    return 0;
}
