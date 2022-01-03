#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <ctype.h>


int main(){
    int charAEnvoyer[2];
    char unChar;

    if(pipe(charAEnvoyer)==-1){
        printf("création du tube impossible\n");
        return -1;
    }


    pid_t pid = fork();
    
    
    switch (pid){
        case -1:
            printf("création du fils impossible\n");
            return -1;
        case 0:
            close(charAEnvoyer[1]);
            while(read(charAEnvoyer[0], &unChar, sizeof(char))!=0){
                printf("Le caractere saisit est %c\n", toupper(unChar));
            }
            printf("Fin du fils\n");
            close(charAEnvoyer[0]);
            break;

        default:
            close(charAEnvoyer[0]);
            unChar = getchar();
            while(!(unChar=='$')){
                write(charAEnvoyer[1], &unChar, sizeof(char));
                unChar = getchar();
            }
            printf("Fin du pere\n");
            close(charAEnvoyer[1]);
            break;
    }

    return 0;
}