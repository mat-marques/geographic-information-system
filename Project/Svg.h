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
   Escreve no arquivo arqSvg uma string referente a tag svg de criação de um círculo com opacidade modificada.  As configurações do círculo são dadas por r (raio), x (Coordenada x), y (Coordenada y), uma cor de preenchimento (corB).
 */
void tagCirculoOpacity(FILE *arqSvg, double r, double x, double y, char *cor);


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
   Escreve no arquivo arqSvg uma string referente a tag svg de criação de um texto.
   O texto possui as coordenadas x e y, uma cor e um tamanho.
 */
void tagTexto2(FILE *arqSvg, char *texto, char *cor, int fontSize, double x, double y);


/*
   Escreve no arquivo arqSvg uma string referente a tag svg de criação de um texto.
   O texto possui as coordenadas x e y, uma cor, um tamanho, uma família de fontes e um id.
 */
void tagTexto3(FILE *arqSvg, int id, char *texto, char *cor, int fontSize,
               char *fontFamily, double x, double y);


/**
   Escreve no arquivo arqSvg uma string referente a tag svg de criação de um retângulo de sobreposição. As configurações do retângulo são dadas por w (Comprimento), h (altura), x (Coordenada x), y (Coordenada y). A cor de preenchimento e none e as bordas do retângulo são tracejadas.
 */
void tagRetanguloSobreposicao(FILE *arqSvg, double x, double y, double w, double h);

/**
   Escreve no arquivo arqSvg uma string referente a um comando para criação de um ponto. O ponto possui coordenada x e y e uma cor de preenchimento.
 */
void pontos(FILE *arqSvg, double x, double y, char *cor);


/**
   Escreve no arquivo arqSvg uma string referente a um comando para criação de um linha. A linha conecta dois pontos. As coordenadas x1, y1 e x2, y2 representam os pontos que seram ligados pela linha. A linha também recebe uma cor de preenchimento.
 */
void linha(FILE *arqSvg, double x1, double y1, double x2, double y2, char *cor);


/*
   Escreve no arquivo arqSvg uma string referente a um comando para criação de um linha. A linha conecta dois pontos. As coordenadas x1, y1 e x2, y2 representam os pontos que seram ligados pela linha. A linha também recebe uma cor de preenchimento, um id e uma espessura.
 */
void tagLinha2(FILE *arqSvg, int id, double x1, double y1, double x2, double y2, char *cor, int sizeLine);


/*
   Escreve no arquivo arqSvg uma string referente a um comando para criação de multiplas linha. Cada linha conecta dois pontos. As coordenadas dos pontos estão na variável. A linha também recebe uma cor de preenchimento, um id, uma espessura e uma cor que preencherá o espaço de conexão entre a linhas.
 */
void tagMultiplasLinhas(FILE *arqSvg, int id, double *pontos, int n, char *corL, char *corF, int lineSize);


/*
   Escreve no arquivo arqSvg uma string referente a tag svg de criação de um poligono.
   O poligono possui n pontos contidos no vetor pontos. As linhas que conectam os pontos possuem uma cor(corL) e uma espessura lineSize. O poligono possui uma cor de preenchimento(corF). Ele possui um id único.
 */
void tagPoligono(FILE *arqSvg, int id, double *pontos, int n, char *corL, char *corF, int lineSize);


/*
   Escreve no arquivo arqSvg uma string referente a tag svg de criação de uma elipse.
   A elipse possui centro em cx cy. E também possui um raio em x (rx) e um em y (ry). A linha de contorno tem uma cor(corL) e uma espessura(lineSize). O valor de corF representa a cor de preenchimento da ellipse.
 */
void tagEllipse(FILE *arqSvg, int id, double cx, double cy, double rx, double ry, char *corL, char *corF, int lineSize);


/* Define um seta para o canvas. Deve ser usado antes do procedimento arrow. */
void defArrow(FILE *arqSvg, char *cor);


/* Define um seta entre dois pontos. */
void arrow(FILE *arqSvg, double x1, double y1, double x2, double y2, char *cor);

/**
   Escreve no arquivo arqSvg uma string referente a uma tag utilizada para fechamento de um arquivos svg.
 */
void tagFechamento(FILE *arqSvg);


#endif
