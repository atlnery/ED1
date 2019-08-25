#include<stdio.h>
#include<math.h>

int processamento(int valor);
int saida(int cont100,int cont50,int cont20,int cont10, int cont5, int cont2);

int processamento(int valor){
  int cont100=0, cont50=0, cont20=0, cont10=0, cont5=0, cont2=0;
  cont100 = floor (valor/100);
  cont50  = floor((valor%100)/50);
  cont20  = floor((valor - (cont100*100 + cont50*50))/20);
  cont10  = floor((valor - (cont100*100 + cont50*50+cont20*20))/10);
  if (((valor - (cont100*100 + cont50*50+cont20*20+cont10*10))%2) == 0){
    cont2   = floor((valor - (cont100*100 + cont50*50+cont20*20+cont10*10+cont5*5))/2);
  }
  else{
    cont5 = floor((valor - (cont100*100 + cont50*50+cont20*20+cont10*10))/5);
    cont2 = floor((valor - (cont100*100 + cont50*50+cont20*20+cont10*10+cont5*5))/2);
  }

  saida(cont100, cont50, cont20, cont10, cont5, cont2);
}

int saida(int cont100,int cont50,int cont20,int cont10, int cont5, int cont2){
  printf("%d NOTAS DE R$ 100,00\n%d NOTAS DE R$ 50,00\n%d NOTAS DE R$ 20,00\n",cont100, cont50, cont20);
  printf("%d NOTAS DE R$ 10,00\n%d NOTAS DE R$ 5,00\n%d NOTAS DE R$ 2,00\n",cont10, cont5, cont2);
}

int main(){
  int valor = 10569;
  processamento(valor);
}
