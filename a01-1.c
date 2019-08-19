#include<stdio.h>
#include<math.h>

int entrada();
int processamento();
int saida();

int entrada(){
  int x = 3;
  processamento(x);
}

int processamento(int x){
  x = pow(x, 2);
  saida(x);
}

int saida(int x){
  printf("%d\n",x);
}

int main(){
  entrada();
}
