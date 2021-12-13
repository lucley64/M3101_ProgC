#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
    pid_t pid = fork(void);

    switch (pid){
        case 0:
            printf("Processus Fils");
            return 0;
            break;

        default:
            printf("Processus Pere");
            return 0;
            break;
    }

    return 0;
}