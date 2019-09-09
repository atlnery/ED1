#include <stdio.h>
#include <stdlib.h>

// DADOS
typedef struct{
    int *m;
    int linhas;
    int colunas;
} Matriz;


//OPERAÇÕES (PROTÓTIPOS)

Matriz *matriz_cria(int linhas, int colunas);
void matriz_atribui(Matriz *m, int lin, int col, int valor);
int matriz_acessa1(Matriz *m, int lin, int col);
void matriz_acessa2(Matriz *m, int lin, int col, int *end);
void matriz_imprime(Matriz *m);
void matriz_destroi(Matriz *m);


//OPERAÇÕES (IMPLEMENTAÇÃO)

