#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ExecucaoEcPmTm.h"
#include "StringO.h"
#include "Cidade.h"
#include "Pessoa.h"
#include "EstabelecimentoComercial.h"
#include "Operadora.h"
#include "Endereco.h"
#include "HashTable.h"
#include "Morador.h"
#include "Dicionario.h"
#include "Celular.h"

char secao1[] = "cpfXcep";
char secao2[] = "numcelXpessoa";
char secao3[] = "codtXestabC";
char secao4[] = "cpfXpessoa";
char secao5[] = "cepXquadra";
char secao6[] = "cepXmoradores";
HashTable hash;
Dicionario dicionario;

void executarEcT(Canvas canvas, FILE *arqEntradaEc){
  char *codt, *descricao;
  int l;
  Cidade cidade;
  EstabC estabC;
  l = qtdCaracteres(arqEntradaEc);
  codt = alocarString(l);
  fscanf(arqEntradaEc, "%s ", codt);

  l = qtdCaracteres(arqEntradaEc);
  descricao = alocarString(l);
  fscanf(arqEntradaEc, "%s\n", descricao);

  cidade = getCidade(canvas);

  dicionario = getDicionario(cidade);
  hash = getSecaoDicionario(dicionario, secao3);
  estabC = itemIsInsideHT(hash, codt, codt, compareEstabC);

  if(estabC != NULL){
    setDescription(estabC, descricao);
  }

  desalocar(codt);
  desalocar(descricao);
}


void executarEcE(Canvas canvas, FILE *arqEntradaEc){
  char *codt, *cep, *face, *num, *cnpj, *nome;
  int l;
  Cidade cidade;
  EstabC estabC;
  l = qtdCaracteres(arqEntradaEc);
  codt = alocarString(l);
  fscanf(arqEntradaEc, "%s ", codt);

  l = qtdCaracteres(arqEntradaEc);
  cep = alocarString(l);
  fscanf(arqEntradaEc, "%s ", cep);

  l = qtdCaracteres(arqEntradaEc);
  face = alocarString(l);
  fscanf(arqEntradaEc, "%s ", face);

  l = qtdCaracteres(arqEntradaEc);
  num = alocarString(l);
  fscanf(arqEntradaEc, "%s ", num);

  l = qtdCaracteres(arqEntradaEc);
  cnpj = alocarString(l);
  fscanf(arqEntradaEc, "%s ", cnpj);

  l = qtdCaracteres(arqEntradaEc);
  nome = alocarString(l);
  fscanf(arqEntradaEc, "%s\n", nome);

  estabC = criaEstabC(codt, cep, face, num, cnpj, nome);

  cidade = getCidade(canvas);

  dicionario = getDicionario(cidade);
  hash = getSecaoDicionario(dicionario, secao3);
  estabC = itemIsInsideHT(hash, codt, codt, compareEstabC);

  desalocar(codt);
  desalocar(cep);
  desalocar(face);
  desalocar(cnpj);
  desalocar(nome);

}


void executarPmP(Canvas canvas, FILE *arqEntradaPm){
  char *cpf, *nome, *sobrenome, *sexo, *nasc;
  int l;
  Cidade cidade;
  Pessoa pessoa;
  l = qtdCaracteres(arqEntradaPm);
  cpf = alocarString(l);
  fscanf(arqEntradaPm, "%s ", cpf);

  l = qtdCaracteres(arqEntradaPm);
  nome = alocarString(l);
  fscanf(arqEntradaPm, "%s ", nome);

  l = qtdCaracteres(arqEntradaPm);
  sobrenome = alocarString(l);
  fscanf(arqEntradaPm, "%s ", sobrenome);

  l = qtdCaracteres(arqEntradaPm);
  sexo = alocarString(l);
  fscanf(arqEntradaPm, "%s ", sexo);

  l = qtdCaracteres(arqEntradaPm);
  nasc = alocarString(l);
  fscanf(arqEntradaPm, "%s\n", nasc);

  pessoa = criaPessoa(cpf, nome, sobrenome, sexo, nasc);

  cidade = getCidade(canvas);

  dicionario = getDicionario(cidade);
  hash = getSecaoDicionario(dicionario, secao4);
  insertHT(hash, cpf, pessoa);

  desalocar(cpf);
  desalocar(nome);
  desalocar(sobrenome);
  desalocar(sexo);
  desalocar(nasc);
}


void executarPmM(Canvas canvas, FILE *arqEntradaPm){
  char *cpf, *cep, *face, *num, *comp;
  int l;
  Cidade cidade;
  Pessoa pessoa;
  Endereco endereco, endereco2;
  Morador morador;
  l = qtdCaracteres(arqEntradaPm);
  cpf = alocarString(l);
  fscanf(arqEntradaPm, "%s ", cpf);

  l = qtdCaracteres(arqEntradaPm);
  cep = alocarString(l);
  fscanf(arqEntradaPm, "%s ", cep);

  l = qtdCaracteres(arqEntradaPm);
  face = alocarString(l);
  fscanf(arqEntradaPm, "%s ", face);

  l = qtdCaracteres(arqEntradaPm);
  num = alocarString(l);
  fscanf(arqEntradaPm, "%s ", num);

  l = qtdCaracteres(arqEntradaPm);
  comp = alocarString(l);
  fscanf(arqEntradaPm, "%s\n", comp);

  cidade = getCidade(canvas);

  dicionario = getDicionario(cidade);
  hash = getSecaoDicionario(dicionario, secao4);
  pessoa = itemIsInsideHT(hash, cpf, cpf, comparePessoas);
  if(pessoa != NULL){
    endereco = criaEndereco(cep, face, num, comp);
    setEnderecoP(pessoa, endereco);
  }
  hash = NULL;
  hash = getSecaoDicionario(dicionario, secao6);
  endereco2 = criaEndereco(cep, face, num, comp);
  morador = criaMorador(cpf, endereco2);
  insertHT(hash, cep, morador);

  desalocar(cep);
  desalocar(face);
  desalocar(cpf);
  desalocar(comp);

}


void executarTmSu(Canvas canvas, FILE *arqEntradaTm){
  char *cpf, *numCel;
  int l;
  char nome[] = "SercomtUEL";
  Pessoa pessoa;
  Operadora operadora;
  Cidade cidade;
  l = qtdCaracteres(arqEntradaTm);
  cpf = alocarString(l);
  fscanf(arqEntradaTm, "%s ", cpf);

  l = qtdCaracteres(arqEntradaTm);
  numCel = alocarString(l);
  fscanf(arqEntradaTm, "%s ", numCel);

  cidade = getCidade(canvas);



  if(pessoa != NULL){
    setNumCelular(pessoa, numCel);
    operadora = getOperadoraC(cidade, nome);
    insereCliente(operadora, pessoa);
  }

  desalocar(cpf);
  desalocar(numCel);
}


void executarTmUm(Canvas canvas, FILE *arqEntradaTm){
  char *cpf, *numCel;
  int l;
  char nome[] = "UELMobile";
  Pessoa pessoa;
  Operadora operadora;
  Cidade cidade;
  l = qtdCaracteres(arqEntradaTm);
  cpf = alocarString(l);
  fscanf(arqEntradaTm, "%s ", cpf);

  l = qtdCaracteres(arqEntradaTm);
  numCel = alocarString(l);
  fscanf(arqEntradaTm, "%s ", numCel);

  cidade = getCidade(canvas);



  if(pessoa != NULL){
    setNumCelular(pessoa, numCel);
    operadora = getOperadoraC(cidade, nome);
    insereCliente(operadora, pessoa);
  }

  desalocar(cpf);
  desalocar(numCel);
}
