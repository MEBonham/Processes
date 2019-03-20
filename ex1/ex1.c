// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    int x = 100;

    pid_t pid = fork();

    if (pid == 0) // Child process
    {
        printf("Initial value of x in child process: %d\n", x);
        x = 99;
        printf("Proof of change of value: %d\n", x);
    }
    else // Parent process
    {
        x = 5;
        wait(NULL);
        printf("x in child process after both changes: %d\n", x);
    }

    return 0;
}
