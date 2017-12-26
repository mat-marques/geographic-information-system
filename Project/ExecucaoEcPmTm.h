#ifndef EXECUCAOECPMTM_H
#define EXECUCAOECPMTM_H

#include "Canvas.h"

/*
   Autor: Matheus Augusto Marques.
   Módulo ExecucaoEcPmTm:
   O módulo contém as funções necessárias para serem utilizadas no processamento dos comandos contidos nos arquivos de entrada ec, pm e tm.
 */

/*
   O procedimento executa o comando 't' do arquivo '.ec'. O comando 't' define tipo de estabelecimento comercial.
 */
void executarEcT(Canvas canvas, FILE *arqEntradaEc);

/*
   O procedimento executa o comando 'e' do arquivo '.ec'. O comando 'e' insere um novo estabelecimento comercial de um determinado tipo (codt), localizado em um dado endereço (cep,face,num), que possui um dado cnpj e tem um dado nome.
 */
void executarEcE(Canvas canvas, FILE *arqEntradaEc);

/*
   O procedimento executa o comando 'p' do arquivo '.pm'. O comando 'p'insere pessoa identificada por cpf, nomeada (nome,sobrenome), de um certo sexo (M,F), nascida numa determinada data (dd/mm/aaaa).
 */
void executarPmP(Canvas canvas, FILE *arqEntradaPm);

/*
   O procedimento executa o comando 'm' do arquivo '.pm'. O comando 'm' informa que um dada pessoa (cpf) mora num dado endereço(cep,face,num,compl).
 */
void executarPmM(Canvas canvas, FILE *arqEntradaPm);

/*
   O procedimento executa o comando 'su' do arquivo '.tm'. O comando 'su' define que uma Pessoa identificada por cpf é cliente da linha móvel numcel da SercomtUEL.
 */
void executarTmSu(Canvas canvas, FILE *arqEntradaTm);

/*
   O procedimento executa o comando 'um' do arquivo '.tm'. O comando 'um' define que uma Pessoa identificada por cpf é cliente da linha móvel numcel da UELMobile.
 */
void executarTmUm(Canvas canvas, FILE *arqEntradaTm);

#endif
