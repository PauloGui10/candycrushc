#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "funcjogo.h"
#define enter 13
#define esc 27
#define riba 72
#define baixo 80
#define esquerda 75
#define direita 77

typedef struct{
char nome[25];
int pont;
} player;

player p[5], paux[5];

FILE *arq;

void jogo()
{
    int m[6][6];
    int i,j,x=0,y=0,x1,y1, w;
    int temp, cont=20, pont1=0;
    char mov, mov1, op;

    system("cls");

    CriarMatriz(&m);

    while(1)//seleção do primeiro confeito
    {
        w=1;
        MostrarMatriz1(m,x,y);
        printf("\n\tJogadas: %d", cont);
        printf("\n\tScore: %d", pont1);
        CursorMatriz(&mov,&x,&y);
        if(mov == 's')
        {
            system("cls");
            printf("Deseja mesmo sair do jogo? [s] ou [n]");
            op=getch();fflush(stdin);
            if(op == 's')
                break;
            else if(op == 'n'){
                continue;system("cls");}
        }

        if(mov == enter)//confirmar seleção do primeiro elemento
        {
            x1=x+1; y1=y; system("cls");

            while(w)//seleção do segundo elemento
            {
                MostrarMatriz2(m,x,y,x1,y1);
                printf("\n\tJogadas: %d", cont);
                printf("\n\tScore: %d", pont1);
                CursorMatriz2(&mov1,&x1,&y1);

                if(mov1 == enter)//confirmar seleção do segundo confeito e troca dos dois confeitos
                {
                    system("cls");
                    if(((x==x1+1 || x==x1-1) && y==y1) || ((y==y1+1 || y==y1-1) && x==x1))
                    {
                        temp = m[y][x];
                        m[y][x] = m[y1][x1];
                        m[y1][x1] = temp;
                        verif(&m,&pont1);
                        w=0; x=0; y=0; cont--;
                    }
                }
                else if(mov1 == esc)
                {
                    system("cls");w=0;
                }
                else
                    continue;
            }
        }
        if(cont==(-1))
        {
            system("cls");endgame(&pont1);
            addranking(&pont1);break;
        }
        else
            continue;
    }
    system("cls");
}

void addranking(int *x)
{
    int i=0, j, temp, q;
    char aux[25];
    //abrir o arquivo ranking com as structs para igualar ás structs auxiliar
    arq = fopen("ranking.bin","rb");

    if(arq == NULL)
    {
        printf("\tarquivo ainda não criado");
    }

    q=fread(p,sizeof(player), 5, arq);

    for(i=0;i<q;i++)//jogando os valores das structs do arquivo para as auxiliares
    {
        strcpy(paux[i].nome,p[i].nome);
        paux[i].pont = p[i].pont;
    }
    fclose(arq);//fechando o arquivo

    if((*x) > paux[4].pont)//organizando as structs auxiliares em ordem decrescente, caso o novo jogador entre no ranking
    {
        paux[4].pont = (*x);
        printf("\ndigite seu nome:");
        gets(paux[4].nome);fflush(stdin);
        system("cls");
        for(i=0;i<5;i++)
        {
            for(j=i+1;j<5;j++)
            {
                if(paux[i].pont <  paux[j].pont)
                {
                    temp = paux[i].pont;
                    paux[i].pont = paux[j].pont;
                    paux[j].pont = temp;

                    strcpy(aux,paux[i].nome);
                    strcpy(paux[i].nome,paux[j].nome);
                    strcpy(paux[j].nome,aux);
                }
            }
        }
    }
//fim da organização das structs auxiliares na ordem decrescente
    else
        {printf("\nVoce nao entrou no ranking, champs");}
//adicionando as structs auxiliares, todas organizadas, para as structs definitivas, que serão enviadas para o arquivo
    for(i=0;i<5;i++)
    {
        strcpy(p[i].nome,paux[i].nome);
        p[i].pont=paux[i].pont;
    }

//abrindo o arquivo novamente
    arq = fopen("ranking.bin","wb");

if(arq==NULL)
{
    printf("arquivo ainda não criado");
}

else
{
    for(i = 0; i < 5; i++)//preenchendo o arquivo com as structs definitivas
    {
        fwrite(&p[i], sizeof(player), 1, arq);
    }
    fclose(arq);
}

}

void verranking()
{
    int i=0, j=1, q;
    arq = fopen("ranking.bin","rb");

    if(arq == NULL)
    {
        printf("\tarquivo ainda nao criado");
    }

    q=fread(p,sizeof(player), 5, arq);
    printf("\n\t\t\t__________ºRANKINGº__________\n");
    for(i=0;i<q;i++)
    {
        printf("\t\t\t%dº %s __________ %d pts\n",j, p[i].nome,p[i].pont);
        j++;
    }
    getch();
    fclose(arq);
}
