#ifndef STRINGO_H
#define STRINGO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
Autor: Matheus Augusto Marques.
Módulo:STRINGO.
O módulo stringO é composto por um conjunto de funções e precedimentos que manipulam strings.
*/

char *criarString(char *char1);
/**
Verifica e retorna a quantidades de elementos em um linha de arquivo texto até encontra espaço.
Retorna um inteiro.
*/
int qtdCaracteres(FILE *file);

/**
Aloca uma string de tamanho size.
size>0.
*/
char *alocarString(int size);

/**
Verifica e retorna a quantidade de caracteres em uma substring dentro de uma outra string.
a contagem se inicia na posição index e termina quando encontrar um espaço.
Retorna um inteiro.
*/
int sizeStringElement(char *oldString, int *index);

/**
Retorna uma substring pertencente a oldString com tamanho qtd.
A substring começa na posição index de oldString.
A função retorna uma string.
*/
char *newStringElement(char *oldString, int qtd, int index);

/**
Desaloca um string.
*/
void desalocar(char *valor);

/**
Retorna uma string.
A função concatena a string concatenar com a string palavra.Assim, gerando e retornando uma nova palavra. Ambas as strings devem ser diferente do vazio.
*/
char *concatenarStrings(char *concatenar, char *palavra);

/**
Verifica se nome possui '/', "./" ou "../" como substring e também verifica se o diretorio possui o caracter '/' como substring.
Para a string nome é verificado os caracteres iniciais e para o diretório os
caracteres finais.
Retorna 1 caso o nome possui uma barra e diretorio não.
Retorna 2 caso o nome não possui uma barra e diretorio possua barra.
Retorna 3 caso ambos nome e diretorio possuam barra.
Retorna 4 caso ambos nome e diretorio não possuam barra.
Retorna 5 caso nome possua "./" e diretorio não tenha barra.
Retorna 6 caso nome possua "./" e diretorio tenha barra.
Retorna 7 caso nome possua "../" e diretorio não tenha barra.
Retorna 8 caso nome possua "../" e diretorio tenha barra.
Os números retornados são caracteres.
Retorna 'f' caso as strings sejam nulas.
*/
char verificarBarra(char *nome, char *diretorio);

/**
Concatena o caracter '/' com palavra retornando uma nova string.
*/
char *colocarBarra(char *palavra);

/**
Verifica se arqNome tem como substring a extensão '.geo'.
Caso sim retorna 't' ou caso não retorna 'f'.
*/
char verificarGeo(char *arqNome);

#endif
