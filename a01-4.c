#include<stdio.h>
#include<string.h>

void processo(int dia, int mes, int ano){
  char a[20]="undefined"; char b[20]="undefined"; char month[20];
    if (dia/10 == 1){
      if (dia == 10){strcpy(a, "dez");}
      else if (dia == 11){strcpy(a, "onze");}
      else if (dia == 12){strcpy(a, "doze");}
      else if (dia == 13){strcpy(a, "treze");}
      else if (dia == 14){strcpy(a, "catorze");}
      else if (dia == 15){strcpy(a, "quinze");}
      else if (dia == 16){strcpy(a, "dezesseis");}
      else if (dia == 17){strcpy(a, "dezessete");}
      else if (dia == 18){strcpy(a, "dezoito");}
      else if (dia == 19){strcpy(a, "dezenove");}
    }
    else if(dia/10 == 2){strcpy(a, "vinte");}
    else if(dia/10 == 3){strcpy(a, "trinta");}
    if (dia/10 != 1){
      if (dia%10 == 1) {strcpy(b,"um");}
      else if (dia%10 == 2) {strcpy(b,"dois");}
      else if (dia%10 == 3) {strcpy(b,"três");}
      else if (dia%10 == 4) {strcpy(b,"quatro");}
      else if (dia%10 == 5) {strcpy(b,"cinco");}
      else if (dia%10 == 6) {strcpy(b,"seis");}
      else if (dia%10 == 7) {strcpy(b,"sete");}
      else if (dia%10 == 8) {strcpy(b,"oito");}
      else if (dia%10 == 9) {strcpy(b,"nove");}

    }

  if (mes == 1){strcpy(month, "Janeiro");}
  else if (mes == 2){strcpy(month, "Fevereiro");}
  else if (mes == 3){strcpy(month, "Março");}
  else if (mes == 4){strcpy(month, "Abril");}
  else if (mes == 5){strcpy(month, "Maio");}
  else if (mes == 6){strcpy(month, "Junho");}
  else if (mes == 7){strcpy(month, "Julho");}
  else if (mes == 8){strcpy(month, "Agosto");}
  else if (mes == 9){strcpy(month, "Setembro");}
  else if (mes == 10){strcpy(month, "Outubro");}
  else if (mes == 11){strcpy(month, "Novembro");}
  else if (mes == 12){strcpy(month, "Dezembro");}

  printf(" %s\n",a);
  printf(" %s\n",b);
}


int main(){
  int dia=21, mes=1, ano=959;
  processo(dia, mes, ano);
}
