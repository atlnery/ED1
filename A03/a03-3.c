#include<stdio.h>
#include<string.h>

char verifica(float nota);

char verifica(float nota){
  char control;
  if (nota < 0 || nota > 10){
   control = 'X';
 }
  else if (nota >= 9){
    control = 'A';
  }
  else if (nota >= 7){
    control = 'B';
  }
  else if (nota >= 6){
    control = 'C';
  }
  else if (nota < 6){
    control = 'I';
  }
  return control;
}

char verifica2(float nota, char *conceito){
   if (nota < 0 || nota > 10){
    *conceito = 'X';
  }
  else if (nota >= 9){
    *conceito = 'A';
  }
  else if (nota >= 7){
    *conceito = 'B';
  }
  else if (nota >= 6){
    *conceito = 'C';
  }
  else if (nota < 6){
    *conceito = 'I';
  }
}

void main(){

  //return
  printf("Nota -1:\t Conceito = %c\n", verifica(-1));
  printf("Nota 5:\t Conceito = %c\n", verifica(5));
  printf("Nota 9:\t Conceito = %c\n", verifica(9));
  printf("Nota 7:\t Conceito = %c\n", verifica(7));
  printf("Nota 6:\t Conceito = %c\n", verifica(6));

  //segundo modo

  printf("\nMÉTODO PONTEIRO\n");
  float nota = 7;
  if (nota < 0 || nota > 10){
    printf("VALOR INVÁLIDO\n");
  }
  else{
  char conceito;
  verifica2(nota, &conceito);
  printf("Nota %.2f:\t Conceito = %c\n", nota, conceito);
  }
}
