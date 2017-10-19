#ifndef CIDADE_H
#define CIDADE_H

#include "Quadra.h"
#include "Hidrante.h"
#include "Semafaro.h"
#include "Torre.h"
#include "QuadTree.h"
typedef void* ElementoUrbano;
typedef void* Cidade;

FILE *newArqCity;

/**
Autor: Matheus Augusto Marques
TAD: Cidade.
Definição:
Uma cidade é definida por um nome , um conjunto de elementos urbanos e quadras. Um elemento urbano pode ser um hidrante, uma torre celular ou um semafáro.
*/


/*
Cria uma cidade vazia com o nome na string name.
*/
Cidade criaCidade(char *name);


/*
Insere uma quadra em uma cidade.
*/
void insertQuadra(Cidade cidade, ElementoUrbano item);


/*
Remove uma quadra presente em uma cidade em uma posição indicada por p.
*/
void removeQuadra(Cidade cidade, char *cep);


/*
Insere um semafaro em uma cidade.
*/
void insertSemafaro(Cidade cidade, ElementoUrbano item);


/*
Remove um semafaro presente em uma cidade em uma posição indicada por p.
*/
void removeSemafaro(Cidade cidade, char *id);


/*
Insere uma torre celular em uma cidade.
*/
void insertTorre(Cidade cidade, ElementoUrbano item);


/*
Remove uma torre celular presente em uma cidade em uma posição indicada por p.
*/
void removeTorre(Cidade cidade, char *id);


/*
Insere um hidrante em uma cidade.
*/
void insertHidrante(Cidade cidade, ElementoUrbano item);


/*
Remove um hidrante de uma cidade em uma posição indicada por p.
*/
void removeHidrante(Cidade cidade, char *id);


/*
Retorna o nome da cidade.
*/
char *getNome(Cidade cidade);


/*
Troca o nome de uma cidade por outro nome contido na string nome.
*/
void setNome(Cidade cidade, char *nome);


/*
Retorna um lista contendo todas as quadras de uma cidade.
Retorna null caso não exista quadras na cidade.
*/
QuadTree getListaQ(Cidade cidade);


/*
Retorna um lista contendo todos os semafaros de uma cidade.
Retorna null caso não exista semafaros na cidade.
*/
QuadTree getListaS(Cidade cidade);


/*
Retorna um lista contendo todas as torres celulares de uma cidade.
Retorna null caso não exista torres celulares na cidade.
*/
QuadTree getListaT(Cidade cidade);


/*
Retorna um lista contendo todos os hidrantes de uma cidade.
Retorna null caso não exista hidrantes na cidade.
*/
QuadTree getListaH(Cidade cidade);


/*
 Escreve as propriedades de uma quadra em um arquivo no formato svg.
O arquivo é expecificado pelo usúario através da variável newArqCity.
O arquivo svg deve existir e estar aberto.
*/
void showQ(Quadra quadra);


/*
 Escreve as propriedades de um hidrante em um arquivo no formato svg.
O arquivo é expecificado pelo usúario através da variável newArqCity.
O arquivo svg deve existir e estar aberto.
*/
void showH(Hidrante hidrante);


/*
 Escreve as propriedades de um semafaro em um arquivo no formato svg.
O arquivo é expecificado pelo usúario através da variável newArqCity.
O arquivo svg deve existir e estar aberto.
*/
void showS(Semafaro semafaro);


/*A funcão escreve as propriedades de uma torre em um arquivo no formato svg.
O arquivo é expecificado pelo usúario através da variável newArqCanvas.
O arquivo svg deve existir e estar aberto.*/
void showT(Torre torre);

/*
Retorna uma quadra presente em uma cidade com o título de identificação definido pela string cep.
Retorna null caso a quadra não exista.
*/
Quadra getQuadra(Cidade cidade, char *cep);

/*
Retorna uma torre celular (Elemento urbano) com a identificação contida na string id.
Retorna null caso a torre celular não exista na cidade.
*/
ElementoUrbano getTorre(Cidade cidade, char *id);

/*
Retorna um semafáro (Elemento urbano) com a identificação contida na string id.
Retorna null caso o semafáro não exista na cidade.
*/
ElementoUrbano getSemafaro(Cidade cidade, char *id);

/*
Retorna um hidrante (Elemento urbano) com a identificação contida na string id.
Retorna null caso o hidrante não exista na cidade.
*/
ElementoUrbano getHidrante(Cidade cidade, char *id);

/*
Apaga todas as quadras presentes na cidade.
*/
void eraseListaQ(Cidade cidade);

/*
Apaga todos os semafaros presentes na cidade.
*/
void eraseListaS(Cidade cidade);

/*
Apaga todas as torres de celular presentes na cidade.
*/
void eraseListaT(Cidade cidade);

/*
Apaga todos os hidrantes presentes em uma cidade.
*/
void eraseListaH(Cidade cidade);

/*
Apaga uma cidade e todos os seus componentes.
*/
void eraseCidade(Cidade cidade);

#endif
