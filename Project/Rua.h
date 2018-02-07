#ifndef RUA_H
#define RUA_H

typedef void* Street;

/*
  Autor: Matheus Augusto Marques
  Tad: Rua
  Definição: Uma rua é um elemento que divide a cidade em regiões onde pode ocorrer a movimentação de elementos moveis. Uma rua é definida por um nome
  cepRight (Quadra a direita da rua), cepLeft(Quadra a esquerda da rua), cmp(Comprimento) e vm(Velocidade).
*/


/*
  Cria uma areta definindo o seu direcionamento e conexão com os vertíces. Também define as opções opcionais configuradas.
*/
Street createStreet(char *name, char *cepRight, char *cepLeft, double cmp, double vm);

/*
  A função retorna o nome da rua.
*/
char *getNameStreet(Street street);


/*
 O procedimento define um novo nome para a rua.
*/
void setNameStreet(Street street, char *name);


/*
  A função retorna o cep da quadra a direita da rua.
*/
char *getCepRight(Street street);


/*
  O procedimento define uma nova quadra que está a direita da rua.
*/
void setCepRight(Street street, char *cepRight);


/*
  A função retorna o id da quadra que esta a esquerda da rua.
*/
char *getCepLeft(Street street);


/*
  O procedimento define uma nova quadra que está a esquerda da rua.
*/
void setCepLeft(Street street, char *cepLeft);


/*
  A função retorna o comprimento da rua.
*/
double getCmp(Street Street);


/*
  O procedimento define um novo comprimento para a rua.
*/
void setCmp(Street street, double cmp);


/*
  A função retorna a velocidade permitida na rua.
*/
double getVm(Street street);


/*
  O procedimento define a velocidade permitida na rua.
*/
void setVm(Street street, double vm);


/*
  Compara uma rua pelo nome.
  Caso possuam mesmo nome será retornado 1 e 0 caso contrário.
*/
int compareStreet(Street street, void *name);


/*
  A apaga uma rua.
*/
void removeStreet(Street street);

#endif
