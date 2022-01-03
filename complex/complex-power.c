#include <stdio.h>
#include <stdlib.h>

int main() {

  int op, opt;
  double a[2], b[2], res[2];
  double exc(double, double, double, double, int);

  printf("\n--------------------------------------------------------------------------------");
  printf("\n\nPOTENCIACAO DE COMPLEXOS POR SERIE DE TAYLOR!");
  printf("\n\n z^x = e^[ln(z)*(x)]");

  do {

    printf("\n\n--------------------------------------------------------------------------------");
    printf("\n\nDigite o valor da base:\n");
    printf("\n a(Re) = ");
    scanf("%lf", & a[0]);
    printf("\n a(Im) = ");
    scanf("%lf", & a[1]);
    printf("\n--------------------------------------------------------------------------------");
    printf("\n\nDigite o valor do expoente:\n");
    printf("\n b(Re) = ");
    scanf("%lf", & b[0]);
    printf("\n b(Im) = ");
    scanf("%lf", & b[1]);

    res[0] = exc(a[0], a[1], b[0], b[1], 0);
    res[1] = exc(a[0], a[1], b[0], b[1], 1);

    printf("\n--------------------------------------------------------------------------------");
    printf("\n\nUtilizando a Serie de Taylor para e^[ln(a)*b] temos:");
    printf("\n\n");
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
    printf(" elevado a ");
    //fix shown values:
    if ((b[0] == 0) && (b[1] == 0)) {
      printf("0");
    } else {
      if (b[1] == 0) {
        printf("%.6lf", b[0]);
      } else {
        if (b[0] == 0) {
          printf("%.6lfi", b[1]);
        } else {
          if (b[1] < 0) {
            printf("%.3lf%.3lfi", b[0], b[1]);
          } else {
            printf("%.3lf+%.3lfi", b[0], b[1]);
          }
        }
      }
    }
    printf(" = ");
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

double exc(double a, double b, double c, double d, int f) {

  int n = 0, i = 0;
  long double e = 0, ln2 = 0, lnm = 0, k = 0, sgn = 0, top = 0, bot = 0, mod = 0;
  long double pi = 0, arg = 0, zq = 0, nt = 0, cx2 = 0, cx4 = 0, sx4 = 0;
  long double rt = 0, vrt = 0, rdiv = 0, res[4];
  long double ec = 0, sd = 0, cd = 0;

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
  //define sqrt(1.5)
  //using taylor series for sqrt(x):
  rt = 0;
  for (n = 1; n <= 100; n++) {
    bot = 1;
    zq = 1;
    for (i = 1; i < n; i++) {
      zq *= i;
    }
    bot *= zq;
    zq = 1;
    for (i = 1; i < n; i++) {
      zq *= 2;
    }
    bot *= zq;
    bot *= bot;
    top = 1;
    for (i = 1; i < n; i++) {
      top *= (1 - (1.5));
    }
    zq = 1;
    for (i = 1; i <= (2 * (n - 1)); i++) {
      zq *= i;
    }
    top *= zq;
    top *= (1.5);
    rdiv = rdiv + (top / bot);
  }

  //1: ln(z)

  //fix ln(0):
  if ((a == 0) && (b == 0)) {
    res[2] = (-99999999999999);
    res[3] = 0;
  } else {

    // 1.1: Real part of ln(z)

    //get [(a^2)+(b^2)]*(2^-k)
    //until the result is between 4 and 2:
    mod = ((a * a) + (b * b));
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
    //get ln(sqrt(x))=(1/2)*ln(x)
    //for x=([(a^2)+(b^2)]*(2^-k)):
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
    res[2] = ((lnm + (k * ln2)) * 0.5);

    // 1.2: Imaginary part of ln(z)

    //get square root of mod^2(z):
    vrt = ((a * a) + (b * b));
    //get value divided for 1.5^n
    //until it gets between 0.5 and 1.5:
    k = 0;
    if (vrt != 0) {
      k = 1;
      do {
        if (vrt > (1.5)) {
          vrt = (vrt / (1.5));
          k *= rdiv;
        } else {
          if (vrt < (0.5)) {
            vrt *= (1.5);
            k = (k / rdiv);
          }
        }
      } while (vrt > (1.5) || vrt < (0.5));
    }
    //taylor series for sqrt(x):
    rt = 0;
    for (n = 1; n <= 100; n++) {
      bot = 1;
      zq = 1;
      for (i = 1; i < n; i++) {
        zq *= i;
      }
      bot *= zq;
      zq = 1;
      for (i = 1; i < n; i++) {
        zq *= 2;
      }
      bot *= zq;
      bot *= bot;
      top = 1;
      for (i = 1; i < n; i++) {
        top *= (1 - vrt);
      }
      zq = 1;
      for (i = 1; i <= (2 * (n - 1)); i++) {
        zq *= i;
      }
      top *= zq;
      top *= vrt;
      rt = rt + (top / bot);
    }
    //get sqrt(x/k)*sqrt(k):
    rt *= k;
    mod = rt;
    //get cos(x/2):
    if (b == 0) {
      if (a >= 0) {
        //cos(0):
        vrt = 1;
      } else {
        //cos(pi/2):
        vrt = 0;
      }
    } else {
      //cos(whatever/2):
      vrt = ((1 + (a / mod)) * 0.5);
    }
    //get value divided for 1.5^n
    //until it gets between 0.5 and 1.5:
    k = 0;
    if (vrt != 0) {
      k = 1;
      do {
        if (vrt > (1.5)) {
          vrt = (vrt / (1.5));
          k *= rdiv;
        } else {
          if (vrt < (0.5)) {
            vrt *= (1.5);
            k = (k / rdiv);
          }
        }
      } while (vrt > (1.5) || vrt < (0.5));
    }
    //taylor series for sqrt(u):
    rt = 0;
    for (n = 1; n <= 100; n++) {
      bot = 1;
      zq = 1;
      for (i = 1; i < n; i++) {
        zq *= i;
      }
      bot *= zq;
      zq = 1;
      for (i = 1; i < n; i++) {
        zq *= 2;
      }
      bot *= zq;
      bot *= bot;
      top = 1;
      for (i = 1; i < n; i++) {
        top *= (1 - vrt);
      }
      zq = 1;
      for (i = 1; i <= (2 * (n - 1)); i++) {
        zq *= i;
      }
      top *= zq;
      top *= vrt;
      rt = rt + (top / bot);
    }
    //get sqrt(u/k)*sqrt(k):
    rt *= k;
    mod = rt;
    //get cos(x/4):
    vrt = ((1 + mod) * 0.5);
    //get value divided for 1.5^n
    //until it gets between 0.5 and 1.5:
    k = 0;
    if (vrt != 0) {
      k = 1;
      do {
        if (vrt > (1.5)) {
          vrt = (vrt / (1.5));
          k *= rdiv;
        } else {
          if (vrt < (0.5)) {
            vrt *= (1.5);
            k = (k / rdiv);
          }
        }
      } while (vrt > (1.5) || vrt < (0.5));
    }
    //taylor series for sqrt(u):
    rt = 0;
    for (n = 1; n <= 100; n++) {
      bot = 1;
      zq = 1;
      for (i = 1; i < n; i++) {
        zq *= i;
      }
      bot *= zq;
      zq = 1;
      for (i = 1; i < n; i++) {
        zq *= 2;
      }
      bot *= zq;
      bot *= bot;
      top = 1;
      for (i = 1; i < n; i++) {
        top *= (1 - vrt);
      }
      zq = 1;
      for (i = 1; i <= (2 * (n - 1)); i++) {
        zq *= i;
      }
      top *= zq;
      top *= vrt;
      rt = rt + (top / bot);
    }
    //get sqrt(u/k)*sqrt(k):
    rt *= k;
    cx4 = rt;
    //get sin(x/4):
    vrt = ((1 - mod) * 0.5);
    //get value divided for 1.5^n
    //until it gets between 0.5 and 1.5:
    k = 0;
    if (vrt != 0) {
      k = 1;
      do {
        if (vrt > (1.5)) {
          vrt = (vrt / (1.5));
          k *= rdiv;
        } else {
          if (vrt < (0.5)) {
            vrt *= (1.5);
            k = (k / rdiv);
          }
        }
      } while (vrt > (1.5) || vrt < (0.5));
    }
    //taylor series for sqrt(u):
    rt = 0;
    for (n = 1; n <= 100; n++) {
      bot = 1;
      zq = 1;
      for (i = 1; i < n; i++) {
        zq *= i;
      }
      bot *= zq;
      zq = 1;
      for (i = 1; i < n; i++) {
        zq *= 2;
      }
      bot *= zq;
      bot *= bot;
      top = 1;
      for (i = 1; i < n; i++) {
        top *= (1 - vrt);
      }
      zq = 1;
      for (i = 1; i <= (2 * (n - 1)); i++) {
        zq *= i;
      }
      top *= zq;
      top *= vrt;
      rt = rt + (top / bot);
    }
    //get sqrt(u/k)*sqrt(k):
    rt *= k;
    sx4 = rt;
    //fix the value of sin(x/4):
    if (b < 0) {
      sx4 *= (-1);
    }
    //get tan(x/8)=(1-cos(u))/sin(u):
    if (sx4 == 0) {
      mod = 0;
      nt = 0;
    } else {
      mod = ((1 - cx4) / sx4);
      nt = 8;
    }
    //get tan(w/2)
    //until the result is smaller than 0.2:
    do {
      if (mod > (0.2) || mod < (-0.2)) {
        vrt = (1 + (mod * mod));
        //get value divided for 1.5^n
        //until it gets between 0.5 and 1.5:
        k = 0;
        if (vrt != 0) {
          k = 1;
          do {
            if (vrt > (1.5)) {
              vrt = (vrt / (1.5));
              k *= rdiv;
            } else {
              if (vrt < (0.5)) {
                vrt *= (1.5);
                k = (k / rdiv);
              }
            }
          } while (vrt > (1.5) || vrt < (0.5));
        }
        //taylor series for sqrt(u):
        rt = 0;
        for (n = 1; n <= 100; n++) {
          bot = 1;
          zq = 1;
          for (i = 1; i < n; i++) {
            zq *= i;
          }
          bot *= zq;
          zq = 1;
          for (i = 1; i < n; i++) {
            zq *= 2;
          }
          bot *= zq;
          bot *= bot;
          top = 1;
          for (i = 1; i < n; i++) {
            top *= (1 - vrt);
          }
          zq = 1;
          for (i = 1; i <= (2 * (n - 1)); i++) {
            zq *= i;
          }
          top *= zq;
          top *= vrt;
          rt = rt + (top / bot);
        }
        //get sqrt(u/k)*sqrt(k):
        rt *= k;
        //get tan(w/2)=(sqrt(u)-1)/tan(w):
        zq = ((rt - 1) / (mod));
        mod = zq;
        nt *= 2;
      }
    } while (mod > (0.2) || mod < (-0.2));
    //get arctan(x):
    arg = 0;
    sgn = (-1);
    for (n = 1; n <= 100; n++) {
      sgn = (-sgn);
      bot = ((2 * (n - 1)) + 1);
      top = 1;
      for (i = 1; i <= ((2 * (n - 1)) + 1); i++) {
        top *= mod;
      }
      arg = arg + (sgn * (top / bot));
    }
    //get arctan(x/(2^k))*(2^k):
    arg *= nt;
    //ln(z)(Im):
    res[3] = arg;
  }

  //2: e^(z)

  //multiplying complex values:
  zq = ((res[2] * c) - (res[3] * d));
  k = ((res[2] * d) + (res[3] * c));

  //fix e^(-inf):
  if (zq < (-22)) {
    res[0] = 0;
    res[1] = 0;
  } else {

    // 2.1: Real part of e^(z)

    //get e^(c):
    for (n = 1; n <= 100; n++) {
      top = 1;
      for (i = 1; i < n; i++) {
        top *= zq;
      }
      bot = 1;
      for (i = 2; i < n; i++) {
        bot *= i;
      }
      ec = ec + (top / bot);
    }

    //get b between -2pi and 2pi:
    if (k > (2 * pi)) {
      k = (k - (2 * pi));
    }
    if (k < (-2 * pi)) {
      k = (k + (2 * pi));
    }

    //get (e^(a))*cos(b):
    cd = 0;
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
      cd = cd + (sgn * (top / bot));
    }
    //result:
    res[0] = ec * cd;

    // 2.2: Imaginary part of e^(z)

    //(e^(a))*sin(b):
    sd = 0;
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
      sd = sd + (sgn * (top / bot));
    }
    //result:
    res[1] = ec * sd;
  }

  return (double) res[f];
}