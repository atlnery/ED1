#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

void teste(){
  int verifica;

  Lista* lis = lista_criar();

  lista_inserir(lis,1,0);
  lista_inserir(lis,3,1);
  lista_inserir(lis,4,2);
  lista_inserir(lis,5,3);
  lista_inserir(lis,6,4);
  lista_inserir(lis,2,1);
  lista_imprimir(lis);

  int* valor = lista_remover1(lis,0);
  printf("Removido %d\n",*valor);

  valor = lista_remover1(lis,1);
  printf("Removido %d\n",*valor);

  verifica = lista_tamanho(lis);
  printf("Tamanho %d\n",verifica);

  valor = lista_remover1(lis,4);
  printf("Tamanho %d\n",verifica);

  lista_imprimir(lis);

  int valor2;
  Boolean x = lista_remover2(lis, 3 , &valor2);


  lista_buscar(lis, 0, &valor);
  printf("%d\n",valor);
  lista_imprimir(lis);

}

int main(){
  teste();
}
