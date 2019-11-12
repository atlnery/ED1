#include<stdio.h>
#include<string.h>

char oposto(char simbol){
  if (simbol == '('){
   return ')';
  }
  else if(simbol == '{'){
   return '}';
  }
  else if(simbol == '['){
    return ']';
  }
}

char verifica_cadeia(char* c){
  int i = 0;
  while(c[i] != '\0'){
    i++;
  }

  if(i%2 != 0) return 'N';

  int k = i-1;
  int j = 0;

  //printf("%d, %d\n",k,j); valor de k e j

  if ((k - j) == 1){
    if (c[k] == (oposto(c[j])) ) {
      return 'S';
    }
    else{
      return 'N';
    }

  }

  while (j < (i/2)){
    if ( c[k] == oposto(c[j]) ){ //O ÚLTIMO É O OPOSTO DO PRIMEIRO?
      k--; j++;
    }
    else{
      return 'N';
    }
  }
  return 'S';

}

int main(){
  char A[100001];
  int T;
  printf("Valor de instâncias: ");
  scanf("%d",&T);

  if(T > 20 || T < 1){
    printf("Instância inválida\n");
    return 0;
  }

  int i = 0;
  char saida;

  while(i < T){
    printf("Insira os símbolos: ");
    scanf(" %[^\n]", A);
    saida = verifica_cadeia(A);
    printf("SAIDA %c\n",saida);
    i++;
  }
}
