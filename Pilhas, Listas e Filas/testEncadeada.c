#include<stdio.h>
#include "Pilha_encadeada.h"

void teste1(){
    Pilha* p = pilha_criar();

    int x = pilha_push(p, 10);//inserção elemento na pilha
    x = pilha_push(p, 20);
    x = pilha_push(p, 30);
    x = pilha_push(p, 40);
    x = pilha_push(p, 50);
    x = pilha_push(p, 60);
    x = pilha_push(p, 70);


    Tipo* removido = (Tipo*)sizeof(Tipo);
    removido = pilha_pop1(p); //remove elemento e retorna o valor removido
     //printf("%d\n",removido);
    pilha_pop2(p, &removido); //remove elemento e grava na variável o valor removido
    //printf("%d\n", removido);

    printf("TESTE COM POSIÇÕES - -1 QUANDO NÃO CONTÉM\n");
    int pos = pilha_posicao(p, 10); printf("10 na posição %d\n",pos);
    pos = pilha_posicao(p, 30);     printf("30 na posição %d\n",pos);
    pos = pilha_posicao(p, 50);     printf("50 na posição %d\n",pos);
    pos = pilha_posicao(p, 90);     printf("90 na posição %d\n",pos);


    pilha_imprimir(p);
    Pilha* copia = pilha_clone(p);
    pilha_imprimir(copia);

    pilha_imprimir(p);
    p = pilha_inverter(p);
    pilha_imprimir(p);

    x = pilha_tamanho(p);

    pilha_imprimir(copia);
    pilha_imprimir(p);


    int v[4] = {1,2,3,4};
    x = pilha_pushAll(p, v,4);
    printf("%d\n",x);

    pilha_imprimir(p);

    x = pilha_tamanho(p);
    printf("%d\n",x);

    pilha_destruir(p);
    pilha_destruir(copia);
}

int main(){
    teste1();
}
