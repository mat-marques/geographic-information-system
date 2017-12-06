#ifndef Endereco_H
#define Endereco_H

typedef void* Endereco;

Endereco criaEndereco(char *cep, char face, double num, int comp);


char *getCep(Endereco endereco);


void setCep(Endereco endereco, char *cep);


char *getCpfE(Endereco endereco);


void setCpfE(Endereco endereco, char *cpf);


char getFace(Endereco endereco);


void setFace(Endereco endereco, char face);


double getNum(Endereco endereco);


void setNum(Endereco endereco, double num);


int getComp(Endereco endereco);


void setComp(Endereco endereco, int comp);


int compareEnderecos(Endereco endereco, void *cep);


void removeEndereco(Endereco endereco);

#endif
