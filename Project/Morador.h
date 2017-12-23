#ifndef MORADOR_H
#define MORADOR_H

#include "Endereco.h"
typedef void* Morador;


Morador criaMorador(char *cpf, Endereco endereco);


char *getCpfM(Morador morador);


void setCpfM(Morador morador, char *cpf);


Endereco getEndereco(Morador morador);


void setEndereco(Morador morador, Endereco endereco);



int compareMorador(Morador morador, void *cpf);


void removeMorador(Morador morador);

#endif
