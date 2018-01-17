#ifndef EXECUCAOQRY3_H
#define EXECUCAOQRY3_H

#include "Canvas.h"

/*
   Autor: Matheus Augusto Marques.
   Módulo: Esse módulo contém todas os procedimentos necessários para executar os comandos do qry relacionados ao armazenamento de dados em registradores.
 */


/*
   Armazena no registrador r a posição geográficao endereço onde o telefone fone
   foi conectado por último.
 */
void executarQryF(Canvas canvas, FILE *arqEntradaQry);

/*
   Armazena no registrador r a posição geográfica da residência do morador de cpf.
 */
void executarQryM(Canvas canvas, FILE *arqEntradaQry);


/*
   Armazena no registrador r a posição geográfica do endereço cep/face/num.
 */
void executarQryE(Canvas canvas, FILE *arqEntradaQry);


/*
   Armazena no registrador r a posição geográfica do equipamento urbano cujo
   identificador é id.
 */
void executarQryG(Canvas canvas, FILE *arqEntradaQry);


/*
   Armazena no registrador r a posição geográfica (x,y).
 */
void executarQryXY(Canvas canvas, FILE *arqEntradaQry);


/*
   Armazena no registrador r1 o estabelecimento comercial mais próximo da
   posição armazenada no registrador r2.
 */
void executarQryTP(Canvas canvas, FILE *arqEntradaQry);


/*
   Qual o melhor trajeto entre a origem está que no registrador r1 e o destino que está no registrador r2. Caso o percurso peça a representação pictórica, o trajeto deve ser pintado com a cor especificada.
 */
void executarQryP(Canvas canvas, FILE *arqEntradaQry);



#endif
