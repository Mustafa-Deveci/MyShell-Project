// Created by mustafa deveci on 29.11.2022.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

FILE *file;


//execx komutu için string işlemede gerekli
char* subStringFinder(char* input, int subStart, int subEnd){
    int size=(subEnd-subStart) + 1;
    char* substr = malloc(size); // Gereken bayt sayısıyla malloc çağrılarak alan ayrıldı.
    memcpy(substr, &input[subStart],size); //memcpy işlevi boyut baytı kaynak adresinden başlayan nesneden hedef adresinden başlayan nesneye kopyalar.
    substr[size] = '\0'; // NULL (bos) karakter adıyla anılan değerdir. String'in bittiğini belirtir.
    return substr;
}

int digitFinder(int number){
    if (number == 0)
        return 1;
    return floor (log10 (abs (number))) + 1;
}

int main(int argc,char *argv[]) {
    
    int f;
    time_t t;
    t = time( NULL );
    char *newInput = argv[0];
    int number = atoi(argv[1]);
    for(int i=0;i<number;i++){
        if(strcmp(newInput,"help")==0){
            printf("\nOperations:\n");
            printf("cat - cat komutu sonrası yazdığınız şeyleri yazdırır.\n");
            printf("clear - ekranı temizler \n");
            printf("ls - klasör içindeki dosyaları görebilirsiniz.\n");
            printf("exit - myShellden çıkış işlemi.\n");
            printf("bash - sistemdeki bash programı çağrılır, bashteki normal işlemleri yapabilirsiniz, myshell için exit yazmanız yeterlidir\n");
            printf("execx - execx -t kaç kere çalıştırmak istediğiniz) (çalıştırmak istediğiniz programı giriniz) örnek kullanım execx -t 3 help -> help komutu 3 kere çalıştırılır.\n");
            printf("writef - writef -f (filename) filename verilir dosya varsa içine ekleme yapılır yoksa oluşturulup içine yazar. örnek kullanım writef -f deneme -> deneme dosyayı olmadığı için içine oluşturulup sistem tarihi, pid, ppid değerleri yazıldı.\n");
            printf("\n");
        }
        else if(strcmp(newInput,"bash")==0){
            f = fork();
            if(f == 0){
                execve("/bin/bash" , NULL , NULL);
            }else{
                wait(NULL);
            }
        }
        else if(strcmp(newInput,"ls")==0){
            system("ls -ltr");
        }
        else if (strcmp(newInput, "clear")==0){
            system("clear");
        }
        else if (strcmp(newInput, "exit")==0){
            t = time( NULL );
            printf( "\nTime: %s\n", ctime( &t ));
            break;
        }
        else if (strcmp(subStringFinder(newInput,0,3), "cat ")==0){
            char *catInput = subStringFinder(newInput,4,strlen(newInput));
            printf("cat:%s ",catInput);
            printf("\n");
        }
        else if (strcmp(subStringFinder(newInput,0,6), "writef ")==0){
            if(strcmp(subStringFinder(newInput,7,9), "-f ") == 0){
                char *fileName = subStringFinder(newInput,10,strlen(newInput));
                char *str = ctime (&t);
                if (file = fopen(fileName, "a+"))
                {
                    fprintf (file, "Tarih: %spid: %d\nppid: %d\n\n", str, getpid (), getppid ());
                    fclose (file);
                }
                
                
            }
        }
    }
    return 0;
}
