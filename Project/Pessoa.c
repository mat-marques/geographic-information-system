
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Pessoa.h"
#include "StringO.h"

typedef struct novaPessoa {
  char *cpf, *nome, *sobrenome, *sexo, *nasc;
  Endereco endereco;
  Celular celular;

} NovaPessoa;

Pessoa criaPessoa(char *cpf, char *nome, char *sobrenome, char *sexo,
                  char *nasc) {
  NovaPessoa *novaPessoa = NULL;
  novaPessoa = (NovaPessoa *)malloc(sizeof(NovaPessoa));

  novaPessoa->cpf = criarString(cpf);
  novaPessoa->nome = criarString(nome);
  novaPessoa->nasc = criarString(nasc);
  novaPessoa->sexo = criarString(sexo);
  novaPessoa->sobrenome = criarString(sobrenome);
  novaPessoa->endereco = NULL;
  novaPessoa->celular = NULL;
  return novaPessoa;
}

char *getCpf(Pessoa pessoa) {
  NovaPessoa *novaPessoa = (NovaPessoa *)pessoa;
  return novaPessoa->cpf;
}

void setCpf(Pessoa pessoa, char *cpf) {
  NovaPessoa *novaPessoa = (NovaPessoa *)pessoa;
  if (novaPessoa->cpf != NULL) {
    free(novaPessoa->cpf);
    novaPessoa->cpf = NULL;
  }
  novaPessoa->cpf = criarString(cpf);
}

char *getNomeP(Pessoa pessoa) {
  NovaPessoa *novaPessoa = (NovaPessoa *)pessoa;
  return novaPessoa->nome;
}

void setNomeP(Pessoa pessoa, char *nome) {
  NovaPessoa *novaPessoa = (NovaPessoa *)pessoa;
  if (novaPessoa->nome != NULL) {
    free(novaPessoa->nome);
    novaPessoa->nome = NULL;
  }
  novaPessoa->nome = criarString(nome);
}

char *getSobrenome(Pessoa pessoa) {
  NovaPessoa *novaPessoa = (NovaPessoa *)pessoa;
  return novaPessoa->sobrenome;
}

void setSobrenome(Pessoa pessoa, char *sobrenome) {
  NovaPessoa *novaPessoa = (NovaPessoa *)pessoa;
  if (novaPessoa->sobrenome != NULL) {
    free(novaPessoa->sobrenome);
    novaPessoa->sobrenome = NULL;
  }
  novaPessoa->sobrenome = criarString(sobrenome);
}

char *getSexo(Pessoa pessoa) {
  NovaPessoa *novaPessoa = (NovaPessoa *)pessoa;
  return novaPessoa->sexo;
}

void setSexo(Pessoa pessoa, char *sexo) {
  NovaPessoa *novaPessoa = (NovaPessoa *)pessoa;
  if (novaPessoa->sexo != NULL) {
    free(novaPessoa->sexo);
    novaPessoa->sexo = NULL;
  }
  novaPessoa->sexo = criarString(sexo);
}

char *getNasc(Pessoa pessoa) {
  NovaPessoa *novaPessoa = (NovaPessoa *)pessoa;
  return novaPessoa->nasc;
}

void setNasc(Pessoa pessoa, char *nasc) {
  NovaPessoa *novaPessoa = (NovaPessoa *)pessoa;
  if (novaPessoa->nasc != NULL) {
    free(novaPessoa->nasc);
    novaPessoa->nasc = NULL;
  }
  novaPessoa->nasc = criarString(nasc);
}

Endereco getEnderecoP(Pessoa pessoa) {
  NovaPessoa *novaPessoa = (NovaPessoa *)pessoa;
  return novaPessoa->endereco;
}

void setEnderecoP(Pessoa pessoa, Endereco endereco) {
  NovaPessoa *novaPessoa = (NovaPessoa *)pessoa;
  if (endereco != NULL) {
    novaPessoa->endereco = endereco;
  } else {
    novaPessoa->endereco = NULL;
  }
}

Celular getCelular(Pessoa pessoa) {
  NovaPessoa *novaPessoa = (NovaPessoa *)pessoa;
  return novaPessoa->celular;
}

void setCelular(Pessoa pessoa, Celular celular) {
  NovaPessoa *novaPessoa = (NovaPessoa *)pessoa;
  if (novaPessoa->celular != NULL) {
    removeCelular(novaPessoa->celular);
    novaPessoa->celular = NULL;
  }
  if (celular != NULL) {
    novaPessoa->celular = celular;
  } else {
    novaPessoa->celular = NULL;
  }
}

int comparePessoas(Pessoa pessoa1, void *cpf) {
  NovaPessoa *novaPessoa1 = (NovaPessoa *)pessoa1;
  char *myCpf = (char *)cpf;
  if (strcmp(novaPessoa1->cpf, myCpf) == 0) {
    return 1;
  }
  return 0;
}

void removePessoa(Pessoa pessoa) {
  NovaPessoa *novaPessoa = (NovaPessoa *)pessoa;
  free(novaPessoa->cpf);
  free(novaPessoa->nasc);
  free(novaPessoa->nome);
  free(novaPessoa->sexo);
  free(novaPessoa->sobrenome);
  if (novaPessoa->celular != NULL) {
    removeCelular(novaPessoa->celular);
  }
  free(pessoa);
}
