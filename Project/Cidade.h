#ifndef CIDADE_H
#define CIDADE_H

#include "Quadra.h"
#include "Hidrante.h"
#include "Semafaro.h"
#include "Torre.h"
#include "QuadTree.h"
#include "HashTable.h"

#include "Pessoa.h"
#include "EstabelecimentoComercial.h"
#include "Dicionario.h"
#include "Morador.h"

typedef void* ElementoUrbano;
typedef void* Cidade;


/**
   Autor: Matheus Augusto Marques
   TAD: Cidade.
   Definição:
   Uma cidade é definida por um nome , um conjunto de elementos urbanos, quadras, pessoas, moradores e estabelecimentos comerciais. Um elemento urbano pode ser um hidrante, uma torre-base ou um semafáro.
 */


/*
   Cria uma cidade vazia com o nome na string name.
 */
Cidade criaCidade(char *name);

/*
   Retorna a quantidade de elementos dentro de uma cidade.
 */
long int quantityElementsICity(Cidade cidade);


/*
   Retorna o nome da cidade.
 */
char *getNome(Cidade cidade);


/*
   Troca o nome de uma cidade por outro nome contido na string nome.
 */
void setNome(Cidade cidade, char *nome);


/*
   Insere uma quadra em uma cidade.
   Retorna a quantidade de comparações para inserir uma quadra em cidade.
 */
long int insertQuadra(Cidade cidade, ElementoUrbano item);


/*
   Remove uma quadra presente em uma cidade com um número de identificação (cep).
 */
long int removeQuadra(Cidade cidade, char *cep);


/*
   Insere um semafaro em uma cidade.
   Retorna a quantidade de comparações para inserir um semáfaro em cidade.
 */
long int insertSemafaro(Cidade cidade, ElementoUrbano item);

/*
   Remove um semafaro presente em uma cidade com um número de identificação (id).
 */
long int removeSemafaro(Cidade cidade, char *id);


/*
   Insere uma torre celular em uma cidade.
   Retorna a quantidade de comparações para inserir uma torre em cidade.
 */
long int insertTorre(Cidade cidade, ElementoUrbano item);

/*
   Remove uma torre-base presente em uma cidade com um número de identificação (id).
 */
long int removeTorre(Cidade cidade, char *id);


/*
   Insere um hidrante em uma cidade.
   Retorna a quantidade de comparações para inserir uma hidrante em cidade.
 */
long int insertHidrante(Cidade cidade, ElementoUrbano item);


/*
   Remove um hidrante de uma cidade com um número de identificação (id).
 */
long int removeHidrante(Cidade cidade, char *id);


/*
  O procedimento insere uma pessoa em cidade.
 */
void insertPessoas(Cidade cidade, Pessoa pessoa);


/*
  O procedimento insere um morador em cidade.
 */
void insertMorador(Cidade cidade, Morador morador);

/*
  O procedimento insere um estabelecimento comercial em cidade.
 */
void insertEstabC(Cidade cidade, EstabC estabC);


/*
  O procedimento remove uma pessoa de cidade especificada por cpf.
 */
void removePessoasCidade(Cidade cidade, char *cpf);


/*
  O procedimento remove um morador de cidade especificada por cpf.
 */
void removeMoradorCidade(Cidade cidade, char *cpf);


/*
  O procedimento remove um estabelecimento comercial de cidade especificada por cnpj.
 */
void removeEstabCidade(Cidade cidade, char *cnpj);


/*
  A função retorna um dicionário com informações sobre as pessoas, moradores e estabelecimentos comerciais inseridos na cidade.
 */
Dicionario getDicionario(Cidade cidade);


/*
   Escreve em um arquivo file (Arquivo svg) todas as quadras presentes na cidade. As quadras são representadas por retângulos.
 */
void showQuadras(Cidade cidade, FILE *file);


/*
   Escreve em um arquivo file (Arquivo svg) todos os hidrantes presentes na cidade. Os hidrantes são representados por círculos.
 */
void showHidrantes(Cidade cidade, FILE *file);


/*
   Escreve em um arquivo file (Arquivo svg) todos os semafaros presentes na cidade. Os semáfaros são representados por círculos.
 */
void showSemafaros(Cidade cidade, FILE *file);


/*
   Escreve em um arquivo file (Arquivo svg) todas as torres-base presentes na cidade. As torres são representados por círculos.
 */
void showTorres(Cidade cidade, FILE *file);


/*
   O procedimento calcula onde um morador mora em uma dada quadra no número num e com um face face. As coordenadas são retornadas em x e y.
 */
void calculaCoordenadaM(Quadra quadra, int num, char face, double *x,
                        double *y);

/*
   O procedimento desenha em um arquivo de extensão '.svg' um círculo representando o morador.
 */
void showMoradores(Cidade cidade, FILE *file);

/*
   O procedimento desenha em um arquivo de extensão '.svg' um quadrado representando o Estabelecimento Comercial.
 */
void showEstabelecimentos(Cidade cidade, FILE *file);

/*
   Retorna um lista contendo todas as quadras de uma cidade.
   Retorna null caso não exista quadras na cidade.
 */
QuadTree getListaQ(Cidade cidade);


/*
   Retorna um lista contendo todos os semafaros de uma cidade.
   Retorna uma lista vazia caso não exista semafaros na cidade.
 */
QuadTree getListaS(Cidade cidade);


/*
   Retorna um lista contendo todas as torres celulares de uma cidade.
   Retorna uma lista vazia caso não exista torres celulares na cidade.
 */
QuadTree getListaT(Cidade cidade);


/*
   Retorna um lista contendo todos os hidrantes de uma cidade.
   Retorna uma lista vazia caso não exista hidrantes na cidade.
 */
QuadTree getListaH(Cidade cidade);


/*
   Retorna um lista contendo todos os Moradores de uma cidade.
   Retorna uma lista vazia caso não exista moradores na cidade.
 */
List getListaMoradores(Cidade cidade);

/*
   Retorna um lista contendo todos as pessoas de uma cidade.
   Retorna uma lista vazia caso não exista pessoas na cidade.
 */
List getListaPessoas(Cidade cidade);

/*
   Retorna um lista contendo todos os Estabelecimentos Comerciais de uma cidade.
   Retorna uma lista vazia caso não exista Estabelecimentos Comerciais na cidade.
 */
List getListaEstabelecimentos(Cidade cidade);

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
   Apaga uma cidade e todos os seus componentes.
 */
void eraseCidade(Cidade cidade);

#endif
