// Created by mustafa deveci on 29.11.2022.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

char input[200];
FILE *f;

//execx ve writef komutları için string işlemede gerekli olan
char* subStringFinder(char* input, int subStart, int subEnd){
    int size=(subEnd-subStart) + 1;
    char* substr = malloc(size); // Gereken bayt sayısıyla malloc çağrılarak alan ayrıldı.
    memcpy(substr, &input[subStart],size); //memcpy işlevi boyut baytı kaynak adresinden başlayan nesneden hedef adresinden başlayan nesneye kopyalar.
    substr[size] = '\0'; // NULL (bos) karakter adıyla anılan değerdir. String'in bittiğini belirtir.
    return substr;
}
//Son kelimeyi subStringFinder'a atmak için nereden başlayacağını bulmamız için gerekli
int digitFinder(int number){
    if (number == 0)
        return 1;
    return floor (log10 (abs (number))) + 1;
}

int main(int argc,char *argv[],char ** envp)
{
    int i;
    int f;
    time_t t;
    system("clear");
    t = time( NULL );
    printf( "\nTime: %s\n", ctime( &t )); //while döngüsüne girmeden bir kere sistem saati yazdırıldı.
    while(1){
        
        printf("myshell>>");
        scanf("%[^\n]", input); //dizeleri okumak için scanf fonksiyonu kullanıldı, boşluklu dizeleri de okuyor ve yeni bir satır karakteri ile sona eriyor.
        getchar();   //enter tuşuna basılarak karakter okuma işlemi sonlanıyor, bunu yazmazsak sonsuz döngüye giriyor.
        if(strcmp(input,"help")==0){ //strcmp() fonksiyonu Str1 parametresi ile gösterilen karakter dizisini str2 parametresi ile gösterilen karakter dizisi ile karşılaştırır. Eğer her iki karakter dizisindeki tüm karakterler aynı ise sıfır değeri, aksi takdirde sıfırdan farklı bir değer geri döndürür.
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
        else if(strcmp(input,"bash")==0){
            f = fork();
            if(f == 0){
                execve("/bin/bash" , NULL , NULL);
            }else{
                wait(NULL);
            }
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
            printf("myShell'den çıkış yapıldı.\n");
            break;
        }
        else if (strcmp(subStringFinder(input,0,3), "cat ")==0){
            char *catInput = subStringFinder(input,4,strlen(input));
            printf("cat:%s ",catInput);
            printf("\n");
        }
        else if (strcmp(subStringFinder(input,0,5), "execx ")==0){
            int numberOfTime = atoi(subStringFinder(input,9,strlen(input))); // karakter dizisini int bir değere çevirir. Fonksiyon, önce boşluk karakteri içermeyen ilk karakteri bulana kadar boşluk atlar. Daha sonra, bu karakterden başlayarak, int değer içeriğine benzeyen karakterleri sayısal değerlere çevirir.
            if(strcmp(subStringFinder(input,6,8), "-t ") == 0){
                if(atoi(subStringFinder(input,8,strlen(input))) > 0) {
                    char *newargv[3];
                    newargv[0] = subStringFinder(input,10+digitFinder(numberOfTime),strlen(input));
                    newargv[1] = subStringFinder(input,9,strlen(input));
                    newargv[2] = NULL;
                    
                    f = fork();
                    if(f ==0){
                        i = execve("execx",newargv,envp);
                        perror("execx hatası");
                    } else {
                        wait(&i);
                    }
                    
                }
                else
                    printf("Usage -> -t times program\n");
            }
            else
                printf("Usage -> -t times program\n");
        }
        else if (strcmp(subStringFinder(input,0,6), "writef ")==0){
            if(strcmp(subStringFinder(input,7,9), "-f ") == 0){
                char *newargv[2];
                newargv[0] = subStringFinder(input,10,strlen(input));
                newargv[1] = NULL;
                f = fork();
                if(f ==0){
                    i = execve("writef",newargv,envp);
                    perror("execve hata");
                } else {
                    wait(&i);
                }
            }
        }
        else{
            printf("Yanlış bir komut girdiniz, yardım için 'help' komutunu girebilirsiniz\n");
        }
    }
    return 0;
}
