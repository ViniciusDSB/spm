#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int codigoViatura(viaturaEmUso &viatAtual){
    int codigo = 0;
    printf("__________SPM - login na viatura__________\n");
    printf("\n");
    printf("DIGITE O CODIGO DA VIATURA (OU 0 PARA ENCERRAR O PROGRAMA)\n");
    scanf("%d", &codigo);
    if(codigo == 0)
        return 0;
    else
        return buscarViatura(codigo, viatAtual);
}

//cama a função codigoViatura que requisita o codigo das viatura;
//se for 0 então retorna ao menu inicial
void logon(){
    viaturaEmUso viaturaAtual;
    int tipo = codigoViatura(viaturaAtual);
    int qtdOcupantes;

    viaturaAtual.tipo = tipo;

    while(1){

        if(viaturaAtual.tipo == 0)
            main();
        else if(viaturaAtual.tipo == 1){    
            //viatura tipo 1 é regular, protanto pode ter 2, 3, ou 4 ocupantes
            printf("DIGITE A QUANTIDADE DE OCUPANTES:  \n");
            scanf("%d", &qtdOcupantes);
            if(qtdOcupantes<2 || qtdOcupantes >4){      //verifica se a quantidade de ocupantes está de acordo com o tipo de viatura;
                printf("SOMENTE 2 A 4 PERMITIDO, TENTE NOVAMENTE \n");
            }else{ //Se a quantidade de ocupantes estiver de acordo, ele le as credenciais deles com a função continda em buscarOficiais.cpp;
                viaturaAtual.qtdOcupantes = qtdOcupantes;
                lerCredenciais(viaturaAtual);
                break;
            }

        }
        else if(viaturaAtual.tipo == 2){

            printf("FECHADO EM 4 OCUPANTES, DIGA NOME DE GUERRA E SENHA DE CADA UM\n");
            lerCredenciais(viaturaAtual);
            break;

        }
        else{
            printf("!VIATURA INEXISTENTE NO SISTEMA!.\n");
            viaturaAtual.tipo = codigoViatura(viaturaAtual);
        }
            
    }
}