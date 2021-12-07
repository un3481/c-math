#include <stdio.h>
#include <stdlib.h>

int main(){

    int op, opt;
    double a, b, res;
    double ln(double), e(double);

    printf("\n--------------------------------------------------------------------------------");
    printf("\n\nPOTENCIACAO POR SERIE DE TAYLOR!");
    printf("\n\n a^b = e^[ln(a)*b]");

    do{

    printf("\n\n--------------------------------------------------------------------------------");
    printf("\n\nDigite o valor da base:\n");
    printf("\n a = ");
    scanf("%lf",&a);
    printf("\n--------------------------------------------------------------------------------");
    printf("\n\nDigite o valor do expoente:\n");
    printf("\n b = ");
    scanf("%lf",&b);

    if(a==0){
    res=0;
    }else{
    res = e(ln(a)*b);
    }

    printf("\n--------------------------------------------------------------------------------");
    printf("\n\nUtilizando a Serie de Taylor para e^[ln(%.3lf)*%.3lf] temos:",a,b);
    printf("\n\n%.3lf elevado a %.3lf = %.10lf",a,b,res);
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

double ln(double x){

    int n=0, i=0, ct=0, tr=0;
    long double e=0, ln2=0, tln=0, top=0, bot=0, sgn=0, res=0;

    for(n=1;n<=50;n++){
    bot=1;
    for(i=2;i<n;i++){
    bot*=i;
    }
    e = e+(1/bot);
    }

    sgn=(-1);
    ln2=1;
    for(n=1;n<=50;n++){
    sgn=(-sgn);
    top=1;
    for(i=1;i<=n;i++){
    top*=(2-e);
    }
    bot=n;
    for(i=1;i<=n;i++){
    bot*=e;
    }
    ln2 = ln2+(sgn*(top/bot));
    }

    do{
    if(x>4){
    x*=(0.5);
    ct=ct+1;
    }else{
    if(x<2){
    x*=2;
    ct=ct-1;
    }else{
    tr=1;
    }}
    }while(tr!=1);

    sgn=(-1);
    tln=1;
    for(n=1;n<=50;n++){
    sgn=(-sgn);
    top=1;
    for(i=1;i<=n;i++){
    top*=(x-e);
    }
    bot=n;
    for(i=1;i<=n;i++){
    bot*=e;
    }
    tln = tln+(sgn*(top/bot));
    }

    res = tln+(ct*ln2);
    return (double)res;
}

double e(double x){

    int n=0, i=0;
    long double top=0, bot=0, res=0;

    for(n=1;n<=50;n++){
    top=1;
    for(i=1;i<n;i++){
    top*=x;
    }
    bot=1;
    for(i=2;i<n;i++){
    bot*=i;
    }
    res = res+(top/bot);
    }

    return (double)res;
}
