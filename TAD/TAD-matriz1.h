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
Matriz* matriz_multiplica(Matriz* a, Matriz* b);
int matriz_ehQuadrada(Matriz* m);
int matriz_ehDiagonal(Matriz* m);
int matriz_ehIdentidade(Matriz* m);
Matriz* matriz_transposta(Matriz* m);
Matriz* matriz_oposta(Matriz* m);
int matriz_colunas(Matriz* m);
int matriz_linhas(Matriz* m);
int* obter_vetorlinha(Matriz *m, int linha);
int* obter_vetorcoluna(Matriz *m, int coluna);

/*
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

int matriz_colunas(Matriz* m)
{
  return m->linhas;
}

int matriz_linhas(Matriz* m)
{
  return m->colunas;
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

Matriz* matriz_multiplica(Matriz* a, Matriz* b)
{
  if ((*a).colunas == b->linhas)
  {
    Matriz *c = matriz_cria(a->linhas, b->colunas);
    for (int i = 0; i < (*c).linhas; i++)
    {
      for(int j = 0; j < (*c).colunas; j++)
      {
      int k = 0;
      *((c->m[i])+j) = *((a->m[i])+k) * *((b->m[k])+j) + *((a->m[i])+k+1) * *((b->m[k+1])+j);
      }
    }
    return c;
  }
  else
  {
    return NULL;
  }
}

int matriz_ehQuadrada(Matriz* m)
{
  if((*m).linhas == (*m).colunas){
    return 1;
  }
  else{
    return 0;
  }
}

int matriz_ehDiagonal(Matriz* m)
{
  int x1 = matriz_ehQuadrada(m);
  if (x1 == 0){
    return 0;
  }
  else
  {
    int cont = 0;
    for(int i = 0; i < m->linhas; i++)
    {
      for(int j = 0; j < m->colunas; j++)
      {
        if(i != j && *((m->m[i])+j) != 0)
        {
          return 0;
        }
        else{
          cont++;
        }
      }
    }
    if (cont == (m->linhas * m->colunas)){
      return 1;
    }
  }
}

int matriz_ehIdentidade(Matriz* m)
{
  int x = matriz_ehDiagonal(m);
  if(x == 0)
  {
    return 0;
  }
  else
  {
    int cont = 0;
    for(int i = 0; i < m->linhas; i++)
    {
      for (int j = 0; j < m->colunas; j++)
      {
        if(i == j && *((m->m[i])+j) == 1)
        {
          cont++;
        }
      }
    }
    if(cont == m->linhas){
      return 1;
    }
    else{
      return 0;
    }
  }
}

Matriz* matriz_transposta(Matriz* m)
{
  Matriz* t = matriz_cria(m->colunas, m->linhas);
  for (int i = 0; i < t->linhas; i++)
  {
    for(int j = 0; j < t->colunas; j++)
    {
      *((t->m[i])+j) =   *((m->m[j])+i);
    }
  }
  return t;
}

Matriz* matriz_oposta(Matriz* m)
{
  Matriz* copy = matriz_cria(m->linhas, m->colunas);
  for(int i = 0; i < m->linhas; i++)
  {
    for(int j = 0; j < m->colunas; j++)
    {
    *((copy->m[i])+j) =   (-1) * *((m->m[j])+i);
    }
  }
  return copy;
}

int* obter_vetorlinha(Matriz *m, int linha)
{
  int* v = (int*)calloc(m->linhas, sizeof(int));
  for(int i = 0; i < m->linhas; i++){
    v[i] = *((m->m[linha])+i);
  }
  return v;
}

int* obter_vetorcoluna(Matriz *m, int coluna)
{
  int* v = (int*)calloc(m->colunas, sizeof(int));
  for(int i = 0; i < m->colunas; i++){
    v[i] = *((m->m[i])+coluna);
  }
  return v;
}

void matriz_destroi(Matriz *m)
{
  free(m);
}
