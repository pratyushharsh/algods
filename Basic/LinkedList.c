//
// Created by Pratyush Harsh on 6/14/2018.
//

#include <stdio.h>
#include <malloc.h>

//This is the node
typedef struct node {
    int data;
    struct node* next;
} node;

// Declared the head of LL
node* head;

// For creating a node
node* create(int data, node* next) {
    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL) {
        printf("Error creating the node.\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = next;

    return new_node;
}

// Add node at the starting of the LL
node* prepend(int data, node* head) {
    node* new_node = create(data, head);
    head = new_node;
    return head;
}

// Count the length of the LL
int count(node *head) {

    node *pointer = head;
    int c = 0;
    while (pointer->next != NULL) {
        c++;
        pointer = pointer->next;
    }
}

// Inserting to LL

// Append node to the LL
node* append(node* head, int data) {

    // Go to the end of list
    node* cursor = head;
    while (cursor->next != NULL)
        cursor = cursor->next;

    // Attach the node
    node* new_node = create(data, NULL);
    cursor->next = new_node;

    return head;
}

// Insert after a particular node
node* insert_after(node* head, int data, node* prev) {

    if (head == NULL || prev == NULL)
        return NULL;

    node *cursor = head;
    while (cursor != prev)
        cursor = cursor->next;


    // @todo check if it is the last
    if (cursor != NULL) {

        node* new_node = create(data, cursor->next);
        cursor->next = new_node;
        return head;
    } else {
        return NULL;
    }
}

// Insert before a particular node
node* insert_before(node* head, int data, node* nxt) {

    if (head == nxt) {
        head = prepend(data, head);
        return head;
    }

    /* find the prev node, starting from the first node*/
    node* cursor = head;
    while(cursor != NULL) {

        if(cursor->next == nxt)
            break;

        cursor = cursor->next;
    }


    if (cursor != NULL) {
        node* new_node = create(data, cursor->next);
        cursor->next = new_node;
        return head;
    } else {
        return NULL;
    }
}

//Deleting from LL

//Remove the end of the LL
node* remove_back(node* head) {
    if(head == NULL)
        return NULL;

    node* cursor = head;
    node* back = NULL;
    while (cursor->next != NULL) {
        back = cursor;
        cursor = cursor->next;
    }

    if (cursor == head)
        return NULL;

    free(cursor);

    return head;
}

//Remove head of LL

node* remove_first(node* head) {
    if(head == NULL)
        return NULL;

    node* front = head;
    front->next = NULL;
    head = head->next;

    if(front == head)
        return NULL;

    free(front);
    return head;
}

//Remove any from LL

node* remove_any(node* head, node* nd) {
    if (head == NULL)
        return NULL;

    // If the node is the first one.
    if(head == nd)
        remove_first(head);

    // If the node is the last node.
    if(nd->next == NULL)
        remove_back(head);

    node* cursor = head;
    while (cursor != NULL) {
        if(cursor->next == nd)
            break;
        cursor = cursor->next;
    }

    if(cursor != NULL) {
        node* tmp = cursor->next;
        cursor->next = tmp->next;
        tmp->next = NULL;
        free(tmp);
    }
    return head;
}