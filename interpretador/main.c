#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAXLINE 8192

int execute(char * buf, char * parm){
    pid_t pid;
    int status;
    if((pid = fork()) < 0)
        printf("fork error\n");
    else if (pid == 0){
        execlp(buf, parm, (char *) 0);
        printf("couldn't execute: %s %s\n", buf, parm);
        return 127;
    }
    if((pid = waitpid(pid, &status, 0)) < 0)
        printf("waitpid error\n");
        printf("P> ");
        return 0;
}

int
main(void){
    char buf[MAXLINE];
    int r;
    printf("P> ");
    while (fgets(buf, MAXLINE, stdin) != NULL){
        buf[strlen(buf) - 1] = 0;
        if(!strcmp(buf, "indice"))
            if((r = execute("ls", NULL)) > 0) return r;
        if(!strcmp(buf, "volta"))
            if((r = execute("cd", "..")) > 0) return r;
    }
    return 0;
}
