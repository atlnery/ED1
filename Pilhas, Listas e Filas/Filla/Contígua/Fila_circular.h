#include <stdio.h>
#include <stdlib.h>
#define TAM 5


//INSERÇÃO NO FINAL E REMOÇÃO NO INÍCIO

typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

typedef struct{
    Tipo* vetor; //contígua;
    int tam;
    int inicio; //posição
    int fim; //não armazena elemento. EX. 1,2,3 fim é na posição 3. Pode acontecer da final ser 0.
}Fila;


/* ATENÇÃO COM INSERÇÃO QUANDO TODAS AS POSIÇÕES DENTRO DO VETOR FOREM OCUPADAS, USAR DISTÂNCIA DE DOIS tabela rest*/
/*USAR MOD NO INCREMENTO E DECREMENTO*/


Fila* fila_criar();//cria a fila
void fila_desalocar(Fila* f);
Boolean fila_inserir(Fila* f, Tipo elemento); //pronto
Tipo fila_remover1(Fila* f); //devolução do elemento removido;
Boolean fila_remover2(Fila* f, Tipo* endereco); //onde armazenar elemento removido
Boolean fila_primeiro(Fila* f, Tipo* endereco); //mostrar qual é o primeiro elemento da fila
int fila_tamanho(Fila* f); //pronto
int fila_contem(Fila* f, Tipo elemento); //verificar se tem elemento lá dentro
void fila_imprimir(Fila* f); //pronto
void aumenta_fila(Fila *f); //pronto
void aumenta_fila_especial(Fila* f); //casos que fim < inicio


Fila* fila_criar(){
  Fila* nova = (Fila*)malloc(sizeof(Fila));
  nova->vetor = (Tipo*)calloc(TAM, sizeof(Tipo));
  nova->tam = TAM;
  nova->inicio = 0;
  nova->fim = 0;
}

void fila_desalocar(Fila* f){
  if (f == NULL) return;

  free(f->vetor);
  free(f);
}

int fila_contem(Fila* f, Tipo elemento){
  if (f == NULL) return -1;

  if (f->fim == f->inicio) return -1;

  aumenta_fila(f); //quase uma ordenação
  f->tam -= 5; //diminui o valor

  for (int pos = 0; pos < f->tam; pos++){
    if(f->vetor[pos] == elemento)
      return pos;
  }
  return -1;
}

int fila_tamanho(Fila* f){
  if (f == NULL) return -1;

  return f->tam;
}

Boolean fila_primeiro(Fila* f, Tipo* endereco){
  if (f == NULL) return false;

  *endereco = f->vetor[f->inicio];
  return true;
}

void aumenta_fila(Fila *f){
  Tipo* copia = (Tipo*)calloc(f->tam+5, sizeof(Tipo));
  int i, j;

  for (i = f->inicio, j = 0; i < f-> fim; i++, j++){
    copia[j] = f->vetor[i];
  }

  f->vetor = (Tipo*)calloc(f->tam+5, sizeof(Tipo));//não dobei, apenas acrescentei 5

  for (i = 0; i < j; i++){
    f->vetor[i] = copia[i];
  }

  f->tam += 5;
  f->inicio = 0;
  f->fim = i;
  free(copia);
}

void aumenta_fila_especial(Fila* f){
  Tipo* copia = (Tipo*)calloc(f->tam+5, sizeof(Tipo));
  int j, i;
  for (i = f-> inicio, j = 0; i < f->tam; i++, j++){
    copia[j] = f->vetor[i];
  }
  for (i = 0; i < f->fim; i++, j++){
    copia[j] = f->vetor[i];
  }

  f->vetor = (Tipo*)calloc(f->tam+5, sizeof(Tipo));

  for (i = 0; i < j; i++){
    f->vetor[i] = copia[i];
  }

  f->tam += 5;
  f->inicio = 0;
  f->fim = i;
  free(copia);
} //casos que fim < inicio

Boolean fila_inserir(Fila* f, Tipo elemento){
  if (f == NULL) return false;

  if (f->fim == f->tam && f->inicio != 0){ //caso que estourou e inicio não é mais 0 (teve remoções);
    f->fim = 0;
    f->vetor[f->fim] = elemento;

    if (f->inicio - f->fim == 1){
      aumenta_fila_especial(f);
    }
    else {f->fim++;}
    return true;
  }

  if(f->inicio == 0 || f->inicio < f->fim && f->fim < (f->tam)){ //caso comum;
    f->vetor[f->fim] = elemento;
    f->fim++;
  }

  if (f->inicio == 0 && f->fim == f->tam){
    aumenta_fila(f);
    return true;
  }

  if (f->fim < f->inicio){
    f->vetor[f->fim] = elemento;
    f->fim++;

    if (f->inicio - f->fim == 1){
      aumenta_fila_especial(f);
    }
  }
}

Boolean fila_remover2(Fila* f, Tipo* endereco){
  if (f == NULL ) return false;

  if(f->inicio == f->fim){
    f->fim = 0;
    f->inicio = 0;
    return -1;
  }

  int i = f->inicio;
  *endereco = f->vetor[i];
  f->inicio++;

  if (f->inicio >= f->tam){
    f->inicio = 0;
  }

}

Tipo fila_remover1(Fila* f){
  if (f == NULL) return -1;

  if(f->inicio == f->fim){
    f->fim = 0;
    f->inicio = 0;
    return -1;
  }

  int i = f->inicio;
  Tipo removido = f->vetor[i];
  f->inicio++;

  if (f->inicio >= f->tam){
    f->inicio = 0;
  }


  return removido;

}

void fila_imprimir(Fila* f){
  if (f == NULL) return;

  if(f->vetor == NULL || f->inicio == f->fim){
    printf("FILA VAZIA\n");
  }

  else if (f->fim < f->inicio){
    int j;
    printf("ELEMENTOS: [ ");
    for (int j = f->inicio; j < f->tam; j++){
      printf("%d ",f->vetor[j]);
    }
    for (j = 0; j < f->fim; j++){
      printf("%d ", f->vetor[j]);

    }
    printf("]\n");
  }

  else{
    printf("ELEMENTOS: [ ");
    for (int i = f->inicio; i < f->fim; i++){
      printf("%d ",f->vetor[i]);
    }
    printf("]\n");
  }
}
