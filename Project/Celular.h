#ifndef CELULAR_H
#define CELULAR_H


typedef void* Celular;


Celular criaCelular(char *num);


char *getNumCelular(Celular celular);


void setNumCelular(Celular celular, char *num);


char *getNomeOperadora(Celular celular);


void setNomeOperadora(Celular celular, char *nomeOperadora);


void *getDonoCelular(Celular celular);


void *setDonoCelular(Celular celular, void *pessoa);


char *getIdTorreConexao(Celular celular);


void setIdTorreConexao(Celular celular, char *id);


int compareCelulares(Celular celular, void* num);


void removeCelular(Celular celular);

#endif
