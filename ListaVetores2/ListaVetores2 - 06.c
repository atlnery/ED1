/*Escreva uma função que crie uma cópia de uma string (vetor de caracteres).*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* copiastring(char* copia){
 return copia;
}

int main(){
  char original[20] = "ABC";
  char* copia = copiastring(original);
  printf("%s\n", copia);
}
