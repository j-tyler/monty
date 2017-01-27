#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "monty.h"

extern char **environ;

int main(int argc, char **argv)
{
    int status;
    char *mall;
    
    if (argc != 2)
    {
        printf("USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    mall = malloc(1000);
    if (mall == NULL)
    {
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    free(mall);
    status = open(argv[1], O_RDONLY);
    if (status == -1)
    {
        printf("Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    status = fork_and_execute(argv);
    if (status != 0)
        exit(EXIT_FAILURE);
    return (EXIT_SUCCESS);
}
/**
 * fork_and_execute - Fork off to python script
 * @argv: argument vector to pass
 */
int fork_and_execute(char **argv)
{
    pid_t pid;
    int status, i;

    status = 0;
    pid = fork();
    if (pid == 0)
    {
        i = execve("./pyth.py", argv, environ);
        if (i < 0)
        {
            return (2);
            exit(1);
        }
    }
    else
    {
        pid = wait(&status);
        if (WIFEXITED(status))
        {
            return (status);
        }
    }
    return (status / 256);
}
