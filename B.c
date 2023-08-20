#include <stdio.h>
#include <stdlib.h>

int a,b,c,d,e;

void callStack(int n)
{
    int local;
    if (n > 0)
    {
        printf("Stack Address: %p\n", &local);
        callStack(n-1);
    }
}

void callHeap(int n)
{
    int* mem = (int *)malloc(sizeof(int));
    if (n > 0)
    {
        printf("Heap Address: %p\n", mem);
        callHeap(n-1);
    }
    free(mem);
}

void callGlobal()
{
    printf("Data Address: %p\n", &a);
    printf("Data Address: %p\n", &b);
    printf("Data Address: %p\n", &c);
    printf("Data Address: %p\n", &d);
    printf("Data Address: %p\n", &e);
}

int main()
{
    int n = 5;
    printf("Stack grows downward:\n");
    callStack(n);
    printf("\nHeap grows upward:\n");
    callHeap(n);
    printf("\nGlobal variables:\n");
    callGlobal();
    return 0;
}