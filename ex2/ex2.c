// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

// Both processes can access the file, it seems. And can write to it. I guess the order they write to it is
// unpredictable? In my test run it seemed like they at least finished their individual fprintf functions
// one after the other, rather than simultaneously.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE *fp;
    fp = fopen("text.txt", "w");

    pid_t pid = fork();

    if (pid == 0)
    {
        fprintf(fp, "Child writes this.\n");
    }
    else
    {
        fprintf(fp, "Parent writes this.\n");
    }
    

    return 0;
}
