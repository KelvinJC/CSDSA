/*
Append a node to the end of a linked list
*/

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

void append(int val) {
    struct Node *temp, *new;

    new = (struct Node*)malloc(sizeof(struct Node));
    if (!new) {
        printf("Memory allocation failed\n");
        return;
    }
    new->data = val;
    new->next = NULL;

    // Case 1: List is empty; insertion at tail is same as at head of the list
    if (!head) {
        head = new;
        return;
    }

    // Case 2: Node is inserted at tail of the list
    temp = head;
    while(temp->next) { /* traverse the list to its tail node */        
        temp = temp->next; 
    }
    temp->next = new;      // set newly created node as tail
}

void print_list() {
    struct Node* temp = head; 

    printf("List is: ");
    while(temp) {
        if (temp->next == NULL) {
            printf("[ %d ]", temp->data);
        }
        else {
            printf("[ %d ]-->", temp->data);
        }
        temp = temp->next;
    }
} 

void main() {
    head = NULL;
    int i, count, num;

    printf("How many numbers are in the list? \n");
    scanf("%d", &count);

    for (i = 0; i < count; ++i) {
        printf("\nEnter number here: \n");
        scanf("%d", &num);
        append(num);
        print_list();
    }
}