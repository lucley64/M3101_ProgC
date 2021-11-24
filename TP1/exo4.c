#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
    
    pid_t pid = fork();
    int etat;

    switch(pid){
        case 0:
            execl("ps", "ps", NULL);
            exit(EXIT_SUCCESS);
            break;
        default:
            wait(&etat);
            if (WEXITSTATUS(etat) == EXIT_SUCCESS){
                printf("%d \n", etat);
            }
            exit(EXIT_SUCCESS);
            break;
    }

    return 0;
} // Pas d'affichage