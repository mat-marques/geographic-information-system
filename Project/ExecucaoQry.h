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
Remove as quadras dentro da região. (Reporta o id)
*/
long int executardq(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas, int *qtdQuadrasRemovidas);

/*
Executa o comando dh presente no arquivo arqEntradaQry. Caso for necessário é gerado o arquivo arqSaidaT em formato '.txt' com o nome presente na string path. A variavel canvas reuni todos os hidrantes.
Remove todos os hidrantes dentro da região. (Reporta o id)
*/
long int executardh(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas, int *qtdElementosRemovidos);

/*
Executa o comando ds presente no arquivo arqEntradaQry. Caso for necessário é gerado o arquivo arqSaidaT em formato '.txt' com o nome presente na string path. A variavel canvas reuni todos os semáfaros.
Remove todos os semáfaros dentro da região. (Reporta o id)
*/
long int executards(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas, int *qtdElementosRemovidos);

/*
Executa o comando dt presente no arquivo arqEntradaQry. Caso for necessário é gerado o arquivo arqSaidaT em formato '.txt' com o nome presente na string path. A variavel canvas reuni todos as torres.
Remove todos as torres dentro da região. (Reporta o id)
*/
long int executardt(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas, int *qtdElementosRemovidos);

/*
Executa o comando Dq presente no arquivo arqEntradaQry. Caso for necessário é gerado o arquivo arqSaidaT em formato '.txt' com o nome presente na string path.
Caso for removido quadra então o inteiro qtdQuadrasRemovidas é incrementado. A variavel canvas reuni todas quadras.
Remove as quadras dentro da região. (Reporta o id)
*/
long int executarDq(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas, int *qtdQuadrasRemovidas);

/*
Executa o comando Dh presente no arquivo arqEntradaQry. Caso for necessário é gerado o arquivo arqSaidaT em formato '.txt' com o nome presente na string path. A variavel canvas reuni todos os hidrantes.
Remove os hidrantes dentro da região. (Reporta o id)
*/
long int executarDh(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas, int *qtdElementosRemovidos);

/*
Executa o comando Ds presente no arquivo arqEntradaQry. Caso for necessário é gerado o arquivo arqSaidaT em formato '.txt' com o nome presente na string path. A variavel canvas reuni todos os semáfaros.
Remove os semafaros dentro da região. (Reporta o id)
*/
long int executarDs(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas, int *qtdElementosRemovidos);

/*
Executa o comando Dt presente no arquivo arqEntradaQry. Caso for necessário é gerado o arquivo arqSaidaT em formato '.txt' com o nome presente na string path. A variavel canvas reuni todos as torres.
Remove as torres de celular dentro da região. (Reporta o id)
*/
long int executarDt(FILE *arqEntradaQry, FILE **arqSaidaT, char *path, Canvas canvas, int *qtdElementosRemovidos);

/*
Executa o comando Crd? presente no arquivo arqEntradaQry. Caso for necessário é gerado o arquivo arqSaidaT em formato '.txt' com o nome presente na string path. A variavel canvas reuni todos os tads do problema.
O comando Crd? imprime no arquivo .txt as coordenadas e a espécie do equipamento urbano de um determinado cep ou com uma determinada
identificação.
*/
void executarCrd(FILE *arqEntradaQry , FILE **arqSaidaT, char *path, Canvas canvas);


/*
Executa o comando pc? presente no arquivo arqEntradaQry. Esse procedimento calcula o polígono de cobertura das rádio-bases da cidade (ou daquelas contidas na região retangular definida pelos parâmetros definidos em arqEntradaQry). Produz um arquivo svg mostrando a cidade e o polígono de cobertura.
*/
void executarPc(FILE *arqEntradaQry, char *arqNome, char *dirPath, char *extensao2, Canvas canvas);

/*
Executa o comando ac? presente no arquivo arqEntradaQry. Esse procedimento calcula e imprime no arquivo .txt a área (m2) do polígono de cobertura das rádio-bases da cidade (ou daquelas contidas na região retangular definida pelos
parâmetros definidos em arqEntradaQry).
*/
void executarAc(FILE *arqEntradaQry , FILE **arqSaidaT, char *path, Canvas canvas);


/*
Executa o comando -acc0. Nesse procedimento é gerado um arquivo chamado 'resumo.txt' e esse arquivo estará no diretório dirPath. No arquivo resumo.txt será escrito em uma linha os dados arqNome, qtdQuadrasInseridas, qtdCompararacoesI, qtdQuadrasRemovidas e qtdCompararacoesR.
*/
void executarAcc0(char *dirPath, char *arqNome, char *extensao, int qtdQuadrasInseridas, int qtdCompararacoesI, int qtdQuadrasRemovidas, int qtdCompararacoesR);

/*
Executa o comando acc0. Nesse procedimento é gerado um arquivo chamado 'resumo.txt' e esse arquivo estará no diretório dirPath. No arquivo resumo.txt será escrito em uma linha os dados arqNome, qtdQuadrasInseridas, qtdCompararacoesI, qtdQuadrasRemovidas e qtdCompararacoesR.
*/
void executarAcc(char *dirPath, char *arqNome, char *extensao, int qtdQuadrasInseridas, int qtdCompararacoesI, int qtdQuadrasRemovidas, int qtdCompararacoesR);

#endif
