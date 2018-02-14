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
   O módulo Processamento contém um procedimento para processar os dados iniciais.
   O restante dos procedimentos e e funções são internas.
 */


/*
   O procedimento tem a finalidade de organizar dentro de si todas as chamadas das 4 etapas do problema.
   Argumentos da main: argv e argc.
 */
void processarDados(char **argv, int argc);

#endif
