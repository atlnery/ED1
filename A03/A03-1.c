#include<stdio.h>
/*Escreva um algoritmo que calcule e mostre a potência
de um determinado número somente usando ooperador de multiplicação*/

float potencia1(float a, float b);//return
float potencia2(float a, float b, float* valor);//referência


float potencia2(float a, float b, float* valor){
  if(b == 0){*valor = 1;}
  else if (b < 0){
    int i = 0;
    while(i != b){
      i--;
      *valor *= (1/a);
    }
  }
  else{
    int i = 0;
    while (i < b){
      *valor *= a;
      i++;
    }
  }
}

float potencia1(float a, float b){
  float valor = 1;
  if(b == 0){return 1;}

  else if (b < 0){
    int i = 0;
    while(i != b){
      i--;
      valor = valor*1/a;
    }
    return valor;
  }
  else{
    int i = 0;
    while (i < b){
      valor *= a;
      i++;
    }
    return valor;
  }
}

void main(){

  //MODO CONVENCIONAL(return)
  printf("2 elevado a 3 = %.0f\n", potencia1(2,3));
  printf("-2 elevado a 3 = %.0f\n", potencia1(-2,3));
  printf("2 elevado a -3 = %.3f\n", potencia1(2,-2));
  printf("2 elevado a 0 = %.0f\n\n", potencia1(2,0));

  //MODO SCANF (por referência)
  float valor=1;
  potencia2(2,3, &valor);
  printf("2 elevado a 3 = %.0f\n", valor);
  valor=1;
  potencia2(-2,3, &valor);
  printf("-2 elevado a 3 = %.0f\n", valor);
  valor=1;
  potencia2(2,-3, &valor);
  printf("2 elevado a -3 = %.3f\n", valor);
  valor=1;
  potencia2(2,0, &valor);
  printf("2 elevado a 0 = %.0f\n", valor);
}
