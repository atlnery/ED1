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

  int cont = 0;
  while (c[cont] != '\0'){
    cont++;
  } //saber qtd de elementos para serem comparados;

  if ( (cont%2) != 0) return 'N';

  char abre[50001];
  char fecha[50001];

  int j = 0, k = 0;
  int i;

  for(i = 0; i < cont; i++){ //cria dois vetores com os que abrem e os que fecham
    if(c[i] == '{' || c[i] == '[' || c[i] == '('){
      abre[j] = c[i];
      j++;
    }
    else{
      fecha[k] = c[i];
      k++;
    }
  }

  if (k != j) return 'N'; //se os vetores abre e fecha forem diferentes, tem caracter sem par.

  int alpha = 0;
  for(i = 0; i < k; i++){
    j--;
    if (fecha[i] != oposto(abre[j])){
      alpha++;
    }
  }
  if (alpha == 0) return 'S';
  printf("%d\n",alpha);
  printf("%c\n",fecha[alpha]);

  return 'T';

}

int main(){
  char A[100001];
  int T;
  scanf("%d",&T);

  if(T > 20 || T < 1){
    return 0;
  }

  else{
    int i = 0;
    char saida;

    while(i < T){
      scanf(" %[^\n]", A);
      saida = verifica_cadeia(A);
      printf("%c\n",saida);
      i++;
    }
  }

}
