#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

struct cell{
    char nome[32];
    char cpf[16];
    char apelido[16];
    char cidade[32];
    int idade;
    char cargo[32];
    char senha[32];
    cell* nex;
};


//Essa fução produra os policiais com os nomes de guerra dados
//verifica a senha, se for válida salva o policial na lista encadeada de policiais logados;
void lerPoliciais(cell* &policiais){
    //cell* policiaisLogados;
    char nome[32];
    char cpf[16];
    char apelido[16];
    char cidade[32];
    int idade;
    char cargo[32];
    char senha[32];

    FILE *pt = fopen("../database/policiais.txt", "r");
    
    if(pt == NULL)
        printf("Erro ao abrir arquivo ../database/policiais.txt\n");
    else{
        while(feof(pt) == 0){
            //Le os dasos de um policial no arquivo txt
        if (fscanf(pt, "%[^\n]\n", nome) == EOF) {
            break;
        }
            fscanf(pt, "%s\n", cpf);
            fscanf(pt, "%s", apelido);
            fscanf(pt, "%s\n", cidade);
            fscanf(pt, "%d\n", &idade);
            fscanf(pt, "%[^\n]\n", cargo);
            fscanf(pt, "%s\n", senha);

            //Salva os dados dele na lista encadeada;
            cell* tmp, *p;
            tmp = (cell*) malloc(sizeof(cell));
            
            strcpy(tmp->nome, nome);
            strcpy(tmp->cpf, cpf);
            strcpy(tmp->apelido, apelido);
            strcpy(tmp->cidade, cidade);
            tmp->idade = idade;
            strcpy(tmp->cargo, cargo);
            strcpy(tmp->senha, senha);

            tmp->nex = NULL;

            if(policiais == NULL)
                policiais = tmp;
            else{
                p = policiais;
                while(p->nex != NULL){
                    p = p->nex;
                }
                p->nex = tmp;
            }

        }
        fclose(pt);
    }

}

void mostrar(cell* &policiais){
    cell* tmp = policiais;

    while(tmp != NULL){
        
        printf("%s\n", tmp->nome);
        printf("%s\n", tmp->cpf);
        printf("%s\n", tmp->apelido);
        printf("%s\n", tmp->cidade);
        printf("%d\n", tmp->idade);
        printf("%s\n", tmp->cargo);
        printf("%s\n", tmp->senha);

        printf("__________________\n");
        tmp = tmp->nex;
    }

}

//Uma função recursiva que le o nome de guerra um oficial e sua senha
//Caso o nome de guerra não seja encontrado ela avisa e pede novamente, analogamente com a senha;
int validarOficiais(cell *policiais, char nome[], viaturaEmUso &viatAtual){
    cell*tmp = policiais;
    char senha[32];
    int ok = 0;

    while(tmp!=NULL && strcmp(tmp->apelido, nome) != 0){
        tmp = tmp->nex;
    }
    if(tmp == NULL){
        printf("OFICIAL NÃO ENCONTRADO, TENTE NOVAMENTE\n");
        scanf("%s", nome);
        validarOficiais(policiais, nome, viatAtual);
    }else{
        printf("DIGITE SUA SENHA\n");
        scanf("%s", senha);
        if(strcmp(tmp->senha, "314"))
            ok = 0;
        else if(strcmp(tmp->senha, senha) != 0){
            printf("SENHA INVALIDA, TENTE NOVAMENTE\n");
            validarOficiais(policiais, nome, viatAtual);
        }else{
            printf("TUDO CERTO\n");
            ok = 1;
        }
    }
    return ok;
}

//Aqui ela recebe a quantidade de piliciais lá do Index, e le nome de guerra
//Pra cada um ele chama a função validarOficiais que valida os policiais logados;
void lerCredenciais(viaturaEmUso &viatAtual){
    int qtdOcupantes = viatAtual.qtdOcupantes;
    cell* policiais = NULL;
    lerPoliciais(policiais);
    char nomeGuerra[16];
    int ok;
    printf("DIGITE 314 A QUALQUER MOMENTO PARA VOLTAR AO MENU INICIAL\n");
    for(int i = 0; i<qtdOcupantes; i++){
        printf("Digite o nome de guerra: \n");
        scanf("%s", nomeGuerra);
        if(strcmp(nomeGuerra, "314") == 0){
            ok = 0;
            break;
        }else{
            ok = validarOficiais(policiais, nomeGuerra, viatAtual);
            if(ok==0)
                break;
        }   
    }

    if(ok == 1){
        neutro();
    }else if(ok == 0){
        main();
    }
    else{
        printf("!OCORREU ALGUM PROBLEMA AO VALIDAR AS CREDENCIAIS: buscarOficiais.cpp");
        logon();
    }
}