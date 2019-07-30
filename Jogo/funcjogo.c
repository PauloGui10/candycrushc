#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "jogo.h"
#define enter 13
#define esc 27
#define riba 72
#define baixo 80
#define esquerda 75
#define direita 77

void mudacor(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

void CriarMatriz(int **m[6][6])
{
    int i,j;
    srand( (unsigned)time(NULL) );
    for(i=0; i<6; i++)//criação da matriz
    {
        for(j=0; j<6; j++)
        {
            do{
            m[i][j] = rand()%10;
            Sleep(200);}
            while(m[i][j]==m[i+1][j] || m[i][j]==m[i-1][j] || m[i][j]==m[i][j+1] || m[i][j]==m[i][j-1]);
        }
    }
}


void MostrarMatriz1(int m[6][6], int x, int y)
{
    int i,j;
    for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
        {
            if(i==y && j==x)
            {
                mudacor(10);
                printf("%c%c",175, 175);
                mudacor(15);
                printf("%d",m[i][j]);
                mudacor(10);
                printf("%c%c",174, 174);
            }
            else
            {
                mudacor(15);
                printf("  %d  ", m[i][j]);
            }
        }
        printf("\n\n");
    }
}

void CursorMatriz(char *mov,int *x, int *y)
{
    (*mov)=getch();fflush(stdin);
    switch(*mov)
    {
    case riba:(*y)--;system("cls");break;
    case baixo:(*y)++;system("cls");break;
    case esquerda:(*x)--;system("cls");break;
    case direita:(*x)++;system("cls");break;
    default:system("cls");break;
    }
    if(*y>5)//paredes da matriz
        *y=0;
    else if(*y<0)
        *y=5;
    else if(*x>5)
        *x=0;
    else if(*x<0)
        *x=5;
}

void MostrarMatriz2(int m[6][6],int x,int y,int x1,int y1)
{
    int i,j;
    for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
        {
            if(i==y1 && j==x1)
            {
                mudacor(10);
                printf("%c%c",175, 175);
                mudacor(15);
                printf("%d",m[i][j]);
                mudacor(10);
                printf("%c%c",174,174);
            }
            else if(i==y && j==x)
            {
                mudacor(12);
                printf("  %d  ", m[i][j]);
            }
            else
            {
                mudacor(15);
                printf("  %d  ", m[i][j]);
            }
        }
        printf("\n\n");
    }
}

void CursorMatriz2(char *mov1, int *x1, int *y1)
{
    (*mov1)=getch();fflush(stdin);
    switch(*mov1)
    {
    case riba:(*y1)--;system("cls");break;
    case baixo:(*y1)++;system("cls");break;
    case esquerda:(*x1)--;system("cls");break;
    case direita:(*x1)++;system("cls");break;
    default:system("cls");break;
    }
    if((*y1)>5)//paredes da matriz
        *y1=0;
    else if((*y1)<0)
        *y1=5;
    else if((*x1)>5)
        *x1=0;
    else if((*x1)<0)
        *x1=5;

}

void endgame(int *pont)
{
    printf("\n\n\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("\n\t\t%cFIM DE JOGO%c",186,186);
    printf("\n\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,188);
    printf("\n\n\t SCORE:");
    mudacor(10);
    printf("%d", *pont);
    mudacor(15);
    getch();
}

void verif(int **m[6][6], int *pont)
{
    int i,j;
    for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
        {
            if(i==0)//primira linha
            {
                if(m[i][j]==m[i+1][j] && m[i][j]==m[i+2][j])
                {
                    (*pont)+=100;
                    m[i][j]=rand()%10;
                    m[i+1][j]=rand()%10;
                    m[i+2][j]=rand()%10;
                }//fim das pontuações verticais da primeira linha
                else if(m[i][j]==m[i][j+1] && m[i][j]==m[i][j-1])
                {
                    (*pont)+=100;
                    m[i][j]=rand()%10;
                    m[i][j+1]=rand()%10;
                    m[i][j-1]=rand()%10;
                }
                else if(m[i][j]==m[i][j+1] && m[i][j]==m[i][j+2])
                {
                    (*pont)+=100;
                    m[i][j]=rand()%10;
                    m[i][j+1]=rand()%10;
                    m[i][j+2]=rand()%10;
                }
                else if(m[i][j]==m[i][j-1] && m[i][j]==m[i][j-2])
                {
                    (*pont)+=100;
                    m[i][j]=rand()%10;
                    m[i][j-1]=rand()%10;
                    m[i][j-2]=rand()%10;
                }//fim das pontuações horizontais
            }
            else if(i==1)//segunda linha
            {
                if(m[i][j]==m[i+1][j] && m[i][j]==m[i-1][j])
                {
                    (*pont)+=100;
                    m[i][j]=rand()%10;
                    m[i+1][j]=rand()%10;
                    m[i-1][j]=rand()%10;
                }
                else if(m[i][j]==m[i+1][j] && m[i][j]==m[i+2][j])
                {
                    (*pont)+=100;
                    m[i+2][j]=m[i-1][j];

                    m[i][j]=rand()%10;
                    m[i+1][j]=rand()%10;
                    m[i-1][j]=rand()%10;
                }//fim das pontuações verticais
                else if(m[i][j]==m[i][j+1] && m[i][j]==m[i][j-1])
                {
                    (*pont)+=100;
                    m[i][j]=m[i-1][j];
                    m[i][j+1]=m[i-1][j+1];
                    m[i][j-1]=m[i-1][j-1];

                    m[i-1][j]=rand()%10;
                    m[i-1][j+1]=rand()%10;
                    m[i-1][j-1]=rand()%10;
                }
                else if(m[i][j]==m[i][j+1] && m[i][j]==m[i][j+2])
                {
                    (*pont)+=100;
                    m[i][j]=m[i-1][j];
                    m[i][j+1]=m[i-1][j+1];
                    m[i][j+2]=m[i-1][j+2];

                    m[i-1][j]=rand()%10;
                    m[i-1][j+1]=rand()%10;
                    m[i-1][j+2]=rand()%10;
                }
                else if(m[i][j]==m[i][j-1] && m[i][j]==m[i][j-2])
                {
                    (*pont)+=100;
                    m[i][j]=m[i-1][j];
                    m[i][j-1]=m[i-1][j-1];
                    m[i][j-2]=m[i-1][j-2];

                    m[i-1][j]=rand()%10;
                    m[i-1][j-1]=rand()%10;
                    m[i-1][j-2]=rand()%10;
                }//fim das pontuações horizontais
            }
            else if(i==2)//terceira linha
            {
                if(m[i][j]==m[i-1][j] && m[i][j]==m[i-2][j])
                {
                    (*pont)+=100;
                    m[i][j]=rand()%10;
                    m[i-1][j]=rand()%10;
                    m[i-2][j]=rand()%10;
                }
                else if(m[i][j]==m[i+1][j] && m[i][j]==m[i-1][j])
                {
                    (*pont)+=100;
                    m[i+1][j]=m[i-2][j];

                    m[i][j]=rand()%10;
                    m[i-2][j]=rand()%10;
                    m[i-1][j]=rand()%10;

                }
                else if(m[i][j]==m[i+1][j] && m[i][j]==m[i+2][j])
                {
                    (*pont)+=100;
                    m[i+1][j]=m[i-2][j];
                    m[i+2][j]=m[i-1][j];

                    m[i][j]=rand()%10;
                    m[i-2][j]=rand()%10;
                    m[i-1][j]=rand()%10;
                }//fim das pontuações verticais
                else if(m[i][j]==m[i][j+1] && m[i][j]==m[i][j-1])
                {
                    (*pont)+=100;
                    m[i][j]=m[i-1][j];
                    m[i][j+1]=m[i-1][j+1];
                    m[i][j-1]=m[i-1][j-1];

                    m[i-1][j]=rand()%10;
                    m[i-1][j+1]=rand()%10;
                    m[i-1][j-1]=rand()%10;
                }
                else if(m[i][j]==m[i][j+1] && m[i][j]==m[i][j+2])
                {
                    (*pont)+=100;
                    m[i][j]=m[i-1][j];
                    m[i][j+1]=m[i-1][j+1];
                    m[i][j+2]=m[i-1][j+2];

                    m[i-1][j]=rand()%10;
                    m[i-1][j+1]=rand()%10;
                    m[i-1][j+2]=rand()%10;
                }
                else if(m[i][j]==m[i][j-1] && m[i][j]==m[i][j-2])
                {
                    (*pont)+=100;
                    m[i][j]=m[i-1][j];
                    m[i][j-1]=m[i-1][j-1];
                    m[i][j-2]=m[i-1][j-2];

                    m[i-1][j]=rand()%10;
                    m[i-1][j-1]=rand()%10;
                    m[i-1][j-2]=rand()%10;
                }//fim das pontuações horizontais
            }
            else if(i==3)//quarta linha
            {
                if(m[i][j]==m[i+1][j] && m[i][j]==m[i-1][j])
                {
                    (*pont)+=100;
                    m[i][j]=m[i-3][j];
                    m[i+1][j]=m[i-2][j];

                    m[i-1][j]=rand()%10;
                    m[i-2][j]=rand()%10;
                    m[i-3][j]=rand()%10;
                }
                else if(m[i][j]==m[i-1][j] && m[i][j]==m[i-2][j])
                {
                    (*pont)+=100;
                    m[i][j]=m[i-3][j];

                    m[i-1][j]=rand()%10;
                    m[i-2][j]=rand()%10;
                    m[i-3][j]=rand()%10;
                }//fim das pontuações verticais
                else if(m[i][j]==m[i][j+1] && m[i][j]==m[i][j-1])
                {
                    (*pont)+=100;
                    m[i][j]=m[i-1][j];
                    m[i][j+1]=m[i-1][j+1];
                    m[i][j-1]=m[i-1][j-1];

                    m[i-1][j]=rand()%10;
                    m[i-1][j+1]=rand()%10;
                    m[i-1][j-1]=rand()%10;
                }
                else if(m[i][j]==m[i][j+1] && m[i][j]==m[i][j+2])
                {
                    (*pont)+=100;
                    m[i][j]=m[i-1][j];
                    m[i][j+1]=m[i-1][j+1];
                    m[i][j+2]=m[i-1][j+2];

                    m[i-1][j]=rand()%10;
                    m[i-1][j+1]=rand()%10;
                    m[i-1][j+2]=rand()%10;
                }
                else if(m[i][j]==m[i][j-1] && m[i][j]==m[i][j-2])
                {
                    (*pont)+=100;
                    m[i][j]=m[i-1][j];
                    m[i][j-1]=m[i-1][j-1];
                    m[i][j-2]=m[i-1][j-2];

                    m[i-1][j]=rand()%10;
                    m[i-1][j-1]=rand()%10;
                    m[i-1][j-2]=rand()%10;
                }//fim das pontuações horizontais
            }
            else if(i==4)//quinta linha
            {
                if(m[i][j]==m[i-1][j] && m[i][j]==m[i-2][j])
                {
                    (*pont)+=100;
                    m[i][j]=m[i-3][j];
                    m[i-1][j]=m[i-4][j];

                    m[i-2][j]=rand()%10;
                    m[i-3][j]=rand()%10;
                    m[i-4][j]=rand()%10;
                }//fim das pontuações verticais
                else if(m[i][j]==m[i][j+1] && m[i][j]==m[i][j-1])
                {
                    (*pont)+=100;
                    m[i][j]=m[i-1][j];
                    m[i][j+1]=m[i-1][j+1];
                    m[i][j-1]=m[i-1][j-1];

                    m[i-1][j]=rand()%10;
                    m[i-1][j+1]=rand()%10;
                    m[i-1][j-1]=rand()%10;
                }
                else if(m[i][j]==m[i][j+1] && m[i][j]==m[i][j+2])
                {
                    (*pont)+=100;
                    m[i][j]=m[i-1][j];
                    m[i][j+1]=m[i-1][j+1];
                    m[i][j+2]=m[i-1][j+2];

                    m[i-1][j]=rand()%10;
                    m[i-1][j+1]=rand()%10;
                    m[i-1][j+2]=rand()%10;
                }
                else if(m[i][j]==m[i][j-1] && m[i][j]==m[i][j-2])
                {
                    (*pont)+=100;
                    m[i][j]=m[i-1][j];
                    m[i][j-1]=m[i-1][j-1];
                    m[i][j-2]=m[i-1][j-2];

                    m[i-1][j]=rand()%10;
                    m[i-1][j-1]=rand()%10;
                    m[i-1][j-2]=rand()%10;
                }//fim das pontuações horizontais
            }
            else if(m[i][j]==m[i+1][j] && m[i][j]==m[i-1][j])//demais linhas
            {
                (*pont)+=100;
                m[i][j]=m[i-3][j];
                m[i-1][j]=m[i-4][j];
                m[i+1][j]=m[i-5][j];

                m[i-3][j]=rand()%10;
                m[i-4][j]=rand()%10;
                m[i-5][j]=rand()%10;
            }
            else if(m[i][j]==m[i+1][j] && m[i][j]==m[i+2][j])
            {
                (*pont)+=100;
                m[i][j]=m[i-3][j];
                m[i+1][j]=m[i-2][j];
                m[i+2][j]=m[i-1][j];

                m[i-3][j]=rand()%10;
                m[i-2][j]=rand()%10;
                m[i-1][j]=rand()%10;
            }
            else if(m[i][j]==m[i-1][j] && m[i][j]==m[i-2][j])
            {
                (*pont)+=100;
                m[i][j]=m[i-3][j];
                m[i-1][j]=m[i-4][j];
                m[i-2][j]=m[i-5][j];

                m[i-3][j]=rand()%10;
                m[i-4][j]=rand()%10;
                m[i-5][j]=rand()%10;
            }
            //fim das pontuações verticais
            else if(m[i][j]==m[i][j+1] && m[i][j]==m[i][j-1])
            {
                (*pont)+=100;
                m[i][j]=m[i-1][j];
                m[i][j+1]=m[i-1][j+1];
                m[i][j-1]=m[i-1][j-1];

                m[i-1][j]=rand()%10;
                m[i-1][j+1]=rand()%10;
                m[i-1][j-1]=rand()%10;
            }
            else if(m[i][j]==m[i][j+1] && m[i][j]==m[i][j+2])
            {
                (*pont)+=100;
                m[i][j]=m[i-1][j];
                m[i][j+1]=m[i-1][j+1];
                m[i][j+2]=m[i-1][j+2];

                m[i-1][j]=rand()%10;
                m[i-1][j+1]=rand()%10;
                m[i-1][j+2]=rand()%10;
            }
            else if(m[i][j]==m[i][j-1] && m[i][j]==m[i][j-2])
            {
                (*pont)+=100;
                m[i][j]=m[i-1][j];
                m[i][j-1]=m[i-1][j-1];
                m[i][j-2]=m[i-1][j-2];

                m[i-1][j]=rand()%10;
                m[i-1][j-1]=rand()%10;
                m[i-1][j-2]=rand()%10;
            }
            //fim das pontuações horizontais
        }
    }
    for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
        {
            if(m[i][j]>9)
                m[i][j]=rand()%10;
        }
    }
}
