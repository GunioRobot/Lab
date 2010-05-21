#include <unistd.h>
#include <stdio.h>

#define BUFFSIZE 8192
#define STDIN 0
#define STDOUT 1
#define STDERR 2

int
main(void){
    int n;
    char buf[BUFFSIZE];

    while((n = read(STDIN, buf, BUFFSIZE)) > 0)
        if (write(STDOUT, buf, n) != n)
            printf("write error");
    if(n < 0)
        printf("read error");

    return 0;
}
