#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "jogo.h"
#include "funcjogo.h"
#include "menu principal.h"
#define enter 13
#define riba 72
#define baixo 80

void main()
{
    int n=0, s=0;
    int y, w=1;
    while(w)
    {
        int c=175;
        char mov;
         titulo();
        printf("\n\n\n\n\n\n\n\t\t\t\t");
        (n==0)?printf("%c jogar\n\t\t\t\ttutorial\n\t\t\t\tranking\n\t\t\t\tsair",c):
        ((n==1)?printf("jogar\n\t\t\t\t%c tutorial\n\t\t\t\tranking\n\t\t\t\tsair",c):
         ((n==2)?printf("jogar\n\t\t\t\ttutorial\n\t\t\t\t%c ranking\n\t\t\t\tsair",c):
          printf("jogar\n\t\t\t\ttutorial\n\t\t\t\tranking\n\t\t\t\t%c sair",c)));

        mov=getch();fflush(stdin);

        switch(mov)
        {
        case riba:n--;system("CLS");break;
        case baixo:n++;system("CLS");break;
        default:n=n;system("CLS");break;
        }

        if(n > 3)
            n=0;
        else if(n < 0)
            n=3;

        if(mov == enter)
        {
            switch(n)
            {
            case 0:
                system("cls");
                jogo();
                printf("\npressione qualquer tecla para voltar ao menu\n");
                getch();fflush(stdin);
                system("CLS");
                break;
            case 1:
                tutorial();
                system("CLS");
                break;
            case 2:
                system("CLS");
                verranking();
                printf("\nPressione qualquer tecla para voltar ao menu...\n");
                getch();setbuf(stdin,NULL);
                system("CLS");
                break;
            case 3:
                system("CLS");
                while(w)
                {
                    printf("\n\n\n\n\n\n\n");
                    (s==0)?printf("\t%c sim\n\t nao",c):printf("\t sim\n\t%c nao",c);
                    mov=getch();fflush(stdin);
                    switch(mov)
                    {
                    case riba:s--;system("CLS");break;
                    case baixo:s++;system("CLS");break;
                    default:s=s;system("CLS");break;
                    }

                    if(s > 2)
                        s=0;
                    else if(s < 0)
                        s=2;
                    if(mov == enter)
                    {
                        if(s==1)
                        {
                            system("CLS");
                            break;
                        }
                        else if(s==0)
                        {
                            system("CLS");w=0;
                        }
                    }
                }
            }
        }
    }
}


