#include<stdio.h>//ATENÇÃO: esse programa vale apenas para numerais com 3 digitos

void entrada();
int processamento(int num);
int saida(int c, int b, int a);

void entrada(){
  int numero = 607;
  processamento(numero);
}

int processamento(int num){
  int a=0, b=0, c=0;
  if (num/100 >= 1){
    a = num/100;
  }
  if (num/10 >= 10){
    b = (num/10)%10;
    c = num%10;
  }
  saida(c,b,a);
}

int saida(int c, int b, int a){
  printf("%d%d%d\n",c,b,a);
}

int main(){
  entrada();
}
