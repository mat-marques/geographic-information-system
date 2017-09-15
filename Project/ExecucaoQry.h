#ifndef EXECUCAOQRY_H
#define EXECUCAOQRY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Canvas.h"

/**
Autor: Matheus Augusto Marques.
Módulo: ExecucaoQry
Definição:
O módulo ExecucaoQry tem o objetivo de reunir todos os procedimentos necessários para executar cada comando presente em um arquivo '.qry'.
*/


/*
Executa o comando dq presente no arquivo arqEntradaQry. Caso for necessário é gerado o arquivo arqSaidaT em formato '.txt' com o nome presente na string path.
Caso for removido quadra então o inteiro qtdQuadrasRemovidas é incrementado. A variavel canvas reuni todas quadras.
*/
void executardq(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas, int *qtdQuadrasRemovidas);

/*
Executa o comando dh presente no arquivo arqEntradaQry. Caso for necessário é gerado o arquivo arqSaidaT em formato '.txt' com o nome presente na string path. A variavel canvas reuni todos os hidrantes.
*/
void executardh(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas);

/*
Executa o comando ds presente no arquivo arqEntradaQry. Caso for necessário é gerado o arquivo arqSaidaT em formato '.txt' com o nome presente na string path. A variavel canvas reuni todos os semáfaros.
*/
void executards(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas);

/*
Executa o comando dt presente no arquivo arqEntradaQry. Caso for necessário é gerado o arquivo arqSaidaT em formato '.txt' com o nome presente na string path. A variavel canvas reuni todos as torres.
*/
void executardt(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas);

/*
Executa o comando Dq presente no arquivo arqEntradaQry. Caso for necessário é gerado o arquivo arqSaidaT em formato '.txt' com o nome presente na string path.
Caso for removido quadra então o inteiro qtdQuadrasRemovidas é incrementado. A variavel canvas reuni todas quadras.
*/
void executarDq(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas, int *qtdQuadrasRemovidas);

/*
Executa o comando Dh presente no arquivo arqEntradaQry. Caso for necessário é gerado o arquivo arqSaidaT em formato '.txt' com o nome presente na string path. A variavel canvas reuni todos os hidrantes.
*/
void executarDh(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas);

/*
Executa o comando Ds presente no arquivo arqEntradaQry. Caso for necessário é gerado o arquivo arqSaidaT em formato '.txt' com o nome presente na string path. A variavel canvas reuni todos os semáfaros.
*/
void executarDs(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas);

/*
Executa o comando Dt presente no arquivo arqEntradaQry. Caso for necessário é gerado o arquivo arqSaidaT em formato '.txt' com o nome presente na string path. A variavel canvas reuni todos as torres.
*/
void executarDt(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas);

/*
Executa o comando Crd? presente no arquivo arqEntradaQry. Caso for necessário é gerado o arquivo arqSaidaT em formato '.txt' com o nome presente na string path. A variavel canvas reuni todos os tads do problema.
*/
void executarCrd(FILE *arqEntradaQry , FILE **arqSaidaT, char *path, Canvas canvas);

/*
Executa o comando -acc0. Nesse procedimento é gerado um arquivo chamado 'resumo.txt' e esse arquivo estará no diretório dirPath. No arquivo resumo.txt será escrito em uma linha os dados arqNome, qtdQuadrasInseridas, qtdCompararacoesI, qtdQuadrasRemovidas e qtdCompararacoesR.
*/
void executarAcc0(char *dirPath, char *arqNome, char *extensao, int qtdQuadrasInseridas, int qtdCompararacoesI, int qtdQuadrasRemovidas, int qtdCompararacoesR);

/*
Executa o comando acc0. Nesse procedimento é gerado um arquivo chamado 'resumo.txt' e esse arquivo estará no diretório dirPath. No arquivo resumo.txt será escrito em uma linha os dados arqNome, qtdQuadrasInseridas, qtdCompararacoesI, qtdQuadrasRemovidas e qtdCompararacoesR.
*/
void executarAcc(char *dirPath, char *arqNome, char *extensao, int qtdQuadrasInseridas, int qtdCompararacoesI, int qtdQuadrasRemovidas, int qtdCompararacoesR);

#endif
