#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
	int pid = getpid();

	printf("Je suis le processus numéro : %d\n", pid);

	pid = fork();

	printf("Fork m'a renvoyé la valeur : %d\n", pid);

	printf("Je suis le processus numéro : %d %s %d \n", getpid(), ", et mon père est le processus numéro", getppid());

	exit(EXIT_SUCCESS);
	

	return 0;
}
