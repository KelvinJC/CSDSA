/*
Implementation of linked list in C/C++
*/

#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for malloc

struct Node {
    int data;
    struct Node* next;    
};

struct Node* head; // global variable; can be accessed anywhere


void insert(int val, int position) { /* insert val at position */
    // create the new node to be added
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));
    temp1->data = val;
    temp1->next = NULL;
    
    // case 1: list is empty; node is inserted at the head of the list
    if(position == 1) {
        temp1->next = head;
        head = temp1;
        return;
    }
   
    // case 2: node is inserted at any other position in the list
    struct Node* temp2 = head;
    for(int i = 0; i < position - 2; ++i) { /* traverse the list to point at position - 1 */ 
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;  // set next field of newly created node to point to the node currently at position + 1
    temp2->next = temp1;        // set next field of node at position - 1 to point to the newly created node
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
    int n, i, x;

    printf("How many numbers are to be stored? \n");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        printf("Enter the number \n");
        scanf("%d", &x);
        insert(x, i + 1);
        print_list();
    }
}
