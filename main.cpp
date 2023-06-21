// Compile this assignment with: clang -g -Wall main.c -o main.out
// Use this file to implement testing for your
// doubly linked list implementation

#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

#include "my_dll.h"




// ====================================================
// ================== Program Entry ===================
// ====================================================
int main()
{
    dll_t *dll = create_dll();

	printf("DLL size at start: %d\n", dll_size(dll));
    dll_push_front(dll, 10);
    dll_push_front(dll, 20);
    dll_push_back(dll, 30);
    dll_push_back(dll, 40);
    dll_print(dll);
    printf("Element at position 2: %d\n", dll_get(dll, 2));
    
    int removed = dll_remove(dll, 1);
    
    printf("Removed element: %d\n", removed);
    printf("DLL size after removal: %d\n", dll_size(dll));
    dll_print(dll);
    
    int front = dll_pop_front(dll);
    int back = dll_pop_back(dll);
    
    printf("Popped front element: %d\n", front);
    printf("Popped back element: %d\n", back);
    dll_print(dll);
    free_dll(dll);
    
    return 0;
}
