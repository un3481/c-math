#include <stdio.h>
#include <stdlib.h>

int main(){

    int op, opt;
    double a[2], res[2];
    double e(double,double,int);

    printf("\n--------------------------------------------------------------------------------");
    printf("\n\nE(X) POR SERIE DE TAYLOR!");
    printf("\n\n w = e^(z)");

    do{

    printf("\n\n--------------------------------------------------------------------------------");
    printf("\n\nDigite o valor do expoente:\n");
    printf("\n z(Re) = ");
    scanf("%lf",&a[0]);
    printf("\n z(Im) = ");
    scanf("%lf",&a[1]);

    res[0] = e(a[0],a[1],0);
    res[1] = e(a[0],a[1],1);

    printf("\n--------------------------------------------------------------------------------");
    printf("\n\nUtilizando a Serie de Taylor para e^(z) temos:");
    printf("\n\ne^(");
    //fix shown values:
    if((a[0]==0)&&(a[1]==0)){
    printf("0");
    }else{
    if(a[1]==0){
    printf("%.6lf",a[0]);
    }else{
    if(a[0]==0){
    printf("%.6lfi",a[1]);
    }else{
    if(a[1]<0){
    printf("%.3lf%.3lfi",a[0],a[1]);
    }else{
    printf("%.3lf+%.3lfi",a[0],a[1]);
    }}}}
    printf(") = ");
    //fix shown values:
    if((res[0]==0)&&(res[1]==0)){
    printf("0");
    }else{
    if(res[1]==0){
    printf("%.12lf",res[0]);
    }else{
    if(res[0]==0){
    printf("%.12lfi",res[1]);
    }else{
    if(res[1]<0){
    printf("%.6lf%.6lfi",res[0],res[1]);
    }else{
    printf("%.6lf+%.6lfi",res[0],res[1]);
    }}}}

    printf("\n");

    do{

    printf("\n--------------------------------------------------------------------------------");
    printf("\n\nPara determinar um novo valor digite 1.");
    printf("\nPara sair digite 0.\n\n");
    scanf("%d",&op);

        switch(op){

        case 1:

        opt=1;
        op=0;

        break;

        case 0:

        opt=0;
        op=0;

        break;

        default:

        printf("\n--------------------------------------------------------------------------------");
        printf("\n\nOpção Inválida! Escolha entre os números 1 e 0.\n");
        op=2;

        break;

        }

    }while(op!=0);

    }while(opt!=0);

    printf("\nFim do Programa!");
    printf("\n\n--------------------------------------------------------------------------------\n");

    return 0;
}

double e(double a, double b, int f){

    int n=0, i=0;
    long double sgn=0, top=0, bot=0, ea=0, sb=0, cb=0;
    long double zq=0, pi=0, res[2];

    //define pi:
    zq=0;
    sgn=(-1);
    for(n=1;n<=100;n++){
    sgn=(-sgn);
    bot=((2*n)-1);
    top=1;
    for(i=1;i<=((2*n)-1);i++){
    top=(top/5);
    }
    zq = zq+(sgn*(top/bot));
    }
    pi=4*zq;
    zq=0;
    sgn=(-1);
    for(n=1;n<=100;n++){
    sgn=(-sgn);
    bot=((2*n)-1);
    top=1;
    for(i=1;i<=((2*n)-1);i++){
    top=(top/239);
    }
    zq = zq+(sgn*(top/bot));
    }
    pi=(pi-zq);
    pi*=4;

    //fix e^(-inf):
    if(a<(-22)){
    res[0]=0;
    res[1]=0;
    }else{

    //1. Real part of e^(z)

    //get e^(a):
    for(n=1;n<=100;n++){
    top=1;
    for(i=1;i<n;i++){
    top*=a;
    }
    bot=1;
    for(i=2;i<n;i++){
    bot*=i;
    }
    ea = ea+(top/bot);
    }

    //get b between -2pi and 2pi:
    if(b>(2*pi)){
    b=(b-(2*pi));
    }
    if(b<(-2*pi)){
    b=(b+(2*pi));
    }

    //get (e^(a))*cos(b):
    cb=0;
    sgn=(-1);
    for(n=1;n<=100;n++){
    sgn = -sgn;
    bot=1;
    for(i=2;i<=(2*(n-1));i++){
    bot*=i;
    }
    top=1;
    for(i=1;i<=(2*(n-1));i++){
    top=top*b;
    }
    cb = cb+(sgn*(top/bot));
    }
    //result:
    res[0] = ea*cb;

    // 2. Imaginary part of e^(z)

    //(e^(a))*sin(b):
    sb=0;
    sgn=(-1);
    for(n=1;n<=100;n++){
    sgn = -sgn;
    bot=1;
    for(i=2;i<=((2*n)-1);i++){
    bot*=i;
    }
    top=1;
    for(i=1;i<=((2*n)-1);i++){
    top=top*b;
    }
    sb = sb+(sgn*(top/bot));
    }
    //result:
    res[1] = ea*sb;
    }

    return (double)res[f];
}
