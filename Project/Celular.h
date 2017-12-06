#ifndef CELULAR_H
#define CELULAR_H

#include "Pessoa.h"

typedef void* Celular;


Celular criaCelular(char *num);


char *getNumCelular(Celular celular);


void setNumCelular(Celular celular, char *num);


char *getNomeOperadora(Celular celular);


void setNomeOperadora(Celular celular, char *nomeOperadora);


Pessoa getDonoCelular(Celular celular);


Pessoa setDonoCelular(Celular celular, Pessoa pessoa);


char *getIdTorreConexao(Celular celular);


void setIdTorreConexao(Celular celular, char *id);


int compareCelulares(Celular celular, void* num);


void removeCelular(Celular celular);

#endif
