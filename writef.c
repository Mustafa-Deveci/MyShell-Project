// Created by mustafa deveci on 29.11.2022.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
FILE *f;


int main(int argc,char *argv[]) {
    
    time_t t;
    t = time( NULL );
    char *fileName = argv[0];
    if (f = fopen(fileName, "a+")) // a+ ->> fileName ile alınan dosya varsa içine yazar yoksa yeni bi dosya oluşturup içine yazar.
    {
        fprintf (f, "Tarih: %spid: %d\nppid: %d\n\n", ctime( &t ), getpid (), getppid ());
        fclose (f);
    }
    return 0 ;
}
