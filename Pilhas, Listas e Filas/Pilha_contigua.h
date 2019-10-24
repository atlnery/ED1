#include <stdio.h>
#include <stdlib.h>
#define TAM 3

typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

typedef struct{
    Tipo* vetor;
    int tam; //máximo do vetor
    int qtd; //ocupado
}Pilha;

Pilha* pilha_criar(); //criação da pilha.
Boolean pilha_push(Pilha* p, Tipo elemento); //inserção de elemento no topo da pilha (pronto)
Tipo* pilha_pop1(Pilha* p); //insere o endereço do último valor retirado em uma variável
Boolean pilha_pop2(Pilha* p, Tipo* end); //não retorna, insere diretamente o valor;
void pilha_destruir(Pilha* p); //free nos elementos
void pilha_imprimir(Pilha* p); //impressão da pilha_pop1
int pilha_posicao(Pilha* p, Tipo elemento); //retorna a posição do elemento requisitado na pilha
int pilha_tamanho(Pilha* p); //devolve o tamanho total da pilha
//FUNÇÕES ADICIONAIS
int pilha_pushAll(Pilha* p, Tipo* vetor, int tam);//insere elementos de um vetor na pilha, bem como é informado o tamanho desse vetor
void pilha_inverter(Pilha* p); //inverte os elementos na pilha
Pilha* pilha_clone(Pilha* p); //copia uma pilha e devolve o endereço

Boolean aumenta_vetor(Pilha* p); //pronto

Pilha* pilha_criar(){
  Pilha* nova = (Pilha*)malloc(sizeof(Pilha));
  nova->vetor = (Tipo*)calloc(TAM, sizeof(Tipo));
  nova->tam = TAM;
  nova->qtd = 0;
  return nova;
}

Boolean pilha_push(Pilha* p, Tipo elemento){
  if (p -> qtd == p->tam){
    int x = aumenta_vetor(p);
      if (x != 1) {return false;}
  }
    p->vetor[p->qtd] = elemento;
    p->qtd++;
    return true;
}

Boolean aumenta_vetor(Pilha* p){ //irá aumentar 2 posições apenas
  Tipo* aux = (Tipo*)calloc(p->tam, sizeof(Tipo)); //cópia
  for (int i = 0; i < p->tam; i++){
    aux[i] = p->vetor[i];
  }
  p->vetor = (Tipo*)calloc((p->tam+1), sizeof(Tipo));
  for (int i = 0; i < p-> tam; i++){
    p->vetor[i] = aux[i];
  }
  p->tam++;
  return true;
}

void pilha_imprimir(Pilha* p){
  printf("\nVETOR: [ ");
  for (int i = 0; i < p->tam; i++){
    printf(" %d ",p->vetor[i]);
  }
  printf("]\nTAMANHO: %d\nQUANTIDADE: %d\n\n", p->tam, p->qtd);

}

Tipo* pilha_pop1(Pilha* p){
  Tipo* retorno;
  int pos = (p->qtd)-1;
  if (p->qtd <= 0){
    retorno = NULL;
  }
  else{
    retorno = p->vetor[pos];
    p->vetor[pos] = NULL;
    p->qtd--;
    return retorno;
  }
}

Boolean pilha_pop2(Pilha* p, Tipo* end){
  int pos = (p->qtd)-1;
  if (p->qtd <= 0){
    end = NULL;
    return false;
  }
  else{
    *end = p->vetor[pos];
    p->vetor[pos] = NULL;
    p->qtd--;
    return true;
  }
}

int pilha_posicao(Pilha* p, Tipo elemento){
  for(int i = 0; i < p->tam; i++){
    if(elemento == p->vetor[i]){
      return i;
    }
  }
  return -1;
}

int pilha_tamanho(Pilha* p){
  return p->tam;
}

Pilha* pilha_clone(Pilha* p){
  Pilha* copia = (Pilha*) malloc(sizeof(Pilha));
  copia->tam = p->qtd;
  copia->qtd = p->qtd;
  copia->vetor = (Tipo*)calloc(p->qtd, sizeof(Tipo));
  for (int i = 0; i < p->qtd; i++){
    copia->vetor[i] = p->vetor[i];
  }
  return copia;
}

void pilha_inverter(Pilha* p){
  Tipo* aux = (Tipo*)calloc(p->qtd, sizeof(Tipo));
  for (int i = (p->qtd-1), j = 0; i >= 0; i--){
    aux[j] = p->vetor[i];
    j++;
  }
  for (int i = 0; i < p->qtd; i++){
    p->vetor[i] = aux[i];
  }
  free(aux);
}

int pilha_pushAll(Pilha* p, Tipo* vetor, int tam){
  while (p->qtd + tam > p->tam){
    aumenta_vetor(p);
  }
  for(int i = p->qtd, j=0; j < tam; i++){
    p->vetor[i] = vetor[j];
    p->qtd++;
    j++;
  }
}

void pilha_destruir(Pilha* p){
  free(p->vetor);
  free(p);
}
