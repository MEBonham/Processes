// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

// I guess I have different answers for each of the 4 letters v, l, e, and p. v is useful when you don't know how many arguments
// you'll have to a program; l is simpler and saves a step when you do. I don't really understand the purpose of e still.
// p just lets you avoid typing in a lengthy path if your PATH already points in the correct direction.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    pid_t pid = fork();

    if (pid == 0)
    {
        char *args[] = {"ls", "-aF", "/mnt/c/Users/McKay", 0};
        // char *env[] = { 0 };

        // execl("/bin/ls", "ls", "-aF", "/", (char*)0);
        // execv("/bin/ls", args);
        // execle("/bin/ls", "ls", "-aF", "/", (char*)0, env);
        // execve("/bin/ls", args, env);
        execvp("ls", args);
    }
    else
    {
        wait(NULL);
        printf("Done.\n");
    }
    

    return 0;
}
