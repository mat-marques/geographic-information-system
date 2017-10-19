#include <stdio.h>
#include <stdlib.h>

#include "Exibicao.h"
#include "Svg.h"
#include "Cor.h"
#include "Canvas.h"


void showR(Retangulo retangulo){
  double w, h, x, y;
  char *cor;
  x = getRx(retangulo);
  y = getRy(retangulo);
  w = getRw(retangulo);
  h = getRh(retangulo);
  cor = getRcor(retangulo);
  tagRetangulo(globalFile, w, h, x, y, cor);
}

void showR2(Retangulo retangulo){
  double w, h, x, y;
  char *cor;
  x = getRx(retangulo);
  y = getRy(retangulo);
  w = getRw(retangulo);
  h = getRh(retangulo);
  cor = getRcor(retangulo);
  tagRetanguloSobreposicao(globalFile, x, y, w, h);
}

void showC(Circulo circulo){
  double x, y, r;
  char *cor;
  x = getCx(circulo);
  y = getCy(circulo);
  cor = getCcor(circulo);
  tagCirculo(globalFile, r, x, y, cor);

}

void showQ(Quadra quadra){
  double x, y, w, h;
  x = getXQ(quadra);
  y = getYQ(quadra);
  w = getLargQ(quadra);
  h = getAltQ(quadra);
  tagRetangulo2(globalFile, w, h, x, y, globalCor1, globalCor2);
}

void showH(Hidrante hidrante){
  double x, y;
  x = getXH(hidrante);
  y = getYH(hidrante);
  tagCirculo2(globalFile, 5, x, y, globalCor1, globalCor2);
}

void showS(Semafaro semafaro){
  double x, y;
  x = getXS(semafaro);
  y = getYS(semafaro);
  tagCirculo2(globalFile, 5, x, y, globalCor1, globalCor2);
}

void showT(Torre torre){
  double x, y;
  x = getXT(torre);
  y = getYT(torre);
    tagCirculo2(globalFile, 5, x, y, globalCor1, globalCor2);
}
