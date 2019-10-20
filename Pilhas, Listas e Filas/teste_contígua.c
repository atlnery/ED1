#include<stdio.h>
#include "Pilha_contigua.h"

void teste1(){
    Pilha* p = pilha_criar();

    pilha_push(p, 10); //empilhar elementos
    pilha_push(p, 20);
    pilha_push(p, 30);
    pilha_push(p, 40);
    pilha_imprimir(p); // base -> topo

    int x = pilha_posicao(p, 10);
    printf("ESTÁ NA POSIÇÃO %d\n",x);

    pilha_push(p, 50);
    x = pilha_tamanho(p);
    //printf("%d TAMANHO\n",x);

    pilha_imprimir(p); // base -> topo

    pilha_push(p, 60);
    pilha_imprimir(p); // base -> topo

    Tipo* elemento = pilha_pop1(p); //60
    //printf(" elemento %d\n",elemento); //60
    elemento = pilha_pop1(p); //50
    elemento = pilha_pop1(p); //40
    pilha_imprimir(p);
    pilha_imprimir(p);

    pilha_pop2(p, &elemento); //10
    //printf("%d\n", elemento); //10
    pilha_imprimir(p); // base -> topo

    Pilha* copia = pilha_clone(p);
    pilha_imprimir(copia);

    pilha_inverter(p);
    pilha_imprimir(p);

    int v[5] = {1,2,3,4,3};
    pilha_pushAll(p, v, 5);
    pilha_imprimir(p);
    int v2[10] = {1,2,3,4,5,6,7,8,9,10};
    pilha_pushAll(p, v2, 10);
    pilha_imprimir(p);



    pilha_destruir(p);
    pilha_destruir(copia);
}

int main(){
    teste1();
}
