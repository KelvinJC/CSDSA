/*
 C implementation of deletion of a node with a given value in a linked list
*/

#include <stdio.h>
#include <stdlib.h> 

struct Node {
    int data;
    struct Node* next;    
};

struct Node* head; // global variable; can be accessed anywhere


void delete_val(int val) { /* delete node with value val */
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));
    temp1 = head;
    int i = 1;
    
    if (temp1->data == val) {
        head = temp1->next;
        free(temp1);
        return;
    }

    while(temp1 != NULL) {
        if (temp1->data == val){
            delete_pos(i);
            return;
        }
        ++i;
        temp1 = temp1->next;
    }
}

void delete_pos(int position) { /* helper function to delete node at position */
    struct Node* temp1 = head;
    struct Node* temp2;


    if (position == 1) {
        head = temp1->next;
        free(temp1);
        return;
    }

    for(int i = 0; i < position - 2; ++i) {
        temp1 = temp1->next;
    }

    temp2 = temp1->next;        
    temp1->next = temp2->next;  
    free(temp2);                
}

void insert(int val, int position) { /* helper function to insert values into list for test */
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));
    temp1->data = val;
    temp1->next = NULL;
    
    if(position == 1) {
        temp1->next = head;
        head = temp1;
        return;
    }
   
    struct Node* temp2 = head;
    for(int i = 0; i < position - 2; ++i) {  
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;  
    temp2->next = temp1;        
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
    delete_pos(3);
    putchar('\n');
    print_list();
}
