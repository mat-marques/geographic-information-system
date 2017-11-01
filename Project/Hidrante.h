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
Hidrante criaHidrante(double x, double y, char *id, char *corP, char *corB);

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


/**
Retorna a cor de preenchimento de Hidrante element.
Retorna uma string.
*/
char *getCorpH(Hidrante element);


/**
Retorna a cor de borda de Hidrante element.
Retorna uma string.
*/
char *getCorbH(Hidrante element);


/**
Retorna a vazão de Hidrante element.
Retorna uma número real.
*/
double getVazao(Hidrante element);


/*
Modifica a vazão de Hidrante element pelo valor em vazão.
*/
void setVazao(Hidrante element, double vazao);


/*
Remove um hidrante da memória.
*/
void removeH(Hidrante element);


/*
A função verifica se um hidrante é igual ao tipo de dado item.
item é um tipo de dado genérico.
*/
int compareH(Hidrante element, void *item);

#endif
