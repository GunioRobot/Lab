#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAXLINE 8192

int
main(void){
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% ");
    while (fgets(buf, MAXLINE, stdin) != NULL){
        buf[strlen(buf) - 1] = 0;
        if((pid = fork()) < 0)
            printf("fork error\n");
        else if (pid == 0){
            execlp(buf, buf, (char *) 0);
            printf("couldn't execute: %s\n", buf);
            return 127;
        }
        if((pid = waitpid(pid, &status, 0)) < 0)
            printf("waitpid error\n");
            printf("%% ");
    }
    return 0;
}
