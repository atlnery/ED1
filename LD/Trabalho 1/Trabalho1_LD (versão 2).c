#include<stdio.h>
#include<stdlib.h>
#include<math.h> //ATENÇÃO MATH.H
#include<ctype.h>
#define N 8


/*UTILIZAÇÃO : VÁ NA FUNÇÃO "insere_valor" E COLOQUE OS DOIS VALORES (EM DECIMAL) QUE DESEJA UTILIZAR
             EM SEGUIDA VÁ ATÉ "ula" E EM OPERAÇÃO COLOQUE O VALOR DE 0 A 7. CADA VALOR CORRESPONDE A UMA OPERAÇÃO LÓGICA MATEMÁTICA DIFERENTE

/**************************
  PROTÓTIPOS
**************************/
void insere_valor(); //inserção do valor decimal
void ula(int* bin1, int* bin2); //escolha de opções para trabalhar com binário
int* converte_binario(int decimal); //converte decimal to binario
void imprime_binario(int* bin);
int constata(int decimal); //verifica se é um decimal válido
int converte_decimal(int* bin); //converte binário para decimal
int decoder(); //devolve a operação

void bin_and(int* bin1, int* bin2, int* result);
void bin_or(int* bin1, int* bin2, int* result);
void bin_nand(int* bin1, int* bin2, int* result);
void bin_nor(int* bin1, int* bin2, int* result);
void bin_not(int* bin1, int* result);
void bin_xor(int* bin1, int* bin2, int* result);
int somador_subtrator(int* bin1, int* bin2, int* result, int op);


/**************************
  FUNÇÕES
**************************/

//INSERÇÃO DO VALOR DECIMAL A SER UTILIZADO
void insere_valor(){
  int valor1, valor2;

  printf("Valor 1: ");
  scanf("%d",&valor1);
  printf("Valor 2: ");
  scanf("%d",&valor2);

  if ((constata(valor1) && constata(valor2)) == 0){
    printf("VALORES FORA DO INTERVALO DE 8 BITS\n");
    return;
  }

  int* bin1 = converte_binario(valor1);
  int* bin2 = converte_binario(valor2);

  printf("\nValor %d em binário:\t", valor1);
  imprime_binario(bin1);
  printf("Valor %d em binário:\t", valor2);
  imprime_binario(bin2);

  ula(bin1, bin2);
}


int decoder(int* mais_menos){

  int bin[8], operacao; //vetor de operacao
  printf("Operação a ser realizada: \n\n");
  scanf("%d %d %d", &bin[5], &bin[6], &bin[7]);

  *mais_menos = bin[7];

  operacao = converte_decimal(bin);

  return operacao;
}


/* 0 AND / 1 OR / 2 NAND / 3 NOR / 4 NOT
5 XOR / 6 SOMA / 7 SUBTRAÇÃO */
void ula(int* bin1, int* bin2){

  int* result = (int*)calloc(N, sizeof(int));
  int estouro = 0;
  int mais_menos;

  int operacao = decoder(&mais_menos);

  switch (operacao){

    case 0: printf("\nAND\n");
            for (int i = 0; i < N; i++){
              bin_and(&bin1[i], &bin2[i], &result[i]);
            }
            break;

    case 1: printf("\nOR\n");
            for (int i = 0; i < N; i++){
              bin_or(&bin1[i], &bin2[i], &result[i]);
            }
            break;

    case 2: printf("\nNAND\n");
            bin_nand(bin1, bin2, result);
            break;

    case 3: printf("\nNOR\n");
            bin_nor(bin1, bin2, result);
            break;

    case 4: printf("\nNOT 1\n");
            bin_not(bin1, result);
            break;

    case 5: printf("\nXOR\n");
            for (int i = 0; i < N; i++){
              bin_xor(&bin1[i], &bin2[i], &result[i]);
            }
            break;

    case 6: printf("\n");
            estouro = somador_subtrator(bin1, bin2, result, mais_menos);
            break;

    case 7: printf("\n");
            estouro = somador_subtrator(bin1, bin2, result, mais_menos);
            break;

    default: printf("\nOPÇÃO INVÁLIDA!\n");
  }

  int valor = converte_decimal(result);

  printf("Resultado em decimal: %d =  ", valor);
  imprime_binario(result);
  printf("Houve estouro: ");
    (estouro == 0) ? printf("Não\n") : printf("Sim\n");

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

    if (*bin1 && *bin2){
      *result = 1;
    }
    else{
      *result = 0;
    }
}

void bin_or(int* bin1, int* bin2, int* result){

    if (*bin1 || *bin2){
      *result = 1;
    }
    else{
      *result = 0;
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

    if (*bin1 == *bin2){
      *result = 0;
    }
    else{
      *result = 1;
    }

}

int somador_subtrator(int* bin1, int* bin2, int* result, int op){

  if (op == 0){ printf("SOMA\n"); }
  else { printf("SUBTRAÇÃO\n"); }

  int cin = 0, cout = 0;

  int s1, s2, s3, s4; //variáveis a serem utilizadas nas portas

  for(int i = 7; i > 0; i--){ //começa do fim ao início
    //resultado
    bin_xor(&bin1[i], &bin2[i], &result[i]);
    bin_xor(&result[i], &cin, &result[i]);
    //cout
    bin_xor(&op, &bin1[i], &s1);
    bin_or(&bin2[i], &cin, &s2);
    bin_and(&s1, &s2, &s3);
    bin_and(&bin2[i], &cin, &s4);
    bin_or(&s3, &s4, &cout);
    cin = cout;
  }

  return cout;
}

int main(){
  char x = 's';

  while(x != 'N'){

    printf("\n**************** OPERAÇÕES LÓGICAS ***********************\n\n");
    insere_valor();

    printf("\nCONTINUA? (N para sair): ");
    scanf(" %c", &x);
    x = toupper(x);
  }

}
