#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Funzione gestore per il segnale SIGINT (CTRL-C)
void gestore_ctrl_c(int segnale) {
    const char *messaggio = "non voglio terminare\n";
    write(STDOUT_FILENO, messaggio, sizeof("non voglio terminare\n") - 1);
}

int main() {
    // Registriamo il gestore per SIGINT usando signal()
    if (signal(SIGINT, gestore_ctrl_c) == SIG_ERR) {
        perror("Errore nella registrazione del segnale");
        exit(EXIT_FAILURE);
    }

    // Loop infinito per tenere il programma attivo
    while (1) {
        pause(); // Attende i segnali
    }

    return 0;
}
