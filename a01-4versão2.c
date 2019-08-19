#include<stdio.h>
#include<string.h>

void processo(int dia, int mes, int ano);
void saida(char *a[20], char *month[15], int ano);

void processo(int dia, int mes, int ano){
  char a[20], month[15];

    if (dia == 1){strcpy(a, "primeiro");}
    else if (dia == 2) {strcpy(a,"dois");}
    else if (dia == 3) {strcpy(a,"três");}
    else if (dia == 4) {strcpy(a,"quatro");}
    else if (dia == 5) {strcpy(a,"cinco");}
    else if (dia == 6) {strcpy(a,"seis");}
    else if (dia == 7) {strcpy(a,"sete");}
    else if (dia == 8) {strcpy(a,"oito");}
    else if (dia == 9) {strcpy(a,"nove");}
    else if (dia == 10){strcpy(a, "dez");}
    else if (dia == 11){strcpy(a, "onze");}
    else if (dia == 12){strcpy(a, "doze");}
    else if (dia == 13){strcpy(a, "treze");}
    else if (dia == 14){strcpy(a, "catorze");}
    else if (dia == 15){strcpy(a, "quinze");}
    else if (dia == 16){strcpy(a, "dezesseis");}
    else if (dia == 17){strcpy(a, "dezessete");}
    else if (dia == 18){strcpy(a, "dezoito");}
    else if (dia == 19){strcpy(a, "dezenove");}
    else if (dia == 20){strcpy(a, "vinte");}
    else if (dia == 21){strcpy(a, "vinte e um");}
    else if (dia == 22){strcpy(a, "vinte e dois");}
    else if (dia == 23){strcpy(a, "vinte e três");}
    else if (dia == 24){strcpy(a, "vinte e quatro");}
    else if (dia == 25){strcpy(a, "vinte e cinco");}
    else if (dia == 26){strcpy(a, "vinte e seis");}
    else if (dia == 27){strcpy(a, "vinte e sete");}
    else if (dia == 28){strcpy(a, "vinte e oito");}
    else if (dia == 29){strcpy(a, "vinte e nove");}
    else if (dia == 30){strcpy(a, "trinta");}
    else if (dia == 31){strcpy(a, "trinta e um");}

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

    saida(&a, &month, ano);
}

void saida(char *a[20], char *month[15], int ano){
  printf("%s de %s de %d\n",*a, *month, ano);
}


int main(){
  int dia=11, mes=1, ano=959;
  processo(dia, mes, ano);
}
