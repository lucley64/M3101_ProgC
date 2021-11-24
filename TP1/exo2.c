#include <stdio.h>
#include <unistd.h>

int main(void){
    
    int pid = fork();

    switch (pid){
        case 0:
            for (int i = 0; i<10; i++){
                printf("Nombre pairs : %d \n", (i*2));
            }
            break;
        default:
            for (int i = 0; i<10; i++){
                printf("Nombre impairs : %d \n", (i*(2+1)));
            }
            break;
    }
    
    return 0;
}