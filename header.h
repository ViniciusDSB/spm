#include <stdio.h>
#include <stdlib.h>

//Encerrar programa
void tela0();
//Menu Principal
int main();

//Login na viatura e login de policiais, compreende funções das páginas com prefixo "op1"
struct viaturaEmUso{
    int codigo;
    int tipo;
    int qtdOcupantes;
};
void logon();
int buscarViatura(int &codigo, viaturaEmUso &viatAtual);
void lerCredenciais(viaturaEmUso &viatAtual);

void neutro();