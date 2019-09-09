#include <stdio.h>
#include <stdlib.h>

// DADOS
typedef struct{
    int **m;
    int linhas;
    int colunas;

} Matriz;

//OPERAÇÕES (PROTÓTIPOS)

Matriz *matriz_cria(int linhas, int colunas);
void matriz_atribui(Matriz *m, int lin, int col, int valor);
void matriz_imprime(Matriz *m);
int matriz_acessa1(Matriz *m, int lin, int col);
void matriz_acessa2(Matriz *m, int lin, int col, int *end);
void matriz_destroi(Matriz *m);
/*
int matriz_linhas(Matriz* m);
int matriz_colunas(Matriz* m);
void matriz_map1(Matriz* m, void (*funcao)(int*)); //uma forma de aplicar uma alteração à todos os elementos da matriz.
void matriz_map2(Matriz* m, int (*funcao)(int));*/

//OPERAÇÕES (IMPLEMENTAÇÃO)

Matriz *matriz_cria(int linhas, int colunas)
{
  Matriz *mat = (Matriz *)malloc(sizeof(Matriz));
  mat->m = (int **)calloc(linhas, sizeof(int *));
  int i;
  for (i = 0; i < linhas; i++)
  {
    mat->m[i] = (int *)calloc(colunas, sizeof(int));
  }
  mat->linhas = linhas;
  (*mat).colunas = colunas;
  return mat;
}

void matriz_atribui(Matriz *m, int lin, int col, int valor)
{
  *((m->m[lin])+col) = valor;
}

int matriz_acessa1(Matriz *m, int lin, int col)
{
  int col_limite = (*m).colunas;
  int lin_limite = (*m).linhas;
  if (lin > lin_limite || col > col_limite)
  {
    printf("ACESSO INVÁLIDO: Não é possível acessar as coordenadas fornecidas\n\n");
    return 0;
  }
  else
  {
  int x = *((m->m[lin])+(col));
  return x;
  }
}

void matriz_acessa2(Matriz *m, int lin, int col, int *end)
{
  int col_limite = (*m).colunas;
  int lin_limite = (*m).linhas;
  if (lin > lin_limite || col > col_limite)
  {
    printf("ACESSO INVÁLIDO: Não é possível acessar as coordenadas fornecidas\n\n");
    *end = NULL;
  }
  else
  {
  *end = *((m->m[lin])+(col));
  }
}

void matriz_imprime(Matriz *m)
{
  printf("IMPRESSÃO DA MATRIZ\n");
  int lin = (*m).linhas;
  int col = (*m).colunas;
  for (int i = 0; i < lin; i++){
    for(int j = 0; j < col; j++){
      printf("%d\t", *((m->m[i])+j));
    }
    printf("\n");
  }
  printf("\n");
}

void matriz_destroi(Matriz *m)
{
  free(m);
}
