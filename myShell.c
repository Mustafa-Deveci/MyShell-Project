#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

char input[200];

//execx komutu için string işlemede gerekli fonk yazılacak
char* subStringFinder(char* input, int subStart, int subEnd){
    int size=(subEnd-subStart) + 1;
    //
    return substr;
}
//Son kelimeyi subStringFinder'a atmak için nereden başlayacağını bulmamız için gerekli
int digitFinder(int number){
    if (number == 0)
        return 1;
    return floor (log10 (abs (number))) + 1;
}

int main()
{
    time_t t;
    system("clear");
    t = time( NULL );
    printf( "\nTime: %s\n", ctime( &t )); //while döngüsüne girmeden bir kere sistem saati yazdırıldı.
    while(1){
        
        printf("myshell>>");
        scanf("%[^\n]", input); //dizeleri okumak için scanf fonksiyonu kullanıldı, boşluklu dizeleri de okuyor ve yeni bir satır karakteri ile sona eriyor.
        getchar();   //enter tuşuna basılarak karakter okuma işlemi sonlanıyor, bunu yazmasak sonsuz döngüye giriyor.
        if(strcmp(input,"help")==0){ //strcmp() fonksiyonu Str1 parametresi ile gösterilen karakter dizisini str2 parametresi ile gösterilen karakter dizisi ile karşılaştırır. Eğer her iki karakter dizisindeki tüm karakterler aynı ise sıfır değeri, aksi takdirde sıfırdan farklı bir değer geri döndürür.
            printf("\nOperations:\n");
            printf("cat - cat komutu sonrası yazdığınız şeyleri yazdırır.\n");
            printf("clear - ekranı temizler \n");
            printf("ls - klasör içindeki dosyaları görebilirsiniz.\n");
            printf("exit - myShellden çıkış işlemi.\n");
            printf("bash - sistemdeki bash programı çağrılır, bashteki normal işlemleri yapabilirsiniz, myshell için exit yazmanız yeterlidir\n");
            printf("execx - Usage -> -t times program (kaç kere çalıştırmak istediğinizi ve çalıştırmak istediğiniz komutu giriniz)\n");
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
            printf("myShell'den çıkış yapıldı.");
            break;
        }
        else if(strstr(input, "cat" ) == input) {
            printf("%s ",input);
            printf("\n");
        }
        else if (strcmp(subStringFinder(input,0,5), "execx ")==0){
            for(int i=0;i</*  */;i++){
                
                if(strcmp(newInput,"help")==0){
                    printf("\nOperations:\n");
                    printf("cat - cat komutu sonrası yazdığınız şeyleri yazdırır.\n");
                    printf("clear - ekranı temizler \n");
                    printf("ls - klasör içindeki dosyaları görebilirsiniz.\n");
                    printf("exit - myShellden çıkış işlemi.\n");
                    printf("bash - sistemdeki bash programı çağrılır, bashteki normal işlemleri yapabilirsiniz, myshell için exit yazmanız yeterlidir\n");
                    printf("execx - Usage -> -t times program (kaç kere çalıştırmak istediğinizi ve çalıştırmak istediğiniz komutu giriniz)\n");
                    printf("\n");
                }
                else if(strcmp(newInput,"bash")==0){
                    system("bash");
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
                else if(strstr(newInput, "cat" ) == newInput) {
                    printf("%s ",newInput);
                    printf("\n");
                }
            }
            
            else if (strcmp(subStringFinder(input,0,6), "writef ")==0){
                
            }
            else{
                printf("Yanlış bir komut girdiniz, yardım için 'help' komutunu girebilirsiniz\n");
            }
        }
        return 0;
    }
}
