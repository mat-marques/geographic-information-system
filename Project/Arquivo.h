#ifndef ARQUIVO_H
#define ARQUIVO_H
#include<stdio.h>
/*
Autor: Matheus Augusto Marques.
TAD: Arquivo.
Definição:
Um arquivo é um documento textual que é composto por um conjunto de símbolos. Um símbolo pode ser determinado por uma letra de um alfabeto, números etc.
*/

/*
Abre um arquivo referente ao caminho path para leitura.
Fecha a aplicação se path for inválido ou o arquivo não existir.
*/
FILE *createArqR(char *path);

/**
Cria ou abre um arquivo referente ao caminho path para escrita. Caso o arquivo já exista, então o conteúdo em seu interior será apagado.
Fecha a aplicação se path for inválido ou a abertura do arquivo for inválida.
*/
FILE *createArqW(char *path);

/**
Cria ou abre um arquivo referente ao path para ser acrescentado informação no conteúdo que já existe no arquivo.
Fecha a aplicação se path for inválido ou a abertura do arquivo for inválida.
*/
FILE *createArqA(char *path);

/**
Escreve no arquivo arq um caracter.
Só escreve no arquivo arq caso ele tenha sido criado pelas funções createArqW ou createArqA.
*/
void fillArq(FILE *arq, char caracter);

/**
Escreve no arquivo arq uma string palavra.
Só escreve no arquivo arq caso ele tenha sido criado pelas funções createArqW ou createArqA.
*/
void fillArq1(FILE *arq, char *palavra);

/**
Escreve no arquivo arq um número real out.
Só escreve no arquivo arq caso ele tenha sido criado pelas funções createArqW ou createArqA.
*/
void fillArq2(FILE *arq, float out);

/**
Escreve no arquivo arq um número inteiro out.
Só escreve no arquivo arq caso ele tenha sido criado pelas funções createArqW ou createArqA.
*/
void fillArq3(FILE *arq, int out);

/**
Escreve no arquivo arq um número real out com maior precisão numérica.
Só escreve no arquivo arq caso ele tenha sido criado pelas funções createArqW ou createArqA.
*/
void fillArq4(FILE *arq, double out);

/**
Escreve no arquivo arq um caracter que representa um espaço.
Só escreve no arquivo arq caso ele tenha sido criado pelas funções createArqW ou createArqA.
*/
void fillSpace(FILE *arq);

/**
Escreve no arquivo arq um caracter que representa um Tab.
Só escreve no arquivo arq caso ele tenha sido criado pelas funções createArqW ou createArqA.
*/
void fillTab(FILE *arq);

/**
Escreve no arquivo arq um caracter que representa uma quebra de linha.
Só escreve no arquivo arq caso ele tenha sido criado pelas funções createArqW ou createArqA.
*/
void fillBreakLine(FILE *arq);

/*
A função retorna a quantidade de caracteres em uma linha do arquivo file.
*/
int getQuantidade(FILE *file);

/*
A função retorna uma string contendo todos os caracteres existentes em uma linha do arquivo. O tamanho da string é determinado por quantity.
*/
char *getString(FILE *file, int quantity);

#endif
