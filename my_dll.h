#ifndef MYDLL_H
#define MYDLL_H

#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* previous;
} node_t;

typedef struct DLL {
    int count;
    node_t* head;
    node_t* tail;
} dll_t;

dll_t* create_dll() {
    dll_t* myDLL = (dll_t*)malloc(sizeof(dll_t));
    
    if (myDLL == NULL) {
        return NULL;
    }

    myDLL->count = 0;
    myDLL->head = NULL;
    myDLL->tail = NULL;

    return myDLL;
}

int dll_empty(dll_t* l) {
    if (l == NULL) {
        return -1;
    }
    
    return (l->count == 0);
}

int dll_push_front(dll_t* l, int item) {
    if (l == NULL) {
        return -1;
    }
    
    //node_t* newNode = (dll_t*)malloc(sizeof(node_t));
    node_t* newNode = (node_t*)malloc(sizeof(node_t));

   // dll_t* myDLL = (dll_t*)malloc(sizeof(dll_t));
    
    if (newNode == NULL) {
        return 0;
    }
    
    newNode->data = item;
    newNode->previous = NULL;
    newNode->next = l->head;

    if (l->head != NULL) {
        l->head->previous = newNode;
    } else {
        l->tail = newNode;
    }
    
    l->head = newNode;
    l->count++;
    return 1;
}

int dll_push_back(dll_t* l, int item) {
    if (l == NULL) {
        return -1;
    }
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
   // node_t* newNode = malloc(sizeof(node_t));
    
    if (newNode == NULL) {
        return 0;
    }
    
    newNode->data = item;
    newNode->next = NULL;
    newNode->previous = l->tail;

    if (l->tail != NULL) {
        l->tail->next = newNode;
    } else {
        l->head = newNode;
    }
    
    l->tail = newNode;
    l->count++;
    
    return 1;
}

int dll_pop_front(dll_t* l) {
    if (l == NULL) {
        return -1;
    }

    if (l->count == 0) {
        return 0;
    }

    int data = l->head->data;
    node_t* temp = l->head;

    if (l->count == 1) {
        l->head = NULL;
        l->tail = NULL;
    } else {
        l->head = l->head->next;
        l->head->previous = NULL;
    }

    free(temp);
    l->count--;

    return data;
}

int dll_pop_back(dll_t* l) {
    if (l == NULL) {
        return -1;
    }

    if (l->count == 0) {
        return 0;
    }

    int data = l->tail->data;
    node_t* temp = l->tail;

    if (l->count == 1) {
        l->head = NULL;
        l->tail = NULL;
    } else {
        l->tail = l->tail->previous;
        l->tail->next = NULL;
    }

    free(temp);
    l->count--;

    return data;
}

int dll_insert(dll_t* l, int pos, int item) {
    if (l == NULL || pos < 0 || pos > l->count) {
        return 0;
    }

    if (pos == 0) {
        return dll_push_front(l, item);
    } else if (pos == l->count) {
        return dll_push_back(l, item);
    }

    node_t* current = l->head;
    int i;

    for (i = 0; i < pos; i++) {
        current = current->next;
    }

	node_t* newNode = (node_t*)malloc(sizeof(node_t));

    //node_t* newNode = malloc(sizeof(node_t));

    if (newNode == NULL) {
        return 0;
    }

    newNode->data = item;
    newNode->previous = current->previous;
    newNode->next = current;

    current->previous->next = newNode;
    current->previous = newNode;

    l->count++;

    return 1;
}

void destroy_dll(dll_t* l) {
    if (l == NULL) {
        return;
    }

    node_t* current = l->head;
    node_t* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(l);
}
int dll_get(dll_t* l, int pos)
{
    if (l == NULL )
    {
    	
        return -1;
    }
    if( pos < 0 || pos >= l->count)
    {
    	return 0;
	}
    node_t* currentNode = l->head;
    int i;
    
    for (i = 0; i < pos; i++)
    {
        currentNode = currentNode->next;
    }
    
    return currentNode->data;
}

int dll_remove(dll_t* l, int pos)
{
    if (l == NULL )
    {
        return -1;
    }
    if( pos < 0 || pos >= l->count)
    {
    	return 0;
	}
    if (pos == 0)
    {
        return dll_pop_front(l);
    }
    
    if (pos == l->count - 1)
    {
        return dll_pop_back(l);
    }
    
    node_t* currentNode = l->head;
    int i;
    
    for (i = 0; i < pos; i++)
    {
        currentNode = currentNode->next;
    }
    
    int data = currentNode->data;
    currentNode->previous->next = currentNode->next;
    currentNode->next->previous = currentNode->previous;
    free(currentNode);
    l->count--;
    
    return data;
}

int dll_size(dll_t* t)
{
    if (t == NULL)
    {
        return -1;
    }

    return t->count;
}
void free_dll(dll_t* t)
{
    if (t == NULL)
    {
        return;
    }

    node_t* currentNode = t->head;
    node_t* temp;

    while (currentNode != NULL)
    {
        temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }

    free(t);
}
void dll_print(dll_t* l) {
    if (l == NULL) {
        printf("Invalid DLL reference\n");
        return;
    }

    if (dll_empty(l)) {
        printf("DLL is empty\n");
        return;
    }

    node_t* current = l->head;

    printf("DLL elements: ");

    while (current != NULL) {
        printf("%d  ", current->data);
        current = current->next;
    }

    printf("\n");
}

#endif /* MYDLL_H */

