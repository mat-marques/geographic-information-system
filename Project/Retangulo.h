#ifndef RETANGULO_H
#define RETANGULO_H

typedef void* Retangulo;
/**
Autor: Matheus Augusto Marques.
TAD: Retângulo.
Definição:
Modela a forma geométrica de um retãngulo. Portanto, um retângulo é definido
por coordenadas x e y, que representam a posição do vertice inferior esquerdo do retângulo, um comprimento w, uma altura h e uma cor nos padrões do svg.
*/

/**
Cria um retângulo com caracteriscas dos parametros fornecidos.
x e y são coordenadas do vertice inferior esquerdo.
w e h são medidas de comprimento e altura respectivamente.
cor é uma cor para preencher o retângulo.
*/
Retangulo createRectangle(int i, double w, double h, double x, double y, char cor[30]);

/**
Retorna um inteiro que representa o número de identificação de Retangulo element.
*/
int getRi(Retangulo element);

/**
Retorna um número real que representa o comprimento de Retangulo element.
*/
double getRw(Retangulo element);

/**
Retorna um número real que representa a altura de um retângulo.
*/
double getRh(Retangulo element);

/**
Retorna um número real que representa a coordenada x do retângulo.
*/
double getRx(Retangulo element);

/**
Retorna um número real que representa a coordenada y de Retangulo element.
*/
double getRy(Retangulo element);

/*
Retorna uma string que representa a cor de preenchimento de Retangulo element.
*/
char *getRcor(Retangulo element);

/*
Remove Retangulo element da memória.
*/
void removeR(Retangulo element);

/*
A função verifica se um retângulo é igual ao tipo de dado item.
item é um tipo de dado genérico.
*/
int compareR(Retangulo element, void* item);

#endif
