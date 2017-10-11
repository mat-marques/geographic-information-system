#ifndef HIDRANTE_H
#define HIDRANTE_H

typedef void* Hidrante;

/***
Autor: Matheus Augusto Marques.
Tad: Hidrante
Definição:
Modela um hidrante. Um hidrante é um elemento composto por um par ordenado que
configura a posição do hidrante em um plano cartesiano(O plano pode ser uma cidade).
Além disso, o hidrante é constituido por um número de identificação.
*/

/**
Cria um hidrante e o retorna.
Um hidrante é composto pelas configurações x e y que representam um par ordenado
associado a posição do hidrante em uma cidade. O inteiro id representa o número
de identificação do hidrante em uma cidade.
*/
Hidrante criaHidrante(double x, double y, char *id);

/**
Retorna a coordenada x do par ordenado que posiciona o hidrante no plano.
Essa coordenada será do hidrante passado como parâmetro.
*/
double getXH(Hidrante element);

/**
Retorna a coordenada y do par ordenado que posiciona o hidrante no plano.
Essa coordenada será do hidrante passado como parâmetro.
*/
double getYH(Hidrante element);

/**
Retorna o id do hidrante no plano.
Esse id será do hidrante passado como parâmetro.
*/
char *getIdH(Hidrante element);

double getVazao(Hidrante element);

void setVazao(Hidrante element, double vazao);

void removeH(Hidrante element);

int compareH(Hidrante element, void *item);
#endif
