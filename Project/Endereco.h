#ifndef Endereco_H
#define Endereco_H

typedef void* Endereco;

Endereco criaEndereco(char *cep, char face, int num, char *comp);


char *getCep(Endereco endereco);


void setCep(Endereco endereco, char *cep);


char getFace(Endereco endereco);


void setFace(Endereco endereco, char face);


int getNum(Endereco endereco);


void setNum(Endereco endereco, double num);


char *getComp(Endereco endereco);


void setComp(Endereco endereco, char* comp);



int compareEnderecos(Endereco endereco, void *cep);


void removeEndereco(Endereco endereco);

#endif
