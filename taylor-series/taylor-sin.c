#include <stdio.h>

#include <stdlib.h>

#include <math.h>

int main() {

  int op, opt, i, n, a, b;
  double ang, rad, sa, sstm;
  long double pot, fat, stm[20];

  printf("\n--------------------------------------------------------------------------------");
  printf("\n\nAPROXIMACAO DE SEN(X) POR SERIE DE TAYLOR E MACLAURIN!");

  do {

    for (i = 0; i < 20; i++) {
      stm[i] = 0;
    }
    n = 1;
    sa = 0;
    rad = 0;
    sstm = 0;
    fat = 1;
    a = (-1);

    printf("\n\n--------------------------------------------------------------------------------");
    printf("\n\nDigite o angulo:\n");
    printf("\nX = ");
    scanf("%lf", & ang);

    rad = M_PI * (ang / 180);
    sa = sin(rad);

    for (n = 1; n <= 10; n++) {

      b = ((2 * n) - 1);
      a = -a;

      fat = 1;
      for (i = 2; i <= b; i++) {
        fat *= i;
      }

      pot = 1;
      for (i = 1; i <= b; i++) {
        pot = pot * rad;
      }

      stm[n] = a * (pot / fat);

      sstm = sstm + (double) stm[n];

      printf("\n--------------------------------------------------------------------------------");
      printf("\n\nSeno calculado pelo computador:");
      printf("\nsen(%.3lf) = %.10lf", ang, sa);
      printf("\n\nSoma de %d termos da Serie de Taylor e Maclaurin:", n);
      printf("\nsen(%.3lf) = %.10lf", ang, sstm);
      printf("\n");

      getchar();

    }

    do {

      printf("\n--------------------------------------------------------------------------------");
      printf("\n\nPara determinar o seno de um novo angulo digite 1.");
      printf("\nPara sair digite 0.\n\n");
      scanf("%d", & op);

      switch (op) {

      case 1:

        opt = 1;
        op = 0;

        break;

      case 0:

        opt = 0;
        op = 0;

        break;

      default:

        printf("\n--------------------------------------------------------------------------------");
        printf("\n\nOpção Inválida! Escolha entre os números 1 e 0.");
        op = 2;

        break;

      }

    } while (op != 0);

  } while (opt != 0);

  printf("\nFim do Programa!");
  printf("\n\n--------------------------------------------------------------------------------\n");

  return 0;
}