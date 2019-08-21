#include<stdio.h>

int processamento();

int processamento(int x, int y){
  if (y == 0){
    return 1;
  }
  else{
    int i = 1, new = x;
    while(i < y){
      new *= x;
      i++;
    }
  return new;
  }
}

int main(){
  printf("3 elevado a 2 = %d\n", processamento(-3,2));
}

