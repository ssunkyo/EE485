#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <limits.h>
#include <sys/wait.h>

int main(void)
{
    int i, j, pid;
    char *token, command[2000], *arguments[10];

    if(fgets(command, sizeof(command), stdin) != NULL);
    command[strlen(command)-1] = 0;
    
    token = strtok(command, " ");
    if(token == NULL) {exit(-1);}

    else if(token == "exit") {exit(-1);}
    
    arguments[0] = token;
    for(i = 1; i<10; i++)
    {
        token = strtok(NULL, " ");
        if(token == NULL)
            break;
        arguments[i] = token;
    }
    arguments[i] = NULL;

    pid = fork();
    if (pid != 0)
    {
        wait(NULL);
    }
    else
    {
	for(j = 0; j < i; j++)     
	{
		if(execvp(arguments[0], arguments) != -1);
	}
    }
}
