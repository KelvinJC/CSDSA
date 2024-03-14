/*
Read the value of a node in a linked list
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

int read(int n) { /* read a node at position n */
    int i;
    struct Node* temp = head;

    for (i = 0; i < n; ++i) {
        temp = temp->next;
    }
    return(temp->data);
}

int get_position(int val) { /* returns the first position of val; -1 if not found */
    int i = 0;
    struct Node* temp = head;

    while(temp) {
        if (temp->data == val) {
            return(i);
        }
        ++i;
        temp = temp->next;
    }
    return(-1);
}

void insert(int x) {/* helper function to insert data into head of list */
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    if(!new) {
        printf("Memory not allocated \n");
        return;
    }
    new->data = x;
    new->next = head;
    head = new;
}

void print_list() {
    struct Node* temp = head;

    printf("List is: ");
    while (temp) {
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
    int i;
    char test_array[] = {1, 2, 3, 4, 34, 24, 36, 76};

    for (i = 0; test_array[i + 1] != '\0'; ++i) {
        insert(test_array[i]);
    }

    print_list();
    printf("\nread %d \n", read(3));
    printf("Position of 3 in the list is: %d \n", get_position(3));
    printf("Position of 34 in the list is: %d \n", get_position(34));
}
