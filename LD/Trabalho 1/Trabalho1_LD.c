#include<stdio.h>
#include<stdlib.h>
#include<math.h> //ATENÇÃO MATH.H
#define N 8


/*UTILIZAÇÃO : VÁ NA FUNÇÃO "insere_valor" E COLOQUE OS DOIS VALORES (EM DECIMAL) QUE DESEJA UTILIZAR
             EM SEGUIDA VÁ ATÉ "menu" E EM OPERAÇÃO COLOQUE O VALOR DE 0 A 7. CADA VALOR CORRESPONDE A UMA OPERAÇÃO LÓGICA MATEMÁTICA DIFERENTE

/**************************
  PROTÓTIPOS
**************************/
void insere_valor(); //inserção do valor decimal
void menu(int* bin1, int* bin2); //escolha de opções para trabalhar com binário
int* converte_binario(int decimal); //converte decimal to binario
void imprime_binario(int* bin);
int constata(int decimal); //verifica se é um decimal válido
int converte_decimal(int* bin); //converte binário para decimal

void bin_and(int* bin1, int* bin2, int* result);
void bin_or(int* bin1, int* bin2, int* result);
void bin_nand(int* bin1, int* bin2, int* result);
void bin_nor(int* bin1, int* bin2, int* result);
void bin_not(int* bin1, int* result);
void bin_xor(int* bin1, int* bin2, int* result);
int bin_soma(int* bin1, int* bin2, int* result);
int bin_sub(int* bin1, int* bin2, int* result, char* sinal);


/**************************
  FUNÇÕES
**************************/

//INSERÇÃO DO VALOR DECIMAL A SER UTILIZADO

void insere_valor(){
  int valor1 = 167;
  int valor2 = 12;

  if ((constata(valor1) && constata(valor2)) == 0){
    printf("VALORES FORA DO INTERVALO DE 8 BITS\n");
    return;
  }

  int* bin1 = converte_binario(valor1);
  int* bin2 = converte_binario(valor2);

  printf("Valor %d em binário:\t", valor1);
  imprime_binario(bin1);
  printf("Valor %d em binário:\t", valor2);
  imprime_binario(bin2);

  menu(bin1, bin2);
}


/* 0 AND / 1 OR / 2 NAND / 3 NOR / 4 NOT
5 XOR / 6 SOMA / 7 SUBTRAÇÃO */

void menu(int* bin1, int* bin2){
  int* result = (int*)calloc(N, sizeof(int));
  int x = 0;
  char sinal = ' ';

  int op = 6;

  switch (op){

    case 0: printf("AND\n");
            bin_and(bin1, bin2, result);
            break;
    case 1: printf("OR\n");
            bin_or(bin1, bin2, result);
            break;
    case 2: printf("NAND\n");
            bin_nand(bin1, bin2, result);
            break;
    case 3: printf("NOR\n");
            bin_nor(bin1, bin2, result);
            break;
    case 4: printf("NOT A\n");
            bin_not(bin1, result);
            break;
    case 5: printf("XOR\n");
            bin_xor(bin1, bin2, result);
            break;
    case 6: printf("SOMA\n");
            x = bin_soma(bin1, bin2, result);
            break;
    case 7: printf("SUBTRAÇÃO\n");
            x = bin_sub(bin1, bin2, result, &sinal);
            break;
    default: printf("OPÇÃO INVÁLIDA!\n");
  }

  int valor = converte_decimal(result);

  printf("\nResultado da operação %d: ",op);
  imprime_binario(result);
  printf("Resultado em decimal: %c %d\n", sinal, valor);
  printf("Houve estouro: ");
    (x == 0) ? printf("Não\n") : printf("Sim\n");

  free(result);
  free(bin1);
  free(bin2);
}


//TRANSFORMAÇÃO DO VALOR DECIMAL RECEBIDO PARA BINÁRIO;

int* converte_binario(int decimal){
  int* vetor = (int*)calloc(N, sizeof(int));
  int i = N-1;

  while(i >= 0){
    vetor[i] = decimal%2;
    decimal /= 2;
    i--;
  }
  return vetor;
}


//TRANSFORMA UM VALOR BINÁRIO PARA DECIMAL

int converte_decimal(int* bin){
  int decimal = 0;
  int controle = 0;

  for(int i = (N-1); i >= 0; i--){
    if (bin[i] == 1){
      decimal += pow(2, controle);
    }
    controle++;
  }

  return decimal;
}


//VERIFICA SE VALORES INICIAIS INFORMADOS NÃO ULTRAPASSAM 255;

int constata(int decimal){
  if (decimal < 0 || decimal > 255){
    return 0;
  }
  return 1;
}


void imprime_binario(int* bin){
  if (bin == NULL) return;

  printf("[");
  for(int i = 0; i < N; i++){
    printf("%d ",bin[i]);
  }
  printf("]\n");
}


/********************
OPERAÇÕES DA ULA
*********************/

void bin_and(int* bin1, int* bin2, int* result){

  for (int i = 0; i < N; i++){
    if (bin1[i] && bin2[i])
      result[i] = 1;
    else
      result[i] = 0;
  }
}

void bin_or(int* bin1, int* bin2, int* result){

  for (int i = 0; i < N; i++){
    if (bin1[i] || bin2[i])
      result[i] = 1;
    else
      result[i] = 0;
  }
}

void bin_nand(int* bin1, int* bin2, int* result){

  for (int i = 0; i < N; i++){
    if (bin1[i] && bin2[i])
      result[i] = 0;
    else
      result[i] = 1;
  }
}

void bin_nor(int* bin1, int* bin2, int* result){

  for (int i = 0; i < N; i++){
    if (bin1[i] || bin2[i])
      result[i] = 0;
    else
      result[i] = 1;
  }
}

void bin_not(int* bin1, int* result){

  for (int i = 0; i < N; i++){
    if (bin1[i] == 1)
      result[i] = 0;
    else
      result[i] = 1;
  }
}

void bin_xor(int* bin1, int* bin2, int* result){

  for (int i = 0; i < N; i++){
    if (bin1[i] == bin2[i])
      result[i] = 0;
    else
      result[i] = 1;
  }
}

int bin_soma(int* bin1, int* bin2, int* result){

  int estouro = 0; //verificar se excedeu algum valor;

  for (int i = (N-1); i >= 0; i--){
    result[i] = bin1[i] + bin2[i] + estouro;

    if (result[i] >= 2){
      estouro = 1;
      result[i] = result[i] % 2;
    }

    else{
      estouro = 0;
    }
  }

  return estouro;
}

int bin_sub(int* bin1, int* bin2, int* result, char* sinal){

  int* complementar = (int*) calloc(N, sizeof(int));
  complementar[7] = 1;

  int borrow = 0;

  int x = converte_decimal(bin1);
  int y = converte_decimal(bin2);

  if (x > y){
    bin_not(bin2, bin2);
    *sinal = '+';
  }
  else{
    bin_not(bin1, bin1);
    *sinal = '-';
  }

  borrow = bin_soma(bin1, bin2, result);
  borrow = bin_soma(result, complementar, result);

  free(complementar);

  return borrow;
}


int main(){
  insere_valor();
}
