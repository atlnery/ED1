#include<stdio.h>

float verifica(float nota);
void conceito(float conceito);

float verifica(float nota){
  float control;
  if (nota >= 9){
    control = 1;
  }
  else if (nota >= 7){
    control = 2;
  }
  else if (nota >= 6){
    control = 3;
  }
  else if (nota < 6){
    control = 0;
  }
  conceito(control);
}

void conceito(float conceito){
  if (conceito == 1){printf("A\n");}
  if (conceito == 2){printf("B\n");}
  if (conceito == 3){printf("C\n");}
  if (conceito == 0){printf("INSUFICIENTE\n");}
}

void main(){
  float nota = 8;
  verifica(nota);
}
