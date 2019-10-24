#include <stdio.h>
#include <stdlib.h>

typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;
typedef struct no* ptr;

/**
 * Registro utilizado para acomodar cada elemento da pilha (Nó).
 */
typedef struct no{
    Tipo dado;
    ptr prox;
}No;

/**
 * Estrutura usada para representar e armazenar a PILHA com alocação encadeada.
 */
typedef struct{
     No* topo;
    int qtd;
}Pilha;

Pilha* pilha_criar(); //cria a pilha inicial
Boolean pilha_push(Pilha* p, Tipo elemento); //insere elemento no topo da pilha
Tipo* pilha_pop1(Pilha* p); //remove elemento e devolve o valor removido
Boolean pilha_pop2(Pilha* p, Tipo* end); //remove e grava na variável o valor removido
void pilha_destruir(Pilha* p); //chama a destruição dos nós e destroi a pilha;
void destruir_no(ptr no); //destrói os nós
void pilha_imprimir(Pilha* p); //imprime a pilha
int pilha_posicao(Pilha* p, Tipo elemento);//mostra a posição em que se encontra determinado elemento
int pilha_tamanho(Pilha* p);//qtd de elementos na pilha;
//FUNÇÕES ADICIONAIS
int pilha_pushAll(Pilha* p, Tipo* vetor, int tam);
Pilha* pilha_inverter(Pilha* p);
Pilha* pilha_clone(Pilha* p);


/**
 * Cria a pilha e devolve seu endereço.
 * @return o endereço da pilha criada e inicializada.
 */
Pilha* pilha_criar(){
  Pilha* Nova = (Pilha*)malloc(sizeof(Pilha));
  Nova->topo = NULL;
  Nova->qtd = 0;
  return Nova;
}


/*
RECURSIVIDADE - destrói o ultimo nó e vai destruindo os demais
*/
void destruir_no(ptr no){
  if(no == NULL) return;
    destruir_no(no->prox);
    free(no);
}

/**
 * Desaloca a pilha <p>.
 */
void pilha_destruir(Pilha* p){
  if (p == NULL) return;
  destruir_no(p->topo);
  free(p);
}


/**
 * Insere o elemento <elemento> no topo da pilha <p>.
 * @param p: Endereço da Pilha em que o elemento será inserido.
 * @param elemento: Elemento a ser inserido na pilha.
 * @return true se a inserção foi realizada com sucesso e false caso contrário
 */
Boolean pilha_push(Pilha* p, Tipo elemento){
  No* New = (No*)malloc(sizeof(No));
  New->dado = elemento;
    if (p->topo == NULL){
      p->topo = New;
      New->prox = NULL;
    }
    else{
      New->prox = p->topo;
      p->topo = New;
    }
    p->qtd++;
}


/**
 * Remove o topo da Pilha <p>, aloca um espaço dinamicamente para armazenar o * elemento removido e devolve o endereço do elemento.
 * @param p: Endereço da Pilha.
 * @return Endereço do elemento removido ou NULL caso contrário.
 */
Tipo* pilha_pop1(Pilha* p){
  if (p->topo == NULL){
    return NULL;
  }
  else{
    Tipo* removido = p->topo->dado; //recebe o dado armazenado
    ptr aux = p->topo->prox; //recebe o endereço armazenado no topo (seja NULL ou de outra struct);
    free(p->topo); //desaloca struct;
    p->topo = aux;
    p->qtd--;
    return removido;
  }
}

/**
 * Remove o topo da Pilha <p>, e armazena o elemento removido no endereço
 * <end> recebido por parâmetro.
 * @param p: Endereço da Pilha.
 * @param end: Endereço de memória onde será armazenado o elemento removido
 * @return true se a remoçao foi realizada com sucesso e false caso contrário
 */
Boolean pilha_pop2(Pilha* p, Tipo* end){
  if (p->topo == NULL){
    *end = NULL;
    return false;
  }
  else{
    *end = p->topo->dado;
    ptr aux = p->topo->prox;
    free(p->topo);
    p->topo = aux;
    p->qtd--;
    return true;
  }
}


/**
 * Imprime na saída padrão os elementos da pilha
 * @param p: Endereço da Pilha.
 */
void pilha_imprimir(Pilha* p){
  if (p->topo == NULL){
    printf("Impressão minha ou a pilha está vazia?!\n");
  }
  else{
    ptr proximo = p->topo;
    printf("[ ");
      while(proximo != NULL){
        printf("%d ",proximo->dado);
        proximo = proximo->prox;
      }
    printf(" ]\n");
  }
}

/**
 * Devolve a posição do elemento <elemento> na pilha <p>
 * @param p: Endereço da Pilha.
 * @param elemento: Elemento a ser encontrado
 * @return posição do <elemento> em <p> ou -1 caso contrário
 */
int pilha_posicao(Pilha* p, Tipo elemento){
  if (p->topo == NULL){
    return -1;
  }
  else{
    ptr aux = p->topo;
    int i = (p->qtd-1); //trabalhar com valores a partir de zero
    while (aux != NULL){
      if (aux->dado == elemento)
        return i;

      i--; //porque verifico do topo a base
      aux = aux->prox; //acesso até o NULL (base);

      if (i < 0) //esse é caso que não existe o valor procurado
        return -1;
    }
  }
}

/**
 * Devolve o tamanho da pilha <p>
 * @param p: Endereço da Pilha.
 * @return quantidade de elementos da pilha <p>
 */
int pilha_tamanho(Pilha* p){
  return p->qtd;
}

//FUNÇÕES ADICIONAIS

/**
 * Insere todos os elementos do vetor <vetor> na pilha <p>
 * @param p: Endereço da Pilha.
 * @param vetor: Endereço do vetor
 * @param tam: tamanho do <vetor>
 * @return quantidade de elementos inseridos na pilha <p>
 */
int pilha_pushAll(Pilha* p, Tipo* vetor, int tam){
  if (p == NULL || p->topo == NULL){
    return 0;
  }
  else{
    int i;
    for (i = 0; i < tam; i++){
      pilha_push(p, vetor[i]);
    }
    return i++;
  }
}

/**
 * Inverte a pilha <p>
 * @param p: Endereço da Pilha.
 */
Pilha* pilha_inverter(Pilha* p){
  Pilha* invertida = pilha_criar();
  ptr aux = p->topo;
  while(aux != NULL){
    pilha_push(invertida, aux->dado);
    aux = aux->prox;
  }
  return invertida;
}

/**
 * Cria um clone da pilha <p>
 * @param p: Endereço da Pilha.
 * @return Endereço da pilha clonada.
 */
Pilha* pilha_clone(Pilha* p){
  Pilha* clone = pilha_criar();
  clone = pilha_inverter(p);
  clone = pilha_inverter(clone);
  return clone;
}
