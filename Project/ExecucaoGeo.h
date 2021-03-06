#ifndef EXECUCAOGEO_H
#define EXECUCAOGEO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Canvas.h"
#include "Cor.h"
#include "Cidade.h"

/**
   Autor:Matheus Augusto Marques.
   Módulo: ExecucaoGeo
   Definição:
   O módulo ExecucaoGeo tem por objetivo abrigar todos os procedimentos ou funções necessárias para execução dos comandos presentes em um arquivo '.geo'.
 */


/*
   Calcula a envoltória convexa. A função retorna a quantidade de comparações para inserir um elemento no canvas.
   O argumento type pode receber os inteiros:
   1 : Quadra;
   2 : Hidrante;
   3 : Semáfaro.
   4 : Torre;
   5 : Retângulo;
   6 : Círculo;
 */
long int executarConvexHull(List list, Canvas canvas, int type);


/*
   Executa o comando C. Faz a leitura dos parâmetros do comando C no arquivo arqEntradaGeo e cria um círculo e o armazena no canvas.
 */
void executarC(FILE *arqEntradaGeo, List list);

/*
   Executa o comando R. Faz a leitura dos parâmetros do comando R no arquivo arqEntradaGeo e cria um retângulo e o armazena no canvas.
 */
void executarR(FILE *arqEntradaGeo, List list);

/*
   Executa o comando D. Faz a leitura dos parâmetros do comando D no arquivo arqEntradaGeo. Procura os ids i e j das figuras geométricas no canvas e escreve o resultado do comando D em arqSaidaT. O comando D calcula a distância dos centros de massa de duas figuras geométricas.
 */
void executarD(FILE *arqEntradaGeo,  FILE *arqSaidaT, Canvas canvas);

/*
   Executa o comando I. Faz a leitura dos parâmetros do comando I no arquivo arqEntradaGeo. Procura o id j de uma figura geométrica no canvas e escreve o resultado do comando I em arqSaidaT. O comando I verifica se uma dados ponto no plano está dentro de uma figura geométrica.
 */
void executarI(FILE *arqEntradaGeo, FILE *arqSaidaT, Canvas canvas);

/*
   Executa o comando O. Faz a leitura dos parâmetros do comando O no arquivo arqEntradaGeo. Procura os ids i e j das figuras geométricas no canvas e escreve o resultado do comando O em arqSaidaT. Ou seja, verifica se duas figuras geométricas se spbrepõem.
 */
void executarO(FILE *arqEntradaGeo, FILE *arqSaidaT, Canvas canvas);

/*
   Executa o comando A. Faz a leitura dos parâmetros do comando A no arquivo arqEntradaGeo e armazena os dados do canvas referente a círculos e retângulos em um arquivo de saída obtido com a concatenação de dirPath + arqNome + extensao. O comando A gera um arquivo svg que contém os vertices das figuras geométrica representadas.
 */
void executarA(FILE *arqEntradaGeo, Canvas canvas, char *arqNome,char *dirPath, char *extensao2);

/*
   Executa o comando Q. Faz a leitura dos parâmetros do comando Q no arquivo arqEntradaGeo e armazena esses dados no canvas. O inteiro qtdQuadrasInseridas é incrementado a cada quadra inserida.
 */
void executarQ(FILE *arqEntradaGeo, List list, Cor cor, HashTable hash);


/*
   Executa o comando H. Faz a leitura dos parâmetros do comando H no arquivo arqEntradaGeo e armazena esses dados no canvas.
 */
void executarH(FILE *arqEntradaGeo, List list, Cor cor);


/*
   Executa o comando S. Faz a leitura dos parâmetros do comando S no arquivo arqEntradaGeo e armazena esses dados no canvas.
 */
void executarS(FILE *arqEntradaGeo, List list, Cor cor);


/*
   Executa o comando T. Faz a leitura dos parâmetros do comando T no arquivo arqEntradaGeo e armazena esses dados no canvas.
 */
void executarT(FILE *arqEntradaGeo, List list, Cor cor);

/*
   Executa o comando Cq. Faz a leitura dos parâmetros do comando Cq no arquivo arqEntradaGeo e armazena esses dados no canvas.
 */
Cor executarCq(FILE *arqEntradaGeo);

/*
   Executa o comando Ch. Faz a leitura dos parâmetros do comando Ch no arquivo arqEntradaGeo e armazena esses dados no canvas.
 */
Cor executarCh(FILE *arqEntradaGeo);

/*
   Executa o comando Ct. Faz a leitura dos parâmetros do comando Ct no arquivo arqEntradaGeo e armazena esses dados no canvas.
 */
Cor executarCt(FILE *arqEntradaGeo);

/*
   Executa o comando Cs. Faz a leitura dos parâmetros do comando Cs no arquivo arqEntradaGeo e armazena esses dados no canvas.
 */
Cor executarCs(FILE *arqEntradaGeo);

/*
   O procedimento executa o comando hI contido no arquivo arqEntradaGeo. Esse procedimento informa a vazão (l/s) do hidrante id. O hidrante de código id deve ter sido inserido anteriormente na cidade por um comando h.
 */
void executarHI(FILE *arqEntradaGeo, Canvas canvas);

/*
   O procedimento executa o comando TI contido no arquivo arqEntradaGeo. Esse procedimento informa o raio (m) de alcance da radio- base id. A rádio-base id deve ter sido inserido anteriormente por um comando t.
 */
void executarTI(FILE *arqEntradaGeo, Canvas canvas);

/*
   O procedimento executa o comando hI contido no arquivo arqEntradaGeo. Esse procedimento informa o tempo (s) do ciclo (verde,amarelo, vermelho) do semaforo id. O semáforo deve ter sido inserido anteriormente por um comando s.
 */
void executarSI(FILE *arqEntradaGeo, Canvas canvas);


/*
   O procedimento executa o comando hI contido no arquivo arqEntradaGeo.  Esse procedimento Informa que torre de celular de identificação id pertence à operadora SercomtUEL.
 */
void executarGeoSu(FILE *arqEntradaGeo, Canvas canvas, HashTable hash);


/*
   O procedimento executa o comando hI contido no arquivo arqEntradaGeo.  Esse procedimento Informa que torre de celular de identificação id pertence à operadora UELMobile.
 */
void executarGeoUm(FILE *arqEntradaGeo, Canvas canvas, HashTable hash);


/**
   Verifica e retorna um caracter 't' ou 'f' se dois retângulos estão sobrepostos.
   Utiliza procedimentos do módulo OperacoesF e procedimentos do Tad Arquivo.
 */
char comandoOrr(FILE *arqSaidaT,double w1,double h1, double x1, double y1, double w2, double h2, double x2, double y2);

/**
   Verifica e retorna um caracter 't' ou 'f' se um retângulo e um círculo estão sobrepostos.
   Utiliza procedimentos do módulo OperacoesF e procedimentos do Tad Arquivo.
 */
char comandoOrc(FILE *arqSaidaT, double w1,double h1, double x1, double y1, double r2, double x2, double y2);

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

/*
   A função inicializa uma cor.
   O inteiro type pode receber um dos valores a seguir:
   1 - Cor para a quadra.
   2 - Cor para a hidrante.
   3 - Cor para a semafaro.
   4 - Cor para a torre.
 */
Cor setCores(int type);

#endif
