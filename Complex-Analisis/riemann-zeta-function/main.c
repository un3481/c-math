#include <stdio.h>

#include <stdlib.h>

int main() {

  int op, opt;
  double a[2], res[2];
  double rzf(double, double, int);

  printf("\n--------------------------------------------------------------------------------");
  printf("\n\nFUNCAO ZETA DE RIEMANN!");
  printf("\n\n Z(z) = 1/(1^z) + 1/(2^z) + 1/(3^z) + 1/(4^z) + 1/(5^z) + ...");

  do {

    printf("\n\n--------------------------------------------------------------------------------");
    printf("\n\nDigite o valor inicial:\n");
    printf("\n z(Re) = ");
    scanf("%lf", & a[0]);
    printf("\n z(Im) = ");
    scanf("%lf", & a[1]);
    printf("\n--------------------------------------------------------------------------------");
    printf("\n Aguarde cerca de 1 min.\n");

    res[0] = rzf(a[0], a[1], 0);
    res[1] = rzf(a[0], a[1], 1);

    printf("--------------------------------------------------------------------------------");
    printf("\n\nComputando 100 mil termos da Funcao Zeta de Riemann temos:");
    printf("\n\n Z(");
    //fix shown values:
    if ((a[0] == 0) && (a[1] == 0)) {
      printf("0");
    } else {
      if (a[1] == 0) {
        printf("%.6lf", a[0]);
      } else {
        if (a[0] == 0) {
          printf("%.6lfi", a[1]);
        } else {
          if (a[1] < 0) {
            printf("%.3lf%.3lfi", a[0], a[1]);
          } else {
            printf("%.3lf+%.3lfi", a[0], a[1]);
          }
        }
      }
    }
    printf(") = ");
    //fix shown values:
    if ((res[0] == 0) && (res[1] == 0)) {
      printf("0");
    } else {
      if (res[1] == 0) {
        printf("%.12lf", res[0]);
      } else {
        if (res[0] == 0) {
          printf("%.12lfi", res[1]);
        } else {
          if (res[1] < 0) {
            printf("%.6lf%.6lfi", res[0], res[1]);
          } else {
            printf("%.6lf+%.6lfi", res[0], res[1]);
          }
        }
      }
    }

    printf("\n");

    do {

      printf("\n--------------------------------------------------------------------------------");
      printf("\n\nPara determinar um novo valor digite 1.");
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
        printf("\n\nOpção Inválida! Escolha entre os números 1 e 0.\n");
        op = 2;

        break;

      }

    } while (op != 0);

  } while (opt != 0);

  printf("\nFim do Programa!");
  printf("\n\n--------------------------------------------------------------------------------\n");

  return 0;
}

double rzf(double a, double b, int f) {

  int n = 0, i = 0, rzt = 0;
  long double e = 0, ln2 = 0, lnm = 0, k = 0, sgn = 0, top = 0, bot = 0, mod = 0;
  long double pi = 0, arg = 0, zq = 0, res[6];
  long double ea = 0, sb = 0, cb = 0;

  //define e:
  for (n = 1; n <= 100; n++) {
    bot = 1;
    for (i = 2; i < n; i++) {
      bot *= i;
    }
    e = e + (1 / bot);
  }
  //define pi:
  zq = 0;
  sgn = (-1);
  for (n = 1; n <= 100; n++) {
    sgn = (-sgn);
    bot = ((2 * n) - 1);
    top = 1;
    for (i = 1; i <= ((2 * n) - 1); i++) {
      top = (top / 5);
    }
    zq = zq + (sgn * (top / bot));
  }
  pi = 4 * zq;
  zq = 0;
  sgn = (-1);
  for (n = 1; n <= 100; n++) {
    sgn = (-sgn);
    bot = ((2 * n) - 1);
    top = 1;
    for (i = 1; i <= ((2 * n) - 1); i++) {
      top = (top / 239);
    }
    zq = zq + (sgn * (top / bot));
  }
  pi = (pi - zq);
  pi *= 4;
  //define ln(2):
  sgn = (-1);
  ln2 = 1;
  for (n = 1; n <= 100; n++) {
    sgn = (-sgn);
    top = 1;
    for (i = 1; i <= n; i++) {
      top *= (2 - e);
    }
    bot = n;
    for (i = 1; i <= n; i++) {
      bot *= e;
    }
    ln2 = ln2 + (sgn * (top / bot));
  }

  res[0] = 0;
  res[1] = 0;

  for (rzt = 1; rzt <= 100000; rzt++) {
    //1: ln(rzt)

    //get [rzt]*(2^-k)
    //until the result is between 4 and 2:
    mod = (long double) rzt;
    k = 0;
    do {
      if (mod > 4) {
        mod *= (0.5);
        k = k + 1;
      } else {
        if (mod < 2) {
          mod *= 2;
          k = k - 1;
        }
      }
    } while ((mod > 4) || (mod < 2));
    //get ln(x)
    //for x=([rzt]*(2^-k)):
    sgn = (-1);
    lnm = 1;
    for (n = 1; n <= 100; n++) {
      sgn = (-sgn);
      top = 1;
      for (i = 1; i <= n; i++) {
        top *= (mod - e);
      }
      bot = n;
      for (i = 1; i <= n; i++) {
        bot *= e;
      }
      lnm = lnm + (sgn * (top / bot));
    }
    //ln(z)(Re):
    res[2] = (lnm + (k * ln2));
    res[3] = 0;

    //2 e^(z)

    //multiplying ln(rzt) for z:
    zq = (res[2] * a);
    k = (res[2] * b);

    //fix e^(-inf):
    if (zq < (-22)) {
      res[0] = 0;
      res[1] = 0;
    } else {

      // 2.1: Real part of e^(z)

      //get e^(a):
      ea = 0;
      for (n = 1; n <= 100; n++) {
        top = 1;
        for (i = 1; i < n; i++) {
          top *= zq;
        }
        bot = 1;
        for (i = 2; i < n; i++) {
          bot *= i;
        }
        ea = ea + (top / bot);
      }

      //get b between -2pi and 2pi:
      if (k > (2 * pi)) {
        k = (k - (2 * pi));
      }
      if (k < (-2 * pi)) {
        k = (k + (2 * pi));
      }

      //get (e^(a))*cos(b):
      cb = 0;
      sgn = (-1);
      for (n = 1; n <= 100; n++) {
        sgn = -sgn;
        bot = 1;
        for (i = 2; i <= (2 * (n - 1)); i++) {
          bot *= i;
        }
        top = 1;
        for (i = 1; i <= (2 * (n - 1)); i++) {
          top = top * k;
        }
        cb = cb + (sgn * (top / bot));
      }
      //result:
      res[4] = ea * cb;

      // 2.2: Imaginary part of e^(z)

      //(e^(a))*sin(b):
      sb = 0;
      sgn = (-1);
      for (n = 1; n <= 100; n++) {
        sgn = -sgn;
        bot = 1;
        for (i = 2; i <= ((2 * n) - 1); i++) {
          bot *= i;
        }
        top = 1;
        for (i = 1; i <= ((2 * n) - 1); i++) {
          top = top * k;
        }
        sb = sb + (sgn * (top / bot));
      }
      //result:
      res[5] = ea * sb;
    }

    // get 1/(a+bi):
    res[2] = ((res[4]) / ((res[4] * res[4]) + (res[5] * res[5])));
    res[3] = ((-res[5]) / ((res[4] * res[4]) + (res[5] * res[5])));

    res[0] = res[0] + res[2];
    res[1] = res[1] + res[3];
  }

  return (double) res[f];
}