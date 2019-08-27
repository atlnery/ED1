#include<stdio.h>

int main(){

  short int i1;
  short int i2;
  short int *v2[3];
  short int i3;

  v2[0] = &i1;
  v2[1] = &i2;
  v2[2] = &i3;

  *v2[0] = 100;
  *v2[1] = 200;
  *v2[2] = 300;
}
