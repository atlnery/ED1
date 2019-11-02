#include<stdio.h>
#include "FilaEncadeada.h"

void teste(){

Fila* f = fila_criar();

fila_inserir(f, 15);
fila_inserir(f, 20);
fila_inserir(f, 50);
fila_inserir(f, 60);
fila_inserir(f, 232);
fila_inserir(f, 155);
fila_inserir(f, 166);


imprime_fila(f);


Tipo x = fila_remover1(f);
x = fila_remover1(f);
x = fila_remover1(f);

fila_remover2(f, &x);
fila_remover2(f, &x);


imprime_fila(f);

fila_primeiro(f, &x);
printf("PRIMEIRO ELEMENTO: %d\n",x);

x = fila_tamanho(f);
printf("TAMANHO: %d\n",x);

x = fila_contem(f, 155);
printf("Contém: %d\n",x);

fila_desalocar(f);

imprime_fila(f);

}

int main(){
  teste();
}
