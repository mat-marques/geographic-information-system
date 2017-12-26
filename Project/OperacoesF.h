#ifndef OPERACOES_H
#define OPERACOESF_H

#include <math.h>

/**
   Autor: Matheus Augusto Marques.
   Módulo: OPERACOESF.
   O módulo OperacoesF contém um conjunto de operações sobre as figuras geométricas círculo e retângulo e também sobre pontos no plano.
 */

/**
   Calcula e retorna um número real que representa a distância entre dois pontos.
   x1 e y1 representa um ponto.
   x2 e y2 representa um ponto.
 */
double distanciaEntrePontos(double x1, double y1, double x2, double y2);

/*
   Verifica se um retângulo está inteiramente dentro de outro retângulo.
   Retorna t se for verdadeiro e f se for falso.
   w1(comprimento), h1(altura), x1(coordenada x), y1(coordenada y) definem um retângulo.
   w2(comprimento), h2(altura), x2(coordenada x), y2(coordenada y) definem um retângulo.
 */
char verificarInteiramenteSobrepostoRR(double w1,double h1, double x1, double y1,double w2, double h2, double x2, double y2);

/*
   Verifica se um círculo está inteiramente dentro de um retângulo.
   Retorna t se for verdadeiro e f se for falso.
   w1(comprimento), h1(altura), x1(coordenada x), y1(coordenada y) definem um retângulo.
   r2(raio), x2(coordenada x), y2(coordenada y) definem um círculo.
 */
char verificarInteiramenteSobrepostoRC(double w1, double h1, double x1, double y1, double r2, double x2, double y2);

/*
   Verifica se um retângulo está inteiramente dentro de um círculo.
   Retorna t se for verdadeiro e f se for falso.
   w1(comprimento), h1(altura), x1(coordenada x), y1(coordenada y) definem um retângulo.
   r2(raio), x2(coordenada x), y2(coordenada y) definem um círculo.
 */
char verificarInteiramenteSobrepostoCR(double w1, double h1, double x1, double y1, double r2, double x2, double y2);

/*
   Verifica se um círculo está inteiramente dentro de outro círculo.
   Retorna t se for verdadeiro e f se for falso.
   r1(raio), x1(coordenada x), y1(coordenada y) definem um círculo.
   r2(raio), x2(coordenada x), y2(coordenada y) definem um círculo.
 */
char verificarInteiramenteSobrepostoCC(double r1, double x1, double y1, double r2, double x2, double y2);

/**
   Verifica e retorna um caracter 't' se dois retângulos se sobrepoe e 'f' caso não.
   w1(comprimento), h1(altura), x1(coordenada x), y1(coordenada y) definem um retângulo.
   w2(comprimento), h2(altura), x2(coordenada x), y2(coordenada y) definem um retângulo.
 */
char verificarSobreposicaoRR(double w1,double h1, double x1, double y1,double w2, double h2, double x2, double y2);

/**
   Verifica e retorna um caracter 't' se dois círculos se sobrepoe ou 'f' caso não.
   r1(raio), x1(coordenada x), y1(coordenada y) definem um círculo.
   r2(raio), x2(coordenada x), y2(coordenada y) definem um círculo.
 */
char verificarSobreposicaoCC(double r1, double x1, double y1, double r2, double x2, double y2);

/**
   Verifica e retorna um caracter 't' se um retângulo e um círculo se sobrepoe ou 'f' caso não.
   w1(comprimento), h1(altura), x1(coordenada x), y1(coordenada y) definem um retângulo.
   r2(raio), x2(coordenada x), y2(coordenada y) definem um círculo.
 */
char verificarSobreposicaoRC(double w1, double h1, double x1, double y1, double r2, double x2, double y2);

/**
   Calcula as configurações de um retângulo que englobara dentro de si dois círculos sobrepostos.
   r1(raio), x1(coordenada x), y1(coordenada y) definem um círculo.
   r2(raio), x2(coordenada x), y2(coordenada y) definem um círculo.
   w(comprimento), h(altura), x(coordenada x), y(coordenada y) definem um retângulo.
 */
void sobreposicaoCC(double r1, double x1, double y1,double r2, double x2, double y2, double *w, double *h, double *x, double *y);

/**
   Calcula as configurações de um retângulo que englobara dentro de si dois retângulos sobrepostos.
   w1(comprimento), h1(altura), x1(coordenada x), y1(coordenada y) definem um retângulo.
   w2(comprimento), h2(altura), x2(coordenada x), y2(coordenada y) definem um retângulo.
   w(comprimento), h(altura), x(coordenada x), y(coordenada y) definem um retângulo.
 */
void sobreposicaoRR(double w1,double h1, double x1, double y1,double w2, double h2, double x2, double y2, double *w, double *h, double *x, double *y);

/**
   Calcula as configurações de um retângulo que englobara dentro de si um retângulo e um círculo sobrepostos.
   w1(comprimento), h1(altura), x1(coordenada x), y1(coordenada y) definem um retângulo.
   r2(raio), x2(coordenada x), y2(coordenada y) definem um círculo.
   w(comprimento), h(altura), x(coordenada x), y(coordenada y) definem um retângulo.
 */
void sobreposicaoRC(double w1, double h1, double x1, double y1, double r2, double x2, double y2, double *w, double *h, double *x, double *y);

/**
   Verifica e retorna um caracter 't' se um ponto é interno a  um retângulo ou 'f' caso não.
   w(comprimento), h(altura), x1(coordenada x), y1(coordenada y) definem um retângulo.
   x2(coordenada x), y2(coordenada y) definem um ponto.
 */
char pontoInternoR(double w, double h, double x1, double y1, double x2, double y2);

/**
   Verifica e retorna um caracter 't' se um ponto é interno a  um círculo ou 'f' caso não.
   r(raio), x1(coordenada x), y1(coordenada y) definem um círculo.
   x2(coordenada x), y2(coordenada y) definem um ponto.
 */
char pontoInternoC(double r, double x1, double y1, double x2, double y2);


#endif
