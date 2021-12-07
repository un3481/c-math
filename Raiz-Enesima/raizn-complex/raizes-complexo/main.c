#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    double npot(double,double,double,int,int);
    double preal, pimag, n, re, im;
    int op;

    printf("\n--------------------------------------------------------------------------------");
    printf("\n\nDETERMINE A POTENCIA ENÉSIMA DE UM NUMERO COMPLEXO!");
    printf("\n\n--------------------------------------------------------------------------------");

    do{

    if(op==3){

    }else{

    printf("\nDigite seus componentes:\n");
    printf("\nParte real = ");
    scanf("%lf",&preal);
    printf("\nParte imaginária = ");
    scanf("%lf",&pimag);
    printf("\n--------------------------------------------------------------------------------");
    printf("\n\nDigite :\n");
    printf("\nPotencia = ");
    scanf("%lf",&n);

    re = npot(preal,pimag,n,0,0);
    im = npot(preal,pimag,n,1,0);

    printf("\n--------------------------------------------------------------------------------");
    printf("\n\nAs raizes deste numero são:");

    if(im<(0.00000000005) && im>(-0.00000000005)){
    printf("\n\nZ = %.15lf",re);
    }else{
    if(re<(0.00000000005) && re>(-0.00000000005)){
    printf("\n\nZ = %.15lfi",im);
    }else{
    if(im>0){
    printf("\n\nZ = %.15lf + %.15lfi",re,im);
    }else{
    printf("\n\nZ = %.15lf - %.15lfi",re,-im);
    }}}

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

double npot(double real, double imag, double vn, int cmplx, int posrt)
{

    long double vref=(long double)((real*real)+(imag*imag));
    long double rt2=1, i=1;
    double z=0, value=0;
    int dec=0;

    int q1,q2;
    double angulo;

    double cnroot=0,cpot=0,gn=0;
    int nroot=0,pot=0;
    int vtrue=0,vlow=0,pneg=0;

    long double vroot,calc;
    int cont;

    long double rt=0,test=0;
    double result=0;
    int rneg=0,b=0,c=0;

    int ic;
    double retorno;

    do{

    if((rt2*rt2)<vref){

    if(c==2){
    i=i/10;
    dec=dec+1;
    c=1;
    }
    if(b==0){
    i=i*10;
    }
    rt2=rt2+i;
    c=1;

    }else{
    if((rt2*rt2)>vref){

    if(c==1){
    i=i/10;
    dec=dec+1;
    }
    b=1;
    rt2=rt2-i;
    c=2;

    }else{

    dec=16;

    }}

    }while(dec<16);

    z = (double)rt2;

    if(real>0){
    real=real;
    q1=1;
    }else{
    if(real<0){
    real=-real;
    q1=2;
    }else{
    real=0;
    q1=3;
    }}

    if(imag>0){
    imag=imag;
    q2=1;
    }else{
    if(imag<0){
    imag=-imag;
    q2=2;
    }else{
    imag=0;
    q2=3;
    }}

    if(q1==1 && q2==1){
    angulo = atan(imag/real);
    }else{
    if(q1==2 && q2==1){
    angulo = M_PI-atan(imag/real);
    }else{
    if(q1==2 && q2==2){
    angulo = M_PI+atan(imag/real);
    }else{
    if(q1==1 && q2==2){
    angulo = (2*M_PI)-atan(imag/real);
    }else{
    if(q1==1 && q2==3){
    angulo = 0;
    }else{
    if(q1==3 && q2==1){
    angulo = (M_PI/2);
    }else{
    if(q1==2 && q2==3){
    angulo = M_PI;
    }else{
    if(q1==3 && q2==2){
    angulo = 3*(M_PI/2);
    }else{
    if(q1==3 && q2==3){
    angulo = 2*M_PI;
    }
    }}}}}}}}

    value = z;

    if(vn!=0){

    cpot=1;
    cnroot=1;

    if(vn>0){
    pneg=0;
    vn=vn;
    }else{
    pneg=1;
    vn=-vn;
    }

    do{

    do{

    gn=cpot/cnroot;

    if(vn==gn){
    vtrue=1;
    }else{
    if(vn<gn){
    vtrue=1;
    vlow=1;
    }else{
    cpot=cpot+1;
    }}

    }while(vtrue!=1);

    if(vlow==1){
    vtrue=0;
    vlow=0;
    cpot=1;
    cnroot=cnroot+1;
    }

    }while(vtrue!=1);

    pot=(int)cpot;
    nroot=(int)cnroot;

    vroot=1;
    for(cont=1;cont<=pot;cont++){
    vroot=vroot*value;
    }
    if(pneg==1){
    vroot=1/vroot;
    }

    if(vroot>=0){
    rneg = 0;
    vroot = vroot;
    }else{
    rneg = 1;
    vroot = -vroot;
    }

    real = vroot*cos(angulo*pot);
    imag = vroot*sin(angulo*pot);

    vref=(long double)((real*real)+(imag*imag));
    rt2=1;
    i=1;
    z=0;
    dec=0;
    q1=0;
    q2=0;
    angulo=0;

    do{

    if((rt2*rt2)<vref){

    if(c==2){
    i=i/10;
    dec=dec+1;
    c=1;
    }
    if(b==0){
    i=i*10;
    }
    rt2=rt2+i;
    c=1;

    }else{
    if((rt2*rt2)>vref){

    if(c==1){
    i=i/10;
    dec=dec+1;
    }
    b=1;
    rt2=rt2-i;
    c=2;

    }else{

    dec=16;

    }}

    }while(dec<16);

    z = (double)rt2;

    if(real>0){
    real=real;
    q1=1;
    }else{
    if(real<0){
    real=-real;
    q1=2;
    }else{
    real=0;
    q1=3;
    }}

    if(imag>0){
    imag=imag;
    q2=1;
    }else{
    if(imag<0){
    imag=-imag;
    q2=2;
    }else{
    imag=0;
    q2=3;
    }}

    if(q1==1 && q2==1){
    angulo = atan(imag/real);
    }else{
    if(q1==2 && q2==1){
    angulo = M_PI-atan(imag/real);
    }else{
    if(q1==2 && q2==2){
    angulo = M_PI+atan(imag/real);
    }else{
    if(q1==1 && q2==2){
    angulo = (2*M_PI)-atan(imag/real);
    }else{
    if(q1==1 && q2==3){
    angulo = 0;
    }else{
    if(q1==3 && q2==1){
    angulo = (M_PI/2);
    }else{
    if(q1==2 && q2==3){
    angulo = M_PI;
    }else{
    if(q1==3 && q2==2){
    angulo = 3*(M_PI/2);
    }else{
    if(q1==3 && q2==3){
    angulo = 2*M_PI;
    }
    }}}}}}}}

    vroot = z;

    rt=1;
    i=1;
    c=0;
    dec=0;

    do{

    test=1;
    for(cont=1;cont<=nroot;cont++){
    test=test*rt;
    }

    if(test<vroot){

    if(c==2){
    i=i/10;
    dec=dec+1;
    c=1;
    }
    if(b==0){
    i=i*10;
    }
    rt=rt+i;
    c=1;

    }else{
    if(test>vroot){

    if(c==1){
    i=i/10;
    dec=dec+1;
    }
    b=1;
    rt=rt-i;
    c=2;

    }else{

    dec=16;

    }}

    }while(dec<16);

    if(rneg==1){
    rt=-rt;
    }

    result = (double)rt;

    }else{

    result = 1;

    }

    double re[nroot];
    double im[nroot];

    for(ic=1;ic<=nroot;ic++){
    re[ic-1] = result*cos((angulo/nroot)+(M_PI*(ic-1)));
    im[ic-1] = result*sin((angulo/nroot)+(M_PI*(ic-1)));
    }

    if(cmplx=0){

    retorno = re[posrt];

    }else{

    retorno = im[posrt];

    }

    return retorno;

}

