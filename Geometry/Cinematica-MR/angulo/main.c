#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.1415926535897932

int main(){

    int op;
    double at, q1, q2, ang, r, gr, min, seg;
    double p[2];

    printf("\n--------------------------------------------------------------------------------");
    printf("\n\nDETERMINE O ANGULO DE UM MANIPULADOR ROBÓTICO!");
    printf("\n\n--------------------------------------------------------------------------------");

        do{

    if(op==3){

    }else{

    printf("\n\nForneça as coordenadas do Manipulador Robótico:\n");
    printf("\nEm X = ");
    scanf("%lf",&p[0]);
    printf("\nEm Y = ");
    scanf("%lf",&p[1]);
    printf("\n--------------------------------------------------------------------------------");

        if(p[0]>0){
        p[0]=p[0];
        q1=1;
        }else{
        if(p[0]<0){
        p[0]=-p[0];
        q1=2;
        }else{
        p[0]=0;
        q1=3;
        }}

        if(p[1]>0){
        p[1]=p[1];
        q2=1;
        }else{
        if(p[1]<0){
        p[1]=-p[1];
        q2=2;
        }else{
        p[1]=0;
        q2=3;
        }}

        at = atan(p[1]/p[0]);

        if(q1==1 && q2==1){
        ang = (at*180/pi);
        r = sqrt(pow(p[0],2)+pow(p[1],2));
        }else{
        if(q1==2 && q2==1){
        ang = 180-(at*180/pi);
        r = sqrt(pow(p[0],2)+pow(p[1],2));
        }else{
        if(q1==2 && q2==2){
        ang = 180+(at*180/pi);
        r = sqrt(pow(p[0],2)+pow(p[1],2));
        }else{
        if(q1==1 && q2==2){
        ang = 360-(at*180/pi);
        r = sqrt(pow(p[0],2)+pow(p[1],2));
        }else{
        if(q1==1 && q2==3){
        ang = 0;
        r = p[0];
        }else{
        if(q1==3 && q2==1){
        ang = 90;
        r = p[1];
        }else{
        if(q1==2 && q2==3){
        ang = 180;
        r = p[0];
        }else{
        if(q1==3 && q2==2){
        ang = 270;
        r = p[1];
        }else{
        if(q1==3 && q2==3){
        ang = 360;
        r = 0;
        }
        }}}}}}}}

        gr = floor(ang+0.00000000001);
        min = floor(((ang-gr)*60)+0.00000000001);
        if(min<=0){
        min=0;
        }
        seg = floor(((((ang-gr)*60)-min)*60)+0.00000000001);
        if(seg<=0){
        seg=0;
        }

        if(p[0]==0 && p[1]==0){
        printf("\n\nImpossível calcular o angulo pois o raio do Manipulador é igual a 0.");
        }else{
        printf("\n\nO angulo de inclinação do Manipulador Robótico é: %.10lf Graus",ang);
        printf("\n\nQue equivale aproximadamente a: %.0lf° %.0lf' %.0lf''",gr,min,seg);
        printf("\n\nO raio do Manipulador é: %.10lf u",r);
        }

        }

        printf("\n\n--------------------------------------------------------------------------------");
        printf("\n\nPara determinar um novo angulo digite 1.");
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
            printf("\n\nOpção Inválida! Escolha entre os números 1, 2 ou 0.");
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
