#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>



int main()
{
    char c, cwd[200];
    int fd;

    struct stat buf;
    struct dirent *drn;

    DIR *directory;

    getcwd(cwd, sizeof(cwd));

    if((directory = opendir(cwd)) == NULL)
    {
        printf("Errore OpenDir");
        exit(-1);
    }

    //printf("sono in directory");

    while((drn = readdir(directory)) != NULL)
    {
        if((lstat(drn->d_name, &buf)) < 0  )
        {
            printf("Errore Lstat");
        }
        if(S_ISLNK(buf.st_mode))
        {
            printf("Trovato il link %s\n", drn->d_name);
        }
        
    }
}