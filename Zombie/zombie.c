#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();


    if(pid < 0)
    {
        perror("Fork Fallita");
        exit(EXIT_FAILURE);

    }


    if(pid == 0) //PROCESSO FIGLIO     
    {
        printf("Figlio con %d PID Termina\n", getpid());
        exit(0);

    } else 

    {
        printf("Padre ha %d PID, Figlio ha %d PID\n",getpid(), pid);

        printf("Attendo 5 secondi senza fare nulla così figlio è zombie\n");
        sleep(5);

        printf("\nEseguo comando 'ps -o pid,ppid,stat,cmd | grep %d'\n\n", pid);
        char pid_str[11];
        snprintf(pid_str, sizeof(pid_str), "%d", pid);


        execlp("ps", "ps", "-o","pid,ppid,stat,cmd", NULL); //Comando, ARGV, Opzione colonne, colonne da mostrare, fine lista
        perror("execelp fallita");
        exit(EXIT_FAILURE);

    }
}