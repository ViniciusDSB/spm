#include <stdio.h>
#include <stdlib.h>
#include "header.h"

//Mostra a primeira "tela" do sistema, pede o codigo da viatura
int viatLogin();
void tela0(){
    printf("SPM DESLIGANDO...");
}



int main(){
    int d;

    while(1){

        printf("MENU PRINCIPAL\n1 - LOGIN NA VIATURA\n2 - VIATURA EM USO\n3 - COPOM\n4 - POLICIAL MILITAR\n5 - OFICIAL\n6 - COMANDANTE GERAL\n0 - ENCERRAR\n");

        scanf("%d", &d);

        if(d==0){
            tela0();
        }else if(d==1){
            logon();
        }else if(d==2){
            printf("VIATURA EM USO\n");
        }else if(d==3){
            printf("COPOM\n");
        }else if(d==4){
            printf("POLICIAL MILITAR\n");
        }else if(d==5){
            printf("OFICIAL\n");
        }else if(d==6){
            printf("COMANDANTE GERAL\n");
        }else{
            printf("OPÇÃO NÃO EXISTE, DIGITE UMAS DAS SEGUINTES:\n");
        }

    }

    system("pause");
    return 0;
}

