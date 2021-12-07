#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.1415926535897932

int main() {

  int m, n, op;
  double sa, ca;
  double p[3], t[3], a[3];

  double rx[3][3] = {
    {1, 0, 0},
    {0, 1, 1},
    {0, 1, 1}
  };

  double ry[3][3] = {
    {1, 0, 1},
    {0, 1, 0},
    {1, 0, 1}
  };

  double rz[3][3] = {
    {1, 1, 0},
    {1, 1, 0},
    {0, 0, 1}
  };

  printf("\n--------------------------------------------------------------------------------");
  printf("\n\nDETERMINE A POSIÇÃO FINAL DE UM MANIPULADOR ROBÓTICO!");
  printf("\n\n--------------------------------------------------------------------------------");
  printf("\n\nForneça as coordenadas iniciais do Manipulador Robótico:\n");
  printf("\nEm X = ");
  scanf("%lf", & p[0]);
  printf("\nEm Y = ");
  scanf("%lf", & p[1]);
  printf("\nEm Z = ");
  scanf("%lf", & p[2]);
  printf("\n--------------------------------------------------------------------------------");

  do {

    printf("\n\nPara descrever um movimento de Translação digite 1.");
    printf("\nPara descrever um movimento de Rotação digite 2.");
    printf("\nPara resetar a posição digite 3.");
    printf("\nPara sair digite 0.\n\n");
    scanf("%d", & op);

    switch (op) {

    case 1:

      printf("\n--------------------------------------------------------------------------------");
      printf("\n\nDigite os valores de translação em cada eixo:\n");
      printf("\nEm X = ");
      scanf("%lf", & t[0]);
      printf("\nEm Y = ");
      scanf("%lf", & t[1]);
      printf("\nEm Z = ");
      scanf("%lf", & t[2]);

      for (m = 0; m < 3; m++) {
        p[m] = p[m] + t[m];
      }

      break;

    case 2:

      printf("\n--------------------------------------------------------------------------------");
      printf("\n\nDigite os ângulos de rotação em cada eixo:\n");
      printf("\nEm X = ");
      scanf("%lf", & a[0]);

      sa = sin(a[0] * pi / 180);
      ca = cos(a[0] * pi / 180);

      rx[1][1] = ca;
      rx[1][2] = -sa;
      rx[2][1] = sa;
      rx[2][2] = ca;

      printf("\nsen(%.2lf) = %.3lf e cos(%.2lf) = %.3lf\n", a[0], sa, a[0], ca);

      for (m = 0; m < 3; m++) {
        t[m] = 0;
      }

      for (m = 0; m < 3; m++) {
        for (n = 0; n < 3; n++) {
          t[m] = t[m] + (rx[m][n] * p[n]);
        }
      }

      for (m = 0; m < 3; m++) {
        p[m] = t[m];
      }

      printf("\nEm Y = ");
      scanf("%lf", & a[1]);

      sa = sin(a[1] * pi / 180);
      ca = cos(a[1] * pi / 180);

      ry[0][0] = ca;
      ry[0][2] = sa;
      ry[2][0] = -sa;
      ry[2][2] = ca;

      printf("\nsen(%.2lf) = %.3lf e cos(%.2lf) = %.3lf\n", a[1], sa, a[1], ca);

      for (m = 0; m < 3; m++) {
        t[m] = 0;
      }

      for (m = 0; m < 3; m++) {
        for (n = 0; n < 3; n++) {
          t[m] = t[m] + (ry[m][n] * p[n]);
        }
      }

      for (m = 0; m < 3; m++) {
        p[m] = t[m];
      }

      printf("\nEm Z = ");
      scanf("%lf", & a[2]);

      sa = sin(a[2] * pi / 180);
      ca = cos(a[2] * pi / 180);

      rz[0][0] = ca;
      rz[0][1] = -sa;
      rz[1][0] = sa;
      rz[1][1] = ca;

      printf("\nsen(%.2lf) = %.3lf e cos(%.2lf) = %.3lf\n", a[2], sa, a[2], ca);

      for (m = 0; m < 3; m++) {
        t[m] = 0;
      }

      for (m = 0; m < 3; m++) {
        for (n = 0; n < 3; n++) {
          t[m] = t[m] + (rz[m][n] * p[n]);
        }
      }

      for (m = 0; m < 3; m++) {
        p[m] = t[m];
      }

      break;

    case 3:

      printf("\n--------------------------------------------------------------------------------");
      printf("\n\nForneça as coordenadas iniciais do Manipulador Robótico:\n");
      printf("\nEm X = ");
      scanf("%lf", & p[0]);
      printf("\nEm Y = ");
      scanf("%lf", & p[1]);
      printf("\nEm Z = ");
      scanf("%lf", & p[2]);

      op = 4;

      break;

    case 0:

      op = 0;

      break;

    default:

      printf("\n--------------------------------------------------------------------------------");
      printf("\n\nOpção Inválida! Escolha entre os números 1, 2, 3 ou 0.\n");
      op = 4;

      break;

    }

    if (op != 0 && op != 4) {

      printf("\n--------------------------------------------------------------------------------");
      printf("\n\nA posição atual do Manipulador Robótico é:");
      printf("\n\nX = %.10lf", p[0]);
      printf("\n\nY = %.10lf", p[1]);
      printf("\n\nZ = %.10lf", p[2]);
      printf("\n");

    }

    printf("\n--------------------------------------------------------------------------------");

  } while (op != 0);

  printf("\n\nFim do Programa!");
  printf("\n\n--------------------------------------------------------------------------------\n");

  return 0;
}