#include <stdio.h>

#include "TAD-matriz1.h"
//#include "TAD-matriz2.h"

int main()
{

  // criar matriz
  // int m[2][2]

    Matriz *m1 = matriz_cria(2, 3); //feito pelo professor
    Matriz *m2 = matriz_cria(10, 10);
    Matriz *m3 = matriz_cria(2, 2);


    // atribui valores nas celulas
    // m[0][2] = 10;
    matriz_atribui(m1, 0, 1, 10); //done
    matriz_atribui(m2, 2, 3, 20);
    matriz_atribui(m3, 0, 0, 50);


    // acessar valores das celulas
    // int x = m[1][2]*/
    int x1 = matriz_acessa1(m1, 0, 1);
    int y = matriz_acessa1(m2, 2, 3);
    int z = matriz_acessa1(m3, 0, 0);

    int x2;
    matriz_acessa2(m1, 0, 1, &x2); //done

    //imprimir a matriz
    matriz_imprime(m1); //done
    matriz_imprime(m2);
    matriz_imprime(m3);


    //destruir matriz
    matriz_destroi(m1);
    matriz_destroi(m2);
    matriz_destroi(m3);

}
