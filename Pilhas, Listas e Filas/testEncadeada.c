#include<stdio.h>
#include "Pilha_encadeada.h"

void teste1(){
    Pilha* p = pilha_criar();
    Pilha* c = pilha_criar();

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

    printf("TESTE COM POSIÇÕES\n");
    int pos = pilha_posicao(p, 10); printf("%d\n",pos);
    pos = pilha_posicao(p, 20);     printf("%d\n",pos);
    pos = pilha_posicao(p, 30);     printf("%d\n",pos);
    pos = pilha_posicao(p, 40);     printf("%d\n",pos);
    pos = pilha_posicao(p, 50);     printf("%d\n",pos);
    pos = pilha_posicao(p, 90);     printf("%d\n",pos);

    pilha_imprimir(p);

    Pilha* copia = pilha_clone(p);
    pilha_imprimir(copia);

    
    pilha_destruir(c);
    pilha_destruir(p);

    pilha_imprimir(p);

    x = pilha_tamanho(p);
    printf("TAMANHO PILHA P %d\n",x);





}

int main(){
    teste1();
}
