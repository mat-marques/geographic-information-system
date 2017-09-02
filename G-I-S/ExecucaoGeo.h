#ifndef EXECUCAOGEO_H
#define EXECUCAOGEO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Canvas.h"
/**
Autor:Matheus Augusto Marques.
Módulo: ExecucaoGeo
Definição:
O módulo ExecucaoGeo tem por objetivo abrigar todos os procedimentos necessários para execução dos comandos presentes em um arquivo '.geo'.

*/

/*
Executa o comando C. Faz a leitura dos parâmetros do comando C no arquivo arqEntradaGeo e cria um círculo e o armazena no canvas.
*/
void executarC(FILE *arqEntradaGeo, Canvas canvas);

/*
Executa o comando R. Faz a leitura dos parâmetros do comando R no arquivo arqEntradaGeo e cria um retângulo e o armazena no canvas.
*/
void executarR(FILE *arqEntradaGeo, Canvas canvas);

/*
Executa o comando D. Faz a leitura dos parâmetros do comando D no arquivo arqEntradaGeo. Procura os ids i e j das figuras geométricas no canvas e escreve o resultado do comando D em arqSaidaT.
*/
void executarD(FILE *arqEntradaGeo,  FILE *arqSaidaT, Canvas canvas);

/*
Executa o comando I. Faz a leitura dos parâmetros do comando I no arquivo arqEntradaGeo. Procura o id j de uma figura geométrica no canvas e escreve o resultado do comando I em arqSaidaT.
*/
void executarI(FILE *arqEntradaGeo, FILE *arqSaidaT, Canvas canvas);

/*
Executa o comando O. Faz a leitura dos parâmetros do comando O no arquivo arqEntradaGeo. Procura os ids i e j das figuras geométricas no canvas e escreve o resultado do comando O em arqSaidaT.
*/
void executarO(FILE *arqEntradaGeo, FILE *arqSaidaT, Canvas canvas);

/*
Executa o comando A. Faz a leitura dos parâmetros do comando A no arquivo arqEntradaGeo e armazena os dados do canvas referente a círculos e retângulos em um arquivo de saída obtido com a concatenação de dirPath + arqNome + extensao.
*/
void executarA(FILE *arqEntradaGeo, Canvas canvas, char *arqNome,char *dirPath, char *extensao2);

/*
Executa o comando Q. Faz a leitura dos parâmetros do comando Q no arquivo arqEntradaGeo e armazena esses dados no canvas. O inteiro qtdQuadrasInseridas é incrementado a cada quadra inserida.
*/
void executarQ(FILE *arqEntradaGeo,  Canvas canvas, int *qtdQuadrasInseridas);

/*
Executa o comando H. Faz a leitura dos parâmetros do comando H no arquivo arqEntradaGeo e armazena esses dados no canvas.
*/
void executarH(FILE *arqEntradaGeo, Canvas canvas);

/*
Executa o comando S. Faz a leitura dos parâmetros do comando S no arquivo arqEntradaGeo e armazena esses dados no canvas.
*/
void executarS(FILE *arqEntradaGeo, Canvas canvas);

/*
Executa o comando T. Faz a leitura dos parâmetros do comando T no arquivo arqEntradaGeo e armazena esses dados no canvas.
*/
void executarT(FILE *arqEntradaGeo, Canvas canvas);

/*
Executa o comando Cq. Faz a leitura dos parâmetros do comando Cq no arquivo arqEntradaGeo e armazena esses dados no canvas.
*/
void executarCq(FILE *arqEntradaGeo, Canvas canvas);

/*
Executa o comando Ch. Faz a leitura dos parâmetros do comando Ch no arquivo arqEntradaGeo e armazena esses dados no canvas.
*/
void executarCh(FILE *arqEntradaGeo, Canvas canvas);

/*
Executa o comando Ct. Faz a leitura dos parâmetros do comando Ct no arquivo arqEntradaGeo e armazena esses dados no canvas.
*/
void executarCt(FILE *arqEntradaGeo, Canvas canvas);

/*
Executa o comando Cs. Faz a leitura dos parâmetros do comando Cs no arquivo arqEntradaGeo e armazena esses dados no canvas.
*/
void executarCs(FILE *arqEntradaGeo, Canvas canvas);

/**
Verifica e retorna um caracter 't' ou 'f' se dois retângulos estão sobrepostos.
Utiliza procedimentos do módulo OperacoesF e procedimentos do Tad Arquivo.
*/
char comandoOrr(FILE *arqSaidaT,double w1,double h1, double x1, double y1, double w2, double h2, double x2, double y2);

/**
Verifica e retorna um caracter 't' ou 'f' se um retângulo e um círculo estão sobrepostos.
Utiliza procedimentos do módulo OperacoesF e procedimentos do Tad Arquivo.
*/
char comandoOrc(FILE *arqSaidaT, double w1 ,double h1, double x1, double y1, double r2, double x2, double y2);

/**
Verifica e retorna um caracter 't' ou 'f' se dois círculos estão sobrepostos.
Utiliza procedimentos do módulo OperacoesF e procedimentos do Tad Arquivo.
*/
char comandoOcc(FILE *arqSaidaT,double r1, double x1, double y1, double r2, double x2, double y2);

/**
Calcula a distância dos centros de massa de dois polígonos.
Utiliza procedimentos do módulo OperacoesF e procedimentos do Tad Arquivo.
*/
void comandoD(FILE *arqSaidaT,double x1, double y1, double x2, double y2);

/**
Verifica se um ponto qualquer é interno a um círculo.
Utiliza procedimentos do módulo OperacoesF e procedimentos do Tad Arquivo.
*/
void comandoIc(FILE *arqSaidaT,double x1, double y1, double x2, double y2, double r);

/**
Verifica se um ponto qualquer é interno a um retângulo.
Utiliza procedimentos do módulo OperacoesF e procedimentos do Tad Arquivo.
*/
void comandoIr(FILE *arqSaidaT,double w, double h, double x1, double y1,double x2,double y2);

#endif
