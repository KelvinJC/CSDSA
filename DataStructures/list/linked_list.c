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

void insert(int x) { /* insert at head */
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    (*temp).data = x;
    (*temp).next = head;
    head = temp;
}

void print() {
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
        insert(x);
        print();
    }
}
