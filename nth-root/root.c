#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

  double npot(double, double);
  double v, n, res;
  int op;

  printf("\n--------------------------------------------------------------------------------");
  printf("\n\nDETERMINE A POTENCIA ENÉSIMA DE UM NUMERO!");
  printf("\n\n--------------------------------------------------------------------------------");

  do {

    if (op == 3) {

    } else {

      printf("\n\nDigite o Valor a ser potenciado e o expoente:\n");
      printf("\nValor = ");
      scanf("%lf", & v);
      printf("\nExpoente = ");
      scanf("%lf", & n);
      printf("\n--------------------------------------------------------------------------------");

      res = npot(v, n);

      printf("\n\nResultado = %.10lf\n", res);

    }

    printf("\n--------------------------------------------------------------------------------");
    printf("\n\nPara achar as raizes de uma nova função digite 1.");
    printf("\nPara sair digite 0.\n\n");
    scanf("%d", & op);

    switch (op) {

    case 1:

      op = 1;

      break;

    case 0:

      op = 0;

      break;

    default:

      printf("\n--------------------------------------------------------------------------------");
      printf("\n\nOpção Inválida! Escolha entre os números 1 ou 0.\n");
      op = 3;

      break;

    }

    if (op == 3) {} else {
      printf("\n--------------------------------------------------------------------------------");
    }

  } while (op != 0);

  printf("\n\nFim do Programa!");
  printf("\n\n--------------------------------------------------------------------------------\n");

  return 0;
}

double npot(double value, double vn) {

  double cnroot = 0, cpot = 0, gn = 0;
  int nroot = 0, pot = 0;
  int vtrue = 0, vlow = 0, pneg = 0;

  long double vroot, calc;
  int cont;

  long double rt = 0, i = 0, test = 0;
  double result = 0;
  int rneg = 0, b = 0, c = 0, dec = 0;

  if (vn != 0) {

    cpot = 1;
    cnroot = 1;

    if (vn > 0) {
      pneg = 0;
      vn = vn;
    } else {
      pneg = 1;
      vn = -vn;
    }

    do {

      do {

        gn = cpot / cnroot;

        if (vn == gn) {
          vtrue = 1;
        } else {
          if (vn < gn) {
            vtrue = 1;
            vlow = 1;
          } else {
            cpot = cpot + 1;
          }
        }

      } while (vtrue != 1);

      if (vlow == 1) {
        vtrue = 0;
        vlow = 0;
        cpot = 1;
        cnroot = cnroot + 1;
      }

    } while (vtrue != 1);

    pot = (int) cpot;
    nroot = (int) cnroot;

    vroot = 1;
    for (cont = 1; cont <= pot; cont++) {
      vroot = vroot * value;
    }
    if (pneg == 1) {
      vroot = 1 / vroot;
    }

    if (vroot >= 0) {
      rneg = 0;
      vroot = vroot;
    } else {
      rneg = 1;
      vroot = -vroot;
    }

    rt = 1;
    i = 1;
    c = 0;
    dec = 0;

    do {

      test = 1;
      for (cont = 1; cont <= nroot; cont++) {
        test = test * rt;
      }

      if (test < vroot) {

        if (c == 2) {
          i = i / 10;
          dec = dec + 1;
          c = 1;
        }
        if (b == 0) {
          i = i * 10;
        }
        rt = rt + i;
        c = 1;

      } else {
        if (test > vroot) {

          if (c == 1) {
            i = i / 10;
            dec = dec + 1;
          }
          b = 1;
          rt = rt - i;
          c = 2;

        } else {

          dec = 16;

        }
      }

    } while (dec < 16);

    if (rneg == 1) {
      rt = -rt;
    }

    result = (double) rt;

  } else {

    result = 1;

  }

  return result;

}