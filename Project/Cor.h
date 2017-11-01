#ifndef COR_H
#define COR_H

typedef void* Cor;

/**
Autor: Matheus Augusto Marques.
TAD: Cor.
Definição:
Uma cor é definida por uma cor de preenchimento , uma cor de contorno e um número de identificação chamado id. As cores de preenchimento e contorno são as cores definidas pelos padrões do SVG.
*/

/*
Cria uma cor com as propriedades passadas como parâmetro. A cor criada possuira uma cor de preenchimento definida por corPreenchimento , uma cor de contorno definida por corContorno e um id definido por id.
*/
Cor criaCor(char *corPreenchimento, char *corContorno, int id);

/*
Retorna a cor de identificação de uma cor.
*/
int getCorId(Cor cor);

/*
Retorna a cor de preenchimento de uma cor.
*/
char *getCorP(Cor cor);

/*
Substitui a cor de preenchimento de uma cor.
*/
void setCorP(Cor cor, char *corPreenchimento);

/*
Retorna a cor de contorno de uma cor.
*/
char *getCorC(Cor cor);

/*
Substitui a cor de contorno de uma cor.
*/
void setCorC(Cor cor, char *corContorno);

/*
Reseta os componentes de uma cor para vazio.
*/
void resetarCores(Cor cor);

/*
O procedimento remove da memória cor.
*/
void removeCor(Cor cor);

#endif
