#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int linha;
    int coluna;
    int valor;
    struct no* ant;
    struct no* prox;
    struct no* up;
    struct no* down;
}No;

typedef struct{
    No** linhas;    //ponteiro para o vetor cujas células são ponteiros de nós
    No** colunas;    //ponteiro para o vetor cujas células são ponteiros de nós
    int nlin;    //Quantidade de linhas da matriz
    int ncol;    //Quantidade de colunas da matriz
}Matriz;

typedef struct no* ptr;

/********************
    PROTÓTIPOS
********************/
Matriz* matriz_criar(int qtd_linhas, int qtd_colunas);
int matriz_atribuir(Matriz* m, int linha, int coluna, int valor);
int matriz_acessar(Matriz* m, int linha, int coluna);
void matriz_imprimir(Matriz* m);
void matriz_desalocar(Matriz* m);

//AUXILIARES
No* cria_sentinela();
int atribui_existe_no(Matriz* m, int linha, int coluna, int valor);
No* criar(int linha, int coluna, int valor, ptr acima, ptr esquerda);
int busca_acima(Matriz* m, int coluna, int linha, ptr* acima);
int busca_esquerda(Matriz* m, int linha, int coluna, ptr* esquerda);

//Cria uma matriz vazia e devolve seu endereço de memória.
Matriz* matriz_criar(int qtd_linhas, int qtd_colunas){
  if(qtd_linhas < 0 || qtd_colunas < 0) return NULL;

  Matriz* matriz = (Matriz*)malloc(sizeof(Matriz));
  matriz->nlin = qtd_linhas;
  matriz->ncol = qtd_colunas;

  No** linhas = (No**)calloc(qtd_linhas, sizeof(int*));
  No** colunas = (No**)calloc(qtd_colunas, sizeof(int*));

  matriz->linhas = linhas;
  matriz->colunas = colunas;

  for(int i = 0; i < qtd_linhas; i++){
    No* sentinela = cria_sentinela();
    matriz->linhas[i] = sentinela;
  }

  for(int i = 0; i < qtd_colunas; i++){
    No* sentinela = cria_sentinela();
    matriz->colunas[i] = sentinela;
  }
  return matriz;
}

No* cria_sentinela(){
  No* sentinela = (No*)malloc(sizeof(No));
  sentinela->linha = sentinela->coluna = -1;
  sentinela->ant = sentinela->prox = sentinela;
  sentinela->up = sentinela->down = sentinela;

  return sentinela;
}

//Insere o <valor> na matriz <m> na linha <linha> e coluna <coluna>. Caso a posição já exista, substitua o valor da célula.
int matriz_atribuir(Matriz* m, int linha, int coluna, int valor){
  if(linha  > (m->nlin)) {return -1;}
  if(coluna > (m->ncol)) {return -1;}

  int x = atribui_existe_no(m, linha, coluna, valor); //verifica se já existe no na posição;
  //printf("VALOR DE A %d\n",x);

  if (x == 0){ //criar um novo nó
    ptr acima, esquerda;
    busca_acima(m, coluna, linha, &acima);
    busca_esquerda(m, linha, coluna, &esquerda);

    No* novo = criar(linha, coluna, valor, acima, esquerda);

    acima->down->up = novo; acima->down = novo;
    esquerda->prox->ant = novo; esquerda->prox = novo;
  }
}

int atribui_existe_no(Matriz* m, int linha, int coluna, int valor){
  int a = 0; int ctrl = 1;

  ptr aux = m->linhas[linha];

  while(ctrl != -1){
    aux = aux->prox;
    ctrl = aux->coluna;
    if(aux->coluna == coluna){
      a = 1;
      aux->valor = valor;
      break;
    }
  }
  return a;
}

int busca_acima(Matriz* m, int coluna, int linha, ptr* acima){
  *acima = m->colunas[coluna];

  if (coluna == 0) return 0;
  *acima = (*acima)->down;

  for(int i = 0; i < linha; i++){
    if ((*acima)->down->linha > linha){
      break;
    }
    *acima = (*acima)->down;
  }
}

int busca_esquerda(Matriz* m, int linha, int coluna, ptr* esquerda){
  *esquerda = m->linhas[linha];

  //printf("%d l, %d\n",linha, coluna);

  if (linha == 0) return 0;

  *esquerda= (*esquerda)->prox;
  for(int i = 0; i < coluna; i++){
    if ((*esquerda)->prox->coluna > coluna){
      break;
    }
    *esquerda = (*esquerda)->prox;
  }
}

No* criar(int linha, int coluna, int valor, ptr acima, ptr esquerda){
  No* no = (No*)malloc(sizeof(No));
  no->linha = linha;
  no->coluna = coluna;
  no->valor = valor;

  no->ant = esquerda; no->prox = esquerda->prox;
  no->up = acima; no->down = acima->down;

  return no;
}
//Devolve o valor correspondente a linha e coluna solicitada. Faça a validação dos índices. Caso a posição solicitada esteja fora do intervalo, devolva zero.
int matriz_acessar(Matriz* m, int linha, int coluna){
  if(linha  > (m->nlin)) {return 0;}
  if(coluna > (m->ncol)) {return 0;}

}


//Imprime os valores da matriz na tela. Cada linha deve ser impressa em uma linha diferente e os elementos separados por espaço ou tabulação. Os elementos não representados na matriz (valor zero), também devem ser impressos.
void matriz_imprimir(Matriz* m){
  if(m == NULL) printf("MATRIZ VAZIA!\n");

  else{
    for(int i = 0; i < m->nlin; i++){
      ptr aux = m->linhas[i]->prox;
      for(int j = 0; j < m->ncol; j++){
          printf("%d\t",aux->valor);
          aux = aux->prox;
      }
      printf("\n");
    }
    printf("\n");
  }

}

//Libera toda memória alocada dinamicamente para a matriz.
void matriz_desalocar(Matriz* m){

}
