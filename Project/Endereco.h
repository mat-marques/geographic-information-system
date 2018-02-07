#ifndef Endereco_H
#define Endereco_H

typedef void *Endereco;

/*
   Autor: Matheus Augusto Marques.
   Tad Endereço:
   Um endereço é definido por um cep, uma face, um número e um complemento.
   O dado cep define em qual quadra a pessoa mora.
   O dado face define uma das quatro faces da quadra onde uma pessoa mora.
   O dado número define o número da residencia de uma pessoa.
   O complemento define informações adicionais sobre a moradia de uma pessoa.
*/

/*
 Cria e retorna um endereço com as configurações contidas em cep, face, num e
 comp.
*/
Endereco criaEndereco(char *cep, char face, int num, char *comp);

/*
 A função retorna o cep do endereço.
*/
char *getCep(Endereco endereco);

/*
 O procedimento define no endereçço um novo cep.
*/
void setCep(Endereco endereco, char *cep);

/*
 A função retorna a face do endereço.
*/
char getFace(Endereco endereco);

/*
 O procedimento define no endereçço uma nova face.
*/
void setFace(Endereco endereco, char face);

/*
  A função retorna o Numero do endereço.
*/
int getNum(Endereco endereco);


double getXEndereco(Endereco endereco);


void setXEndereco(Endereco endereco, double x);


double getYEndereco(Endereco endereco);


void setYEndereco(Endereco endereco, double y);


/*
 O procedimento define no endereçço um novo número.
*/
void setNum(Endereco endereco, double num);

/*
 A função retorna o complemento do endereço.
*/
char *getComp(Endereco endereco);

/*
 O procedimento define no endereçço um novo complemento.
*/
void setComp(Endereco endereco, char *comp);

/*
  A função verifica se dois endereços tem as mesmas configurações. Ou seja, se
  são iguais.
*/
int compareEnderecos(Endereco endereco1, Endereco endereco2);

/*
  O procedimento apaga todos os dados relacionados a o endereço.
*/
void removeEndereco(Endereco endereco);

#endif
