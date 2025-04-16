#include <unistd.h>
#include <stdlib.h>


int main()
{
    int n1,n2;
    char buffer[3];
    char risultato[2];


    while (1)
    {
        write(1, "Inserisci il primo numero:", 27);
        int r1 = read(0, buffer, 2);

        if(r1 <= 0) break;

        if(buffer[0] == '-' && buffer[1] == '1')
        {
            write(1, "Uscita.\n",8);
            break;
        }

        n1 = buffer[0] - '0';


        write(1, "inserisci il secondo numero:",29);
        int r2 = read(0,buffer,2);

        if(r1 <= 0) break;

        n2 = buffer[0] - '0';

        int somma = n1 + n2;

        risultato[0] = somma + '0';

        risultato[1] = '\n';

        write(1,"Somma: ",7);
        write(1, risultato, 2);

    }

    return 0;
    
}
