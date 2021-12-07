#include <stdio.h>
#include <stdlib.h>

int main(){

    int op, opt;
    double sc[2], res;
    double arct(double,double);

    printf("\n--------------------------------------------------------------------------------");
    printf("\n\nARCO TANGENTE POR SERIE DE TAYLOR!");
    printf("\n\n arctan(sin(x)/cos(x))");

    do{

    printf("\n\n--------------------------------------------------------------------------------");
    printf("\n\nDigite o cateto adjacente:\n");
    printf("\n c(cos(x)) = ");
    scanf("%lf",&sc[0]);
    printf("\n--------------------------------------------------------------------------------");
    printf("\n\nDigite o cateto oposto:\n");
    printf("\n s(sin(x)) = ");
    scanf("%lf",&sc[1]);

    if((sc[0]+sc[1])==0){
    res=0;
    }else{
    res=arct(sc[0],sc[1]);
    }

    printf("\n--------------------------------------------------------------------------------");
    printf("\n\nUtilizando a Serie de Taylor para arctan(x) temos:");
    printf("\n\n arctan(%.3lf/%.3lf) = %.10lf",sc[1],sc[0],res);
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

double arct(double a, double b){

    int n=0, i=0;
    long double k=0, sgn=0, top=0, bot=0, mod=0;
    long double pi=0, arg=0, zq=0, nt=0, cx2=0, cx4=0, sx4=0;
    long double rt=0, vrt=0, rdiv=0, res=0;

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
    //define sqrt(1.5)
    //using taylor series for sqrt(x):
    rt=0;
    for(n=1;n<=100;n++){
    bot=1;
    zq=1;
    for(i=1;i<n;i++){
    zq*=i;
    }
    bot*=zq;
    zq=1;
    for(i=1;i<n;i++){
    zq*=2;
    }
    bot*=zq;
    bot*=bot;
    top=1;
    for(i=1;i<n;i++){
    top*=(1-(1.5));
    }
    zq=1;
    for(i=1;i<=(2*(n-1));i++){
    zq*=i;
    }
    top*=zq;
    top*=(1.5);
    rdiv = rdiv+(top/bot);
    }
    //get square root of mod^2(z):
    vrt=((a*a)+(b*b));
    //get value divided for 1.5^n
    //until it gets between 0.5 and 1.5:
    k=0;
    if(vrt!=0){
    k=1;
    do{
    if(vrt>(1.5)){
    vrt=(vrt/(1.5));
    k*=rdiv;
    }else{
    if(vrt<(0.5)){
    vrt*=(1.5);
    k=(k/rdiv);
    }}
    }while(vrt>(1.5)||vrt<(0.5));
    }
    //taylor series for sqrt(x):
    rt=0;
    for(n=1;n<=100;n++){
    bot=1;
    zq=1;
    for(i=1;i<n;i++){
    zq*=i;
    }
    bot*=zq;
    zq=1;
    for(i=1;i<n;i++){
    zq*=2;
    }
    bot*=zq;
    bot*=bot;
    top=1;
    for(i=1;i<n;i++){
    top*=(1-vrt);
    }
    zq=1;
    for(i=1;i<=(2*(n-1));i++){
    zq*=i;
    }
    top*=zq;
    top*=vrt;
    rt = rt+(top/bot);
    }
    //get sqrt(x/k)*sqrt(k):
    rt*=k;
    mod=rt;
    //get cos(x/2):
    if(b==0){
    if(a>=0){
    //cos(0):
    vrt=1;
    }else{
    //cos(pi/2):
    vrt=0;
    }
    }else{
    //cos(whatever/2):
    vrt=((1+(a/mod))*0.5);
    }
    //get value divided for 1.5^n
    //until it gets between 0.5 and 1.5:
    k=0;
    if(vrt!=0){
    k=1;
    do{
    if(vrt>(1.5)){
    vrt=(vrt/(1.5));
    k*=rdiv;
    }else{
    if(vrt<(0.5)){
    vrt*=(1.5);
    k=(k/rdiv);
    }}
    }while(vrt>(1.5)||vrt<(0.5));
    }
    //taylor series for sqrt(u):
    rt=0;
    for(n=1;n<=100;n++){
    bot=1;
    zq=1;
    for(i=1;i<n;i++){
    zq*=i;
    }
    bot*=zq;
    zq=1;
    for(i=1;i<n;i++){
    zq*=2;
    }
    bot*=zq;
    bot*=bot;
    top=1;
    for(i=1;i<n;i++){
    top*=(1-vrt);
    }
    zq=1;
    for(i=1;i<=(2*(n-1));i++){
    zq*=i;
    }
    top*=zq;
    top*=vrt;
    rt = rt+(top/bot);
    }
    //get sqrt(u/k)*sqrt(k):
    rt*=k;
    mod=rt;
    //get cos(x/4):
    vrt=((1+mod)*0.5);
    //get value divided for 1.5^n
    //until it gets between 0.5 and 1.5:
    k=0;
    if(vrt!=0){
    k=1;
    do{
    if(vrt>(1.5)){
    vrt=(vrt/(1.5));
    k*=rdiv;
    }else{
    if(vrt<(0.5)){
    vrt*=(1.5);
    k=(k/rdiv);
    }}
    }while(vrt>(1.5)||vrt<(0.5));
    }
    //taylor series for sqrt(u):
    rt=0;
    for(n=1;n<=100;n++){
    bot=1;
    zq=1;
    for(i=1;i<n;i++){
    zq*=i;
    }
    bot*=zq;
    zq=1;
    for(i=1;i<n;i++){
    zq*=2;
    }
    bot*=zq;
    bot*=bot;
    top=1;
    for(i=1;i<n;i++){
    top*=(1-vrt);
    }
    zq=1;
    for(i=1;i<=(2*(n-1));i++){
    zq*=i;
    }
    top*=zq;
    top*=vrt;
    rt = rt+(top/bot);
    }
    //get sqrt(u/k)*sqrt(k):
    rt*=k;
    cx4=rt;
    //get sin(x/4):
    vrt=((1-mod)*0.5);
    //get value divided for 1.5^n
    //until it gets between 0.5 and 1.5:
    k=0;
    if(vrt!=0){
    k=1;
    do{
    if(vrt>(1.5)){
    vrt=(vrt/(1.5));
    k*=rdiv;
    }else{
    if(vrt<(0.5)){
    vrt*=(1.5);
    k=(k/rdiv);
    }}
    }while(vrt>(1.5)||vrt<(0.5));
    }
    //taylor series for sqrt(u):
    rt=0;
    for(n=1;n<=100;n++){
    bot=1;
    zq=1;
    for(i=1;i<n;i++){
    zq*=i;
    }
    bot*=zq;
    zq=1;
    for(i=1;i<n;i++){
    zq*=2;
    }
    bot*=zq;
    bot*=bot;
    top=1;
    for(i=1;i<n;i++){
    top*=(1-vrt);
    }
    zq=1;
    for(i=1;i<=(2*(n-1));i++){
    zq*=i;
    }
    top*=zq;
    top*=vrt;
    rt = rt+(top/bot);
    }
    //get sqrt(u/k)*sqrt(k):
    rt*=k;
    sx4=rt;
    //fix the value of sin(x/4):
    if(b<0){
    sx4*=(-1);
    }
    //get tan(x/8)=(1-cos(u))/sin(u):
    if(sx4==0){
    mod=0;
    nt=0;
    }else{
    mod=((1-cx4)/sx4);
    nt=8;
    }
    //get tan(w/2)
    //until the result is smaller than 0.2:
    do{
    if(mod>(0.2)||mod<(-0.2)){
    vrt=(1+(mod*mod));
    //get value divided for 1.5^n
    //until it gets between 0.5 and 1.5:
    k=0;
    if(vrt!=0){
    k=1;
    do{
    if(vrt>(1.5)){
    vrt=(vrt/(1.5));
    k*=rdiv;
    }else{
    if(vrt<(0.5)){
    vrt*=(1.5);
    k=(k/rdiv);
    }}
    }while(vrt>(1.5)||vrt<(0.5));
    }
    //taylor series for sqrt(u):
    rt=0;
    for(n=1;n<=100;n++){
    bot=1;
    zq=1;
    for(i=1;i<n;i++){
    zq*=i;
    }
    bot*=zq;
    zq=1;
    for(i=1;i<n;i++){
    zq*=2;
    }
    bot*=zq;
    bot*=bot;
    top=1;
    for(i=1;i<n;i++){
    top*=(1-vrt);
    }
    zq=1;
    for(i=1;i<=(2*(n-1));i++){
    zq*=i;
    }
    top*=zq;
    top*=vrt;
    rt = rt+(top/bot);
    }
    //get sqrt(u/k)*sqrt(k):
    rt*=k;
    //get tan(w/2)=(sqrt(u)-1)/tan(w):
    zq=((rt-1)/(mod));
    mod=zq;
    nt*=2;
    }
    }while(mod>(0.2)||mod<(-0.2));
    //get arctan(x):
    arg=0;
    sgn=(-1);
    for(n=1;n<=100;n++){
    sgn=(-sgn);
    bot=((2*(n-1))+1);
    top=1;
    for(i=1;i<=((2*(n-1))+1);i++){
    top*=mod;
    }
    arg = arg+(sgn*(top/bot));
    }
    //get arctan(x/(2^k))*(2^k):
    arg*=nt;
    //result:
    res=arg;

    return (double)res;
}
