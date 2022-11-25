#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[500];

int main(int argc,char *argv[])
{

    while(1){
        
        printf("myshell>>");
        memset(input, 0, sizeof(input));
        scanf("%[^\n]", input);
        getchar();
        
        if(strcmp(input,"help")==0){
                

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
            break;
        }
        else if((input, "cat" ) == input) {

        }
               else{
            printf("Yanlış bir komut girdiniz, yardım için 'help' komutunu girebilirsiniz\n");
        }
    }
    return 0;
   
}
