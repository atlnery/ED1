#include<stdio.h>
#include<math.h>

int inverso1(int inverso);
int inverso2(int* inverso);

int inverso2(int* inverso){
  int cont = 0;
  int control = *inverso;
  float controle = control;
  while(controle >= 10){
    controle /= 10;
    cont++;
  }
  int i = 0, soma= 0, potencia = 0;
  float v[cont];
  while(i <= cont){
    i++;
    potencia = pow(10,i);
    v[i] = (control%potencia)-soma;
    soma += v[i];
  }
  i = 0; potencia = 0;
  while(i <= cont){
    potencia = pow(10,i);
    i++;
    v[i]= v[i] / potencia;
  }
  int devolva=0;
  i = 1; potencia = 0;
  while(cont >= 0){
    v[i] *= pow(10, cont);
    cont--;
    devolva += v[i];
    i++;
  }
  inverso = devolva;
}

int inverso1(int inverso){
  int cont = 0;
  float controle = inverso;
  while(controle >= 10){
    controle /= 10;
    cont++;
  }
  int i = 0, soma= 0, potencia = 0;
  float v[cont];
  while(i <= cont){
    i++;
    potencia = pow(10,i);
    v[i] = (inverso%potencia)-soma;
    soma += v[i];
  }
  i = 0; potencia = 0;
  while(i <= cont){
    potencia = pow(10,i);
    i++;
    v[i]= v[i] / potencia;
  }
  inverso = 0; i = 1; potencia = 0;
  while(cont >= 0){
    v[i] *= pow(10, cont);
    cont--;
    inverso += v[i];
    i++;
  }
  return inverso;
}

void main(){

//return
  printf("MÉTODO CONVENCIONAL\n");
  printf("345 - seu inverso é: %d\n", inverso1(345));
  printf("1 - seu inverso é: %d\n", inverso1(1));
  printf("1234627 - seu inverso é: %d\n", inverso1(1234627));
  printf("24 - seu inverso é: %d\n\n", inverso1(24));

//scanf
  int inverso = 1234345;
  printf("MÉTODO SCANF\n");
  printf("O inverso de 1234345 é %d\n",inverso2(&inverso));
}
