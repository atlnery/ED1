#include<stdio.h>
//Lista não tem restrição de inserção e remoção
//Máximo de trabalho é n/2 - porque cada elemento trabalha com dois ponteiros. Que aponta para o anterior e para o próximo. 

typedef struct{
  NoDuplo* prim;
  NoDuplo* ult;
  int qtd;
}ListaDupla; 

typedef struct{
  int dado; 
  struct NoDuplo* prox;
  struct NoDuplo* ant;
}NoDuplo; 

/*CASOS A SEREM CONSIDERADOS NA INSERÇÃO 

1 - LISTA VAZIA
2 - 1ª POSIÇÃO 
3 - INSERIR NA ÚLTIMA POS;
4 - INSERÇÃO NO MEIO; */



//Criação de Novo no condição 1

NoDuplo* no = novo_no(elemento, NULL, NULL);
l->prim = l->ult = no;
l->qtd++;


//Criação de Novo no condição 2
NoDuplo* no = novono(elemento, NULL, NULL); //ou, no terceiro parâmetro, colocar l->prim;
no->prox = l->prim; //se passar para função conforme o comentário, não precisa dessa linha
l->prim -> ant = no; 
l->prim = no;
l->qtd++;

//criação na condição 3
NoDuplo* no = novono(elemento, NULL, NULL);
no->ant = l->ult; 
l->ult -> prox = no;
l->ult = no;
l->qtd++; 

//criação na situação 4 
NoDuplo* no = novono(elemento, NULL, NULL);
NoDupo aux* = GetNo(l, pos); //se for direita, coloque pos-1; tanto faz a abordagem. 
insere/*esquerda ou direita*/(aux, no); 
l->qtd++;

//implemente as duas, para isnerir a esquerda ou direita! desenhe!

