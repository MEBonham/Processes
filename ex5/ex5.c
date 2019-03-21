// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(void)
{
    // Your code here
    int fd[2];

    pipe(fd);

    pid_t pid = fork();

    if (pid == 0)
    {
        close(fd[0]);
        int written = write(fd[1], msg1, 15); // I don't understand why `sizeof msg1` instead of 15 wasn't working.
        if (written == -1)
        {
            perror("write");
            exit(1);
        }
        
        written = write(fd[1], msg2, 15);
        if (written == -1)
        {
            perror("write");
            exit(1);
        }
        
        written = write(fd[1], msg3, 15);
        if (written == -1)
        {
            perror("write");
            exit(1);
        }
    }
    else
    {
        wait(NULL);

        char buf[128];

        int bytes_read = read(fd[0], buf, sizeof buf);
        write(STDOUT_FILENO, buf, bytes_read);

        bytes_read = read(fd[0], buf, sizeof buf);
        write(STDOUT_FILENO, buf, bytes_read);

        bytes_read = read(fd[0], buf, sizeof buf);
        write(STDOUT_FILENO, buf, bytes_read);
    
        // I don't understand why the program doesn't terminate here and needs to be cut off with CTRL+C.
    }
    
    
    return 0;
}
