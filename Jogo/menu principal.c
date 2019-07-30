#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "jogo.h"
#include "funcjogo.h"
#define enter 13
#define riba 72
#define baixo 80

void tutorial()
{
    int c=175, w=1, n=0, s=0;
    char mov;
    while(w)
    {
        printf("\n\n\n\n\n\n\n\t\t\t\t");
        (n==0)?printf("%c controles\n\t\t\t\tcomo funciona o jogo\n\t\t\t\tvoltar ao menu principal",c):
        ((n==1)?printf("controles\n\t\t\t\t%c como funciona o jogo\n\t\t\t\tvoltar ao menu principal",c):
         printf("controles\n\t\t\t\tcomo funciona o jogo\n\t\t\t\t%c voltar ao menu principal",c));
        mov=getch();fflush(stdin);

        switch(mov)
        {
        case riba:n--;system("CLS");break;
        case baixo:n++;system("CLS");break;
        default:n=n;system("CLS");break;
        }
        if(n > 2)
            n=0;
        else if(n < 0)
            n=2;
        if(mov == enter)
        {
            switch(n)
            {
            case 0:
                system("cls");
                controles();
                system("CLS");
                break;
            case 1:
                funciona();
                system("CLS");
                break;
            case 2:
                system("CLS");
                while(1)
                {
                    printf("\n\n\n\n\n\n\n");
                    (s==0)?printf("\t%c sim\n\t nao",c):printf("\t sim\n\t%c nao",c);
                    mov=getch();
                    fflush(stdin);
                    switch(mov)
                    {
                    case riba:s--;system("CLS");break;
                    case baixo:s++;system("CLS");break;
                    default:s=s;system("CLS");break;
                    }
                    if(s > 1)
                        s=0;
                    else if(s < 0)
                        s=1;
                    if(mov == enter)
                    {
                        if(s==1)
                        {
                            system("CLS");break;
                        }
                        else if(s==0)
                        {
                            system("CLS");w=0;break;
                        }
                    }
                }
            }
        }
    }
}

void controles()
{
    printf("\n\t\t\t__________ºCONTROLES DO JOGOº__________");
    printf("\n\t-> setas direcionais = move o cursor para selecionar um numero");
    printf("\n\t-> Enter = confirmar a escolha dos numeros");
    printf("\n\t-> Esc = cancela escolha do primeiro numero");
    printf("\n\t-> S = voltar ao menu principal do jogo");
    printf("\n\n\tPressione qualquer tecla para voltar ao menu tutorial...");
    getch();fflush(stdin);
}

void funciona()
{
    printf("\n\t\t\t__________ºComo funciona o jogoº__________");
    printf("\n\tO jogador tem um número fixo de 20 jogadas para alcançar a maior pontuação possivel");
    printf("\n\tO jogador pode efetuar jogadas em qualquer uma das vizinhanças(uma posição ao lado, ou acima)");
    printf("\n\tAs cinco maiores pontuações são adicionadas ao ranking, ao final de suas respectivas rodadas");
    printf("\n\n\tPressione qualquer tecla para voltar ao menu tutorial...");
    getch();fflush(stdin);
}



void titulo(){

   mudacor(10);printf("\n    &&&&&&&&&&&          AAAAA           NNNN    NN      #######       YY    YY   ");
   mudacor(10);printf("\n    &&                  AAAAAAA          NN NN   NN      ##    ##       YY  YY      ");
   mudacor(10);printf("\n    &&                 AAAAAAAAA         NN  NN  NN      ##     ##        YY     ");
   mudacor(10);printf("\n    &&                AA       AA        NN   NN NN      ##     ##        YY       ");
   mudacor(10);printf("\n    &&&&&&&&&&&      AA         AA       NN    NNNN      ########         YY   \n    ");



   mudacor(11);printf("\n \t   &&&&&&&&&&   #######    UU    UU    SSSSSSS     HH     HH                                       ");
   mudacor(11);printf("\n \t   &&           #######    UU    UU    SS          HH     HH                                       ");
   mudacor(11);printf("\n \t   &&           ######     UU    UU    SSSSSSS     HHHHHHHHH                                       ");
   mudacor(11);printf("\n \t   &&           ##  ##     UU    UU         SS     HH     HH                                       ");
   mudacor(11);printf("\n \t   &&&&&&&&&&&  ##   ###   UUUUUUUU    SSSSSSS     HH     HH                                       ");

   mudacor(10);







}


