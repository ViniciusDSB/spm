#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


void neutro(){
    int d;

    while(1){
        printf("SPM - VIATURA ESTADO NEUTRO\n");
        printf("1 - Apto para atender ocorrencia\n");
        printf("2 - Cancelar Embarcação");
        scanf("%d", &d);

        if(d == 1){
            printf("página em construção\n");
            break;
        }else if(d == 2){
            main();
            break;
        }else{
            printf("Opção não existe, tente:\n");
        }
    }
}

