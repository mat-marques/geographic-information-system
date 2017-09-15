#ifndef SVG_H
#define SVG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***
Autor: Matheus Augusto Marques.
TAD: SVG.
Definição:
SVG (Scalable Vector Graphics) é uma linguagem xml desenvolvida para se criar
graficos vetoriais escalaveis. Portanto, o Svg nos permite criar círculos, retângulos, textos, retas, elipses e entre outros elementos vetoriais. Um arquivo svg é um arquivo com extensão '.svg'.
*/

/**
Cria e retorna um arquivo do tipo '.svg'.
*/
FILE *createSvg(char *arqName);

/**
Escreve no arquivo arqSvg uma string referente a tag svg de criação de um retângulo.
*/
void tagAbertura(FILE *arqSvg, double w, double h);

/**
Escreve no arquivo arqSvg uma string referente a tag svg de criação de um retângulo. As configurações do retângulo são dadas por w (Comprimento), h (altura), x (Coordenada x), y (Coordenada y) e uma cor de preenchimento.
*/
void tagRetangulo(FILE *arqSvg, double w, double h, double x, double y, char *cor);

/**
Escreve no arquivo arqSvg uma string referente a tag svg de criação de um retângulo. As configurações do retângulo são dadas por w (Comprimento), h (altura), x (Coordenada x), y (Coordenada y), uma cor de preenchimento (corB) e uma cor de contorno (corS).
*/
void tagRetangulo2(FILE *arqSvg,double w, double h, double x, double y, char *corB, char *corS);

/**
Escreve no arquivo arqSvg uma string referente a tag svg de criação de um círculo.  As configurações do círculo são dadas por r (raio), x (Coordenada x), y (Coordenada y), uma cor de preenchimento (corB) e uma cor de contorno (corS).
*/
void tagCirculo2(FILE *arqSvg,double r, double x, double y, char corB[60], char corS[60]);

/**
Escreve no arquivo arqSvg uma string referente a tag svg de criação de um círculo. As configurações do círculo são dadas por r (raio), x (Coordenada x), y (Coordenada y) e uma cor de preenchimento (cor).
*/
void tagCirculo(FILE *arqSvg, double r, double x, double y, char *cor);

/**
Escreve no arquivo arqSvg uma string referente a tag svg de criação de um texto.
O texto possui as coordenadas x e y.
*/
void tagTexto(FILE *arqSvg, double x, double y);

/**
Escreve no arquivo arqSvg uma string referente a tag svg de criação de um retângulo de sobreposição. As configurações do retângulo são dadas por w (Comprimento), h (altura), x (Coordenada x), y (Coordenada y). A cor de preenchimento e none e as bordas do retângulo são tracejadas.
*/
void tagRetanguloSobreposicao(FILE *arqSvg, double x, double y, double w, double h);

/**
Escreve no arquivo arqSvg uma string referente a um comando para criação de um ponto. O ponto possui coordenada x e y e uma cor de preenchimento.
*/
void pontos(FILE *arqSvg, double x, double y, char *cor);

/**
Escreve no arquivo arqSvg uma string referente a uma tag utilizada para fechamento de um arquivos svg.
*/
void tagFechamento(FILE *arqSvg);


#endif