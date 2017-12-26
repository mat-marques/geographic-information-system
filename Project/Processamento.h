#ifndef PROCESSAMENTO_H
#define PROCESSAMENTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Canvas.h"

/*
   Autor: Matheus Augusto Marques
   Módulo: PROCESSAMENTO.
   O módulo Processamento contém um conjunto de procedimentos que tem o objetivo de dividir a execução do problema em 4 etapas. Primeira etapa: Abertura dos arquivos de entrada. Segunda etapa: Execução dos comando do arquivo '.geo'. Terceira etapa (Pode existir ou não): Execução dos comando do arquivo '.qry'. Quarta etapa: Resultado dos arquivos de entrada.
 */

/*
   O procedimento tem a finalidade de abrir os arquivos de entrada do problema (Variável arqEntradaGeo e arqEntradaQry). No processo de abertura dos arquivos é armazenado em variáveis o nome do arquivo de entrada (Variável arqNome) , diretório do arquivo de saída (Variável dirPath) e nome do arquivo de saída svg (Variável exitFileSvg). Também é armazenado se um dos comando -acc ou -acc0 foi utilizado na entrada do problema. Etapa 1.
 */
void abrirArquivos(FILE **arqEntradaGeo, FILE **arqEntradaQry,
                   FILE **arqEntradaEc, FILE **arqEntradaPm,
                   FILE **arqEntradaTm, char **arqNome, char **dirPath,
                   char **exitFileSvg, char *acc0, char *acc, char **argv,
                   int argc);

/*
   O procedimento tem a finalidade de apresentar no arquivo de saída svg (arqSaidaSvg) os resultados dos procedimentos obtidos em executarComandosGeo e executarComandosQry (Resultados no canvas). Etapa 4.
 */
void finalizarExecucao(FILE *arqSaidaSvg, Canvas canvas);

/*
   A função tem a finalidade de executar todos os comando necessários para processar o arquivo '.geo'. Etapa 2.
   Arquivo de entrada arqEntradaGeo.
   Nome do arquivo de entrada arqNome.
   Diretório de saida dirPath.
   Quantidade de quadra inseridas.
   retorna a quantidade de comparações para inserir retangulos, círculos, quadras, semafaros, torres e hidrantes no canvas.
 */
long int executarComandosGeo(FILE *arqEntradaGeo, char *arqNome, char *dirPath, Canvas canvas, int *qtdQuadrasInseridas, long int *qtdCompararacoesI);

/*
   O procedimento tem a finalidade de executar todos os comando necessários para processar o arquivo '.qry'. Etapa 3.
   Arquivo de entrada arqEntradaQry.
   Nome do arquivo de entrada arqNome.
   Diretório de saida dirPath.
   Quantidade de quadra removidas.
   retorna a quantidade de comparações para remover quadras, semafaros, torres e hidrantes do canvas.
 */
long int executarComandosQry(FILE *arqEntradaQry,char *arqNome, char *dirPath, Canvas canvas,int *qtdQuadrasRemovidas,long int *qtdCompararacoesR,int *qtdElementosRemovidos);

/*
   O procedimento tem a finalidade de organizar dentro de si todas as chamadas das 4 etapas do problema.
   Argumentos da main: argv e argc.
 */
void processarDados(char **argv, int argc);

#endif
