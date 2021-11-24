#include <stdio.h>
#include <unistd.h>

int main(void){
    
    int pid = fork();

    switch (pid){
        case 0:
            for (int i = 1; i<10; i++){
                printf("Nombre pairs : %d \n", (i*2));
                //sleep(1); //Le fils s'execute et le père après
            }
            break;
        default:
            for (int i = 1; i<10; i++){
                printf("Nombre impairs : %d \n", (i*(2+1)));
                sleep(1); //le fils commence à s'executer puis s'arrête le temps que le père se termine
            }
            break;
    }
    
    return 0;
}