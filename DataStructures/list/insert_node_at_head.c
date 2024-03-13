/*
Insert a node at the head of a linked list 
*/

#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for malloc

struct Node {
    int data;
    struct Node* next;    
};

struct Node* head; // global variable; can be accessed anywhere


void insert_at_head(int val) { /* insert val at head */
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    (*temp).data = val;
    (*temp).next = head;
    head = temp;
}

void print_list() {
    struct Node* temp = head;
    printf("List is: ");
    while (temp != NULL) {
        if (temp->next == NULL)
            printf("[ %d ]", temp->data);
        else
            printf("[ %d ]-->", temp->data);
        temp = temp->next;
    }
}

void main() {
    head = NULL; // empty list
    int i, count, num;

    printf("How many numbers are to be stored? \n");
    scanf("%d", &count);
    
    for(i = 0; i < count; i++) {
        printf("Enter the number \n");
        scanf("%d", &num);
        insert_at_head(num);
        print_list();
    }
}
