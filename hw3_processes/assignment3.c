#include <stdio.h>
#include <stdlib.h>

void func1(void)
{
    printf("Function 1 called\n");
}
void func2(void)
{
    printf("Function 2 called\n");
}

int main()
{
    printf("main is running\n");

    atexit(func1);
    atexit(func2);

    exit(0); //the order of printing would be different if we move this to other line

    printf("would not be printed\n");

}
