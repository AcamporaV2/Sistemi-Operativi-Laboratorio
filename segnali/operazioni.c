#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


int a,b;

void somma(int sig)
{
    printf("La somma è %d\n", a+b);

}

void differnza(int sig)
{

    printf("La differenza è %d\n", a-b);

}


void uscita(int sig)
{
    printf("Uscita dal programma \n");
    exit(0);
}


int main()
{

    signal(SIGUSR1, somma);
    signal(SIGUSR2, differnza);
    signal(SIGINT, uscita);


    printf("Inserisci il primo numero (A): ");
    scanf("%d", &a);
    printf("Inserisci il secondo numero (B): ");
    scanf("%d", &b);


    printf("Aspetto segnali amico(CTRL+C per uscire)\n");
    while(1)
    {
        pause();
    }

}