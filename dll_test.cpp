#include <stdio.h>
#include <stdlib.h>
#include "my_dll.h"
int unitTest1(int status)
{
    int passed = 0;
    dll_t* test = create_dll();
    if (dll_empty(test))
    {
        passed = 1;
    }
    free_dll(test);

    return passed;
}

int unitTest2(int status)
{
    int passed = 0;
    dll_t* test = create_dll();
    dll_push_front(test, 789);
    if (1 == dll_size(test))
    {
        passed = 1;
    }
    else
    {
        passed = 0;
    }
    free_dll(test);

    return passed;
}

int unitTest3(int status)
{
    int passed = 0;
    dll_t* test = create_dll();
    dll_push_back(test, 142);
    if (1 == dll_size(test))
    {
        passed = 1;
    }
    else
    {
        passed = 0;
    }
    free_dll(test);

    return passed;
}

int unitTest4(int status)
{
    int passed = 0;
    dll_t* test = create_dll();
    dll_push_back(test, 142);
    dll_pop_back(test);
    if (0 == dll_size(test))
    {
        passed = 1;
    }
    else
    {
        passed = 0;
    }
    free_dll(test);

    return passed;
}

int unitTest5(int status)
{
    int passed = 0;
    dll_t* test = create_dll();
    dll_push_back(test, 142);
    dll_push_front(test, 142);
    dll_pop_back(test);
    if (1 == dll_size(test))
    {
        passed = 1;
    }
    else
    {
        passed = 0;
    }
    free_dll(test);

    return passed;
}

// Tests dll_remove function on an empty list
int unitTest6(int status)
{
    int passed = 0;
    dll_t *test = create_dll();
    int result = dll_remove(test, 0);
    if (result == -1 && dll_size(test) == 0)
    {
        passed = 1;
    }
    free_dll(test);

    return passed;
}

// Tests dll_remove function to remove the only element in the list
int unitTest7(int status)
{
    int passed = 0;
    dll_t *test = create_dll();
    dll_push_back(test, 10);
    int result = dll_remove(test, 0);
    if (result == 10 && dll_size(test) == 0)
    {
        passed = 1;
    }
    free_dll(test);

    return passed;
}

// Tests dll_remove function to remove the first element in the list
int unitTest8(int status)
{
    int passed = 0;
    dll_t *test = create_dll();
    dll_push_back(test, 10);
    dll_push_back(test, 20);
    int result = dll_remove(test, 0);
    if (result == 10 && dll_size(test) == 1 && dll_get(test, 0) == 20)
    {
        passed = 1;
    }
    free_dll(test);

    return passed;
}

// Tests dll_remove function to remove the last element in the list
int unitTest9(int status)
{
    int passed = 0;
    dll_t *test = create_dll();
    dll_push_back(test, 10);
    dll_push_back(test, 20);
    int result = dll_remove(test, 1);
    if (result == 20 && dll_size(test) == 1 && dll_get(test, 0) == 10)
    {
        passed = 1;
    }
    free_dll(test);

    return passed;
}

// Tests dll_remove function to remove an element in the middle of the list
int unitTest10(int status)
{
    int passed = 0;
    dll_t *test = create_dll();
    dll_push_back(test, 10);
    dll_push_back(test, 20);
    dll_push_back(test, 30);
    int result = dll_remove(test, 1);
    if (result == 20 && dll_size(test) == 2 && dll_get(test, 0) == 10 && dll_get(test, 1) == 30)
    {
        passed = 1;
    }
    free_dll(test);

    return passed;
}



// unitTests array
int (*unitTests[])(int) =
 {
    unitTest1,
    unitTest2,
    unitTest3,
    unitTest4,
    unitTest5,
    unitTest6,
    unitTest7,
    unitTest8,
    unitTest9,
    unitTest10,
    NULL
};

int main()
{
    unsigned int testsPassed = 0;
    int counter = 0;
    while (unitTests[counter] != NULL)
    {
        printf("========unitTest %d========\n", counter+1);
        if (1 == unitTests[counter](1))
        {
            printf("passed test\n");
            testsPassed++;
        }
        else
        {
            printf("failed test, missing functionality, or incorrect test\n");
        }
        counter++;
    }

    printf("%d of %d tests passed\n", testsPassed, counter);

    return 0;
}

