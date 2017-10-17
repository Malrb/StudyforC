#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* next;
} node;

void print_list(node* head){
    node* ptr = head;
    while(ptr != NULL){
        printf("%d",ptr->value);
        ptr = ptr->next;
        printf("\n");
    }
}

node* add_node(node* head, int value){
    node* new_node = malloc(sizeof(node));
    new_node->value = value;

    if(head == NULL){
        head = new_node;
        return head;
    }

    node* current = head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = new_node;
    return head;
}

int main(void){
    node* head = NULL;
    head = add_node(head, 123);
    add_node(head, 456);
    add_node(head, 111);
    print_list(head);
}