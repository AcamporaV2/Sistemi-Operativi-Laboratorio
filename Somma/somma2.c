#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{

    int input_fd = open("testfile.txt", O_RDONLY);
    if(input_fd < 0)
    {
        write(2,"Errore apertura file\n",22);
        exit(1);
    }

    int output_fd = open("outputfile.txt", O_WRONLY);
    if (output_fd < 0) 
    {
        write(2, "File non trovato o errore apertura\n", 36);
        exit(1);
    }

    dup2(input_fd, STDIN_FILENO);
    dup2(output_fd, STDOUT_FILENO);
    close(input_fd);
    close(output_fd);





    int n1,n2;
    char buffer[3];
    char risultato[20];


    while (1)
    {
        int r1 = read(0, buffer, 2);

        if(r1 <= 0) break;

        if(buffer[0] == '-' && buffer[1] == '1')
        {
            write(1, "Uscita.\n",8);
            break;
        }

        n1 = buffer[0] - '0';


        int r2 = read(0,buffer,2);

        if(r1 <= 0) break;

        n2 = buffer[0] - '0';

        int somma = n1 + n2;

        risultato[0] = somma + '0';

        risultato[1] = '\n';

        int len = snprintf(risultato, sizeof(risultato), "Somma: %d\n", somma);
        write(STDOUT_FILENO, risultato, len);

    }

    return 0;
    
}