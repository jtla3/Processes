// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    int x = 100;

    pid_t pid = fork();
    if(pid == 0)
    {
        printf("%d: I'm the child!\n", getpid());
        x = x + 100;
        printf("this is the child x: %d\n", x);
    }
    else
    {
        sleep(1);
        printf("this is child x: %d\n", getpid());
        x = x + 400;
        printf("This is the parent x: %d\n", x);
    }
    return 0;
}
