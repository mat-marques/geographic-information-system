#ifndef EXIBICAO_H
#define EXIBICAO_H

#include "Circulo.h"
#include "Retangulo.h"
#include "Torre.h"
#include "Semafaro.h"
#include "Hidrante.h"
#include "Quadra.h"
#include "Cidade.h"
#include "Arquivo.h"

FILE *globalFile;
char *globalCor1;
char *globalCor2;

void showR(Retangulo retangulo);

void showC(Circulo circulo);

void showQ(Quadra quadra);

void showH(Hidrante hidrante);

void showS(Semafaro semafaro);

void showT(Torre torre);

#endif
