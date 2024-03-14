/*
Reverse a linked list while passing the head as an argument
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node *reversal(struct Node* head) {
    struct Node *prev, *current, *nxt;
    current = head;
    prev = NULL;

    while(current) {
        nxt = current->next;
        current->next = prev;
        prev = current;
        current = nxt;
    }
    return(prev);
}

struct Node *insert(struct Node* head, int val) { /* helper func to insert at head */
    struct Node* temp = head;

    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    if(!new) {
        printf("Insert failed due to error: 'Memory not allocated'. \n");
        return(head);
    }

    new->data = val;
    new->next = head;
    head = new;
    printf("head %d\n", head->data);
    return(head);
}

void print_list(struct Node* head) {
    struct Node* temp = head;

    printf("List is ");
    while(temp) {
        if (temp->next)
            printf("[ %d ]-->", temp->data);
        else 
            printf("[ %d ]", temp->data);
        temp = temp->next;
    }
}

void main() {
    int i = 0;
    struct Node* head = NULL;

    int test_array[] = {1, 2, 3, 4, 34, 22, 91};
    int num_elements = sizeof(test_array) / sizeof(test_array[0]);

    for (i = 0; i < num_elements; ++i) {
        printf("next integer to %d is %d\n", test_array[i], test_array[i + 1]);
        head = insert(head, test_array[i]);
    }
    printf("\nbefore reversal: \n");
    print_list(head);
    head = reversal(head);
    printf("\nafter reversal: \n");
    print_list(head);
}
