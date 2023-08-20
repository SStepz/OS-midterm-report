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
    printf("a Data Address: %p\n", &a);
    printf("b Data Address: %p\n", &b);
    printf("c Data Address: %p\n", &c);
    printf("d Data Address: %p\n", &d);
    printf("e Data Address: %p\n", &e);
}

void stackOverflow(int num)
{
    int local;
    printf("%d - Stack Address: %p\n", num, &local);
    stackOverflow(num+1);
}

int main()
{
    int n=5;
    printf("Stack grows downward:\n");
    callStack(n);
    printf("\nHeap grows upward:\n");
    callHeap(n);
    printf("\nGlobal variables:\n");
    callGlobal();
    // use fucntion below to cause stack overflow
    //stackOverflow(0);
    return 0;
}