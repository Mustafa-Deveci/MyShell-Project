#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char input[500];

int main(int argc,char *argv[])
{
    time_t t;
    system("clear");
    t = time( NULL );
    printf( "\nTime: %s\n", ctime( &t ));
    while(1){
        
        printf("myshell>>");
        memset(input, 0, sizeof(input));
        scanf("%[^\n]", input);
        getchar();
        
        if(strcmp(input,"help")==0){
                      printf("\nOperations:\n");
                      printf("cat - cat komutu sonrası yazdığınız şeyleri yazdırır.\n");
                      printf("clear - ekranı temizler \n");
                      printf("ls - klasör içindeki dosyaları görebilirsiniz.\n");
                      printf("exit - myShellden çıkış işlemi.\n");
                      printf("bash - sistemdeki bash programı çağrılır, bashteki normal işlemleri yapabilirsiniz, myshell için exit yazmanız yeterlidir\n");
                      printf("\n");

              }
        else if(strcmp(input,"bash")==0){
            system("bash");
        }
        else if(strcmp(input,"ls")==0){
            system("ls -ltr");
        }
        else if (strcmp(input, "clear")==0){
            system("clear");
        }
        else if (strcmp(input, "exit")==0){
            t = time( NULL );
            printf( "\nTime: %s\n", ctime( &t ));
            break;
        }
        else if(strstr(input, "cat" ) == input) {
            printf("%s ",input);
            printf("\n");
        }
               else{
            printf("Yanlış bir komut girdiniz, yardım için 'help' komutunu girebilirsiniz\n");
        }
    }
    return 0;
   
}
