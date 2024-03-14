/*
 Delete a node given its position in a linked list
*/

#include <stdio.h>
#include <stdlib.h> 

struct Node {
    int data;
    struct Node* next;    
};

struct Node* head; // global variable; can be accessed anywhere


void delete_pos(int position) { /* delete node at position */
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
    // temp1 points to node before delete position;
    temp2 = temp1->next;        // node at delete position
    temp1->next = temp2->next;  // node after delete position
    free(temp2);                // delete temp2
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
    char test_array[] = {1, 2, 3, 4, 5, 89, 45};

    for(int i = 0; test_array[i + 1] != '\0'; i++) { // length array appears to be stored at index before EOF
        insert(test_array[i], i + 1);
    }

    printf("List before deletion: \n");
    print_list();
    delete_pos(5); 
    printf("\n\nList before deletion: \n");
    print_list();
}
