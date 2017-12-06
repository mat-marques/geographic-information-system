#ifndef CLIENTE_H
#define CLIENTE_H

typedef void* Cliente;


Cliente criaCliente(char *cpf, char *numCelular);


char *getCpfC(Cliente cliente);


void setCpfC(Cliente cliente, char *cpf);


char *getNumCelularC(Cliente cliente);


void getNumCelularC(Cliente cliente, char *numCelular);


char *getNomeC(Cliente cliente);


void setNomeC(Cliente cliente, char *nome);


int compareClientes(Cliente cliente1, Cliente cliente2);


void removeClienteC(Cliente cliente);

#endif
