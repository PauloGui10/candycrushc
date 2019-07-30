#ifndef FUNCJOGO_H_INCLUDED
#define FUNCJOGO_H_INCLUDED

void mudacor(int i);
void CursorMatriz(char *mov,int *x, int *y);
void CursorMatriz2(char *mov1, int *x1, int *y1);
void MostrarMatriz1(int m[6][6],int x, int y);
void MostrarMatriz2(int m[6][6],int x, int y, int x1, int y1);
void CriarMatriz(int *m);
void endgame();
void verif(int **m[6][6], int *pont);

#endif // FUNCJOGO_H_INCLUDED
