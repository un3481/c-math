#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.1415926535897932
#define unit 1.0

int main(){

    int op;
    double a, b, c, d, p, q, u, v, ui, vi;
    double x1r, x1i, x2r, x2i, x3r, x3i;
    double re, im, z, ang;
    int q1, q2;

    printf("\n--------------------------------------------------------------------------------");
    printf("\n\nDETERMINE AS RAIZES DE UMA FUNÇÃO DO 3 GRAU!");
    printf("\n\n--------------------------------------------------------------------------------");

        do{

    if(op==3){

    }else{

    printf("\n\nDada uma função de coeficientes reais do tipo: ax³ + bx² + cx + d");
    printf("\nDigite seus coeficientes:\n");
    printf("\nCoeficiente A = ");
    scanf("%lf",&a);
    printf("\nCoeficiente B = ");
    scanf("%lf",&b);
    printf("\nCoeficiente C = ");
    scanf("%lf",&c);
    printf("\nCoeficiente D = ");
    scanf("%lf",&d);

    p = (-unit*(b*b)/(3*a*a))+(c/a);
    q = ((2*b*b*b)-(9*a*b*c)+(27*a*a*d))/(27*a*a*a);

    if(((q*q)+(4*(p*p*p)/27))>=0){

    u = cbrt((-q/2)+sqrt(((q*q)/4)+((p*p*p)/27)));
    ui = 0;
    v = cbrt((-q/2)-sqrt(((q*q)/4)+((p*p*p)/27)));
    vi = 0;

    x1r = u+v-(b/(3*a));
    x1i = 0;
    x2r = (-unit/2*u)+(-unit/2*v)-(b/(3*a));
    x2i = ((sqrt(3)/2)*u)-((sqrt(3)/2)*v);
    x3r = (-unit/2*u)+(-unit/2*v)-(b/(3*a));
    x3i = ((sqrt(3)/2)*v)-((sqrt(3)/2)*u);

    }else{

    re = (-q/2);
    im = sqrt(-unit*(((q*q)/4)+((p*p*p)/27)));
    z = sqrt((re*re)+(im*im));

        if(re>0){
        re=re;
        q1=1;
        }else{
        if(re<0){
        re=-re;
        q1=2;
        }else{
        re=0;
        q1=3;
        }}

        if(im>0){
        im=im;
        q2=1;
        }else{
        if(im<0){
        im=-im;
        q2=2;
        }else{
        im=0;
        q2=3;
        }}

        if(q1==1 && q2==1){
        ang = atan(im/re);
        }else{
        if(q1==2 && q2==1){
        ang = pi-atan(im/re);
        }else{
        if(q1==2 && q2==2){
        ang = pi+atan(im/re);
        }else{
        if(q1==1 && q2==2){
        ang = (2*pi)-atan(im/re);
        }else{
        if(q1==1 && q2==3){
        ang = 0;
        }else{
        if(q1==3 && q2==1){
        ang = (pi/2);
        }else{
        if(q1==2 && q2==3){
        ang = pi;
        }else{
        if(q1==3 && q2==2){
        ang = 3*(pi/2);
        }else{
        if(q1==3 && q2==3){
        ang = 2*pi;
        }
        }}}}}}}}

    u = cbrt(z)*cos((ang/3)+(2*pi/3));
    ui = cbrt(z)*sin((ang/3)+(2*pi/3));

    re = (-q/2);
    im = -unit*sqrt(-unit*(((q*q)/4)+((p*p*p)/27)));
    z = sqrt((re*re)+(im*im));

        if(re>0){
        re=re;
        q1=1;
        }else{
        if(re<0){
        re=-re;
        q1=2;
        }else{
        re=0;
        q1=3;
        }}

        if(im>0){
        im=im;
        q2=1;
        }else{
        if(im<0){
        im=-im;
        q2=2;
        }else{
        im=0;
        q2=3;
        }}

        if(q1==1 && q2==1){
        ang = atan(im/re);
        }else{
        if(q1==2 && q2==1){
        ang = pi-atan(im/re);
        }else{
        if(q1==2 && q2==2){
        ang = pi+atan(im/re);
        }else{
        if(q1==1 && q2==2){
        ang = (2*pi)-atan(im/re);
        }else{
        if(q1==1 && q2==3){
        ang = 0;
        }else{
        if(q1==3 && q2==1){
        ang = (pi/2);
        }else{
        if(q1==2 && q2==3){
        ang = pi;
        }else{
        if(q1==3 && q2==2){
        ang = 3*(pi/2);
        }else{
        if(q1==3 && q2==3){
        ang = 2*pi;
        }
        }}}}}}}}

    v = cbrt(z)*cos((ang/3)+(2*pi/3));
    vi = cbrt(z)*sin((ang/3)+(2*pi/3));

    x1r = u+v-(b/(3*a));
    x1i = ui+vi;
    x2r = ((-unit/2)*u)+((-unit/2)*v)-((sqrt(3)/2)*ui)+((sqrt(3)/2)*vi)-(b/(3*a));
    x2i = ((sqrt(3)/2)*u)-((sqrt(3)/2)*v)+((-unit/2)*ui)+((-unit/2)*vi);
    x3r = ((-unit/2)*u)+((-unit/2)*v)-((sqrt(3)/2)*vi)+((sqrt(3)/2)*ui)-(b/(3*a));
    x3i = ((sqrt(3)/2)*v)-((sqrt(3)/2)*u)+((-unit/2)*ui)+((-unit/2)*vi);

    }

    if(a==0){

    printf("\n--------------------------------------------------------------------------------");
    printf("\n\nO coeficiente A não pode ser igual a 0!");

    }else{

    printf("\n--------------------------------------------------------------------------------");
    printf("\n\nAs raizes desta função são:");

    printf("\n\nX1 = %.10lf",x1r);

    if(x2i<(0.00000000005) && x2i>(-0.00000000005)){
    printf("\n\nX2 = %.10lf",x2r);
    }else{
    if(x2r<(0.00000000005) && x2r>(-0.00000000005)){
    printf("\n\nX2 = %.10lfi",x2i);
    }else{
    if(x2i>0){
    printf("\n\nX2 = %.10lf + %.10lfi",x2r,x2i);
    }else{
    printf("\n\nX2 = %.10lf - %.10lfi",x2r,-x2i);
    }}}

    if(x3i<(0.00000000005) && x3i>(-0.00000000005)){
    printf("\n\nX3 = %.10lf",x3r);
    }else{
    if(x3r<(0.00000000005) && x3r>(-0.00000000005)){
    printf("\n\nX3 = %.10lfi",x3i);
    }else{
    if(x3i>0){
    printf("\n\nX3 = %.10lf + %.10lfi",x3r,x3i);
    }else{
    printf("\n\nX3 = %.10lf - %.10lfi",x3r,-x3i);
    }}}

    }

        }

        printf("\n\n--------------------------------------------------------------------------------");
        printf("\n\nPara achar as raizes de uma nova função digite 1.");
        printf("\nPara sair digite 0.\n\n");
        scanf("%d",&op);

            switch(op){

            case 1:

            op=1;

            break;

            case 0:

            op=0;

            break;

            default:

            printf("\n--------------------------------------------------------------------------------");
            printf("\n\nOpção Inválida! Escolha entre os números 1 ou 0.");
            op=3;

            break;

           }

        if(op==3){
        }else{
        printf("\n--------------------------------------------------------------------------------");
        }

        }while(op!=0);

    printf("\n\nFim do Programa!");
    printf("\n\n--------------------------------------------------------------------------------\n");

    return 0;
}
