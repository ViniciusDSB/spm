#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

//Struct das viaturas; quando as viaturas são armazenadas, o tipo é lido no arquivo txt
//se for do tipo regular a viatura fica armazenada como tipo 1, se for especial fica tipo 2;
struct cell{
    int codigo;
    int tipo;
    cell* nex;
};

//Funcao que recebe uma viatura, codig e tipo, e armazena na lista encadeada;
void inserirViatura(int cod, int tipoo, cell* &lst){
    cell* tmp, *p;
    tmp = (cell*) malloc(sizeof(cell));
    tmp->codigo = cod;
    tmp->tipo = tipoo;
    tmp->nex = NULL;

    if(lst == NULL){
        lst = tmp;
    }else{
        p = lst;
        while(p->nex != NULL){
            p = p-> nex;
        }
        p->nex = tmp;
    }
}
//função pra desalocar a lista;
void delloc(cell* &lst){
    cell *aux;
    while(lst != NULL){
        aux = lst;
        lst = aux->nex;
        free(aux);
    }
}

//Essa função lê os dados do arquivo de viaturas
//chama a função inserirViatura que armazena os dados da viatura numa lista encadeada;
void lerAsViaturas(cell* &viaturasLst){


    int codViatura;
    char tipoDeViatura[16];

    FILE *pt;
    pt = fopen("../database/viaturas.txt", "r");
    if(!pt){
        printf("Erro na abertura de viaturas.txt\n");
    }
    else{

        while(feof(pt) == 0){

            fscanf(pt, "%d", &codViatura);
            fscanf(pt, "%s", tipoDeViatura);

            if(strcmp(tipoDeViatura, "regular") ==  0){
                inserirViatura(codViatura, 1, viaturasLst);
            }else{
                inserirViatura(codViatura, 2, viaturasLst);
            }

        }



        fclose(pt);
    }
}

//A fnção buscar percorre a lista de viaturas lidas pela função lerAsViaturas
//Se a viatura for encontrada retorna seu tipo e armazena seu codigo na na struct ViaturaAtual
int buscar(int codigo, cell* viaturasLst, viaturaEmUso &viatAtual){

    cell*p = viaturasLst;
    while(p != NULL){
        if(p->codigo == codigo){
            viatAtual.codigo = codigo;
            break;
        }
        else
            p = p->nex;
    }

    if(p == NULL){
        return 0;
    }else{
        return p->tipo;
    }
}

//ESSA é a função que interage com o op1Logon, retornando o tipo de viatura
int buscarViatura(int &codigo, viaturaEmUso &viatAtual){
    cell* viaturasLst = NULL;
    lerAsViaturas(viaturasLst);
    int tipo = buscar(codigo, viaturasLst, viatAtual);
    delloc(viaturasLst);
    return tipo;
}
