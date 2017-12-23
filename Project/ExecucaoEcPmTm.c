#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ExecucaoEcPmTm.h"
#include "StringO.h"
#include "Cidade.h"
#include "Pessoa.h"
#include "EstabelecimentoComercial.h"
#include "Endereco.h"
#include "HashTable.h"
#include "Morador.h"
#include "Dicionario.h"
#include "Celular.h"

HashTable hash;
Dicionario dicionario;

void executarEcT(Canvas canvas, FILE *arqEntradaEc){
  char *codt, *descricao, *codt2;
  char secao3[] = "codtXestabC";
  char secao9[] = "descricaoXestabC";
  int i, l;
  Cidade cidade;
  EstabC estabC;
  List list = NULL;
  l = qtdCaracteres(arqEntradaEc);
  codt = alocarString(l);
  fscanf(arqEntradaEc, "%s ", codt);

  l = qtdCaracteres(arqEntradaEc);
  descricao = alocarString(l);
  fscanf(arqEntradaEc, "%s\n", descricao);

  cidade = getCidade(canvas);

  dicionario = getDicionario(cidade);
  hash = getSecaoDicionario(dicionario, secao3);

  list = getHtList(hash, codt);

  /* Insere na secao9 - descricaoXestabC */
  hash = getSecaoDicionario(dicionario, secao9);

  if(list != NULL){
    l = lengthL(list);
    for(i=1; i<=l; i++){
      estabC = getItemL(list, i);
      codt2 = getCodt(estabC);
      if(strcmp(codt, codt2) == 0){
        insertHT(hash, descricao, estabC);
        setDescription(estabC, descricao);
      }
      estabC = NULL;
    }
  }

  desalocar(codt);
  desalocar(descricao);
}


void executarEcE(Canvas canvas, FILE *arqEntradaEc){
  char *codt, *cep, face, *cnpj, *nome;

  char secao3[] = "codtXestabC";
  char secao8[] = "cnpjXestabC";
  char secao10[] = "cepXestabC";

  int l, num;
  Cidade cidade;
  EstabC estabC;
  l = qtdCaracteres(arqEntradaEc);
  codt = alocarString(l);
  fscanf(arqEntradaEc, "%s ", codt);

  l = qtdCaracteres(arqEntradaEc);
  cep = alocarString(l);
  fscanf(arqEntradaEc, "%s ", cep);

  fscanf(arqEntradaEc, "%c ", &face);

  fscanf(arqEntradaEc, "%d ", &num);

  l = qtdCaracteres(arqEntradaEc);
  cnpj = alocarString(l);
  fscanf(arqEntradaEc, "%s ", cnpj);

  l = qtdCaracteres(arqEntradaEc);
  nome = alocarString(l);
  fscanf(arqEntradaEc, "%s\n", nome);

  estabC = criaEstabC(codt, cep, face, num, cnpj, nome);

  cidade = getCidade(canvas);

  dicionario = getDicionario(cidade);
  /* Insere na secao3 - codtXestabC */
  hash = getSecaoDicionario(dicionario, secao3);
  insertHT(hash, codt, estabC);

  /* Insere na secao8 - cnpjXestabC */
  hash = getSecaoDicionario(dicionario, secao8);
  insertHT(hash, cnpj, estabC);

  /* Insere na secao10 - cepXestabC */
  hash = getSecaoDicionario(dicionario, secao10);
  insertHT(hash, cep, estabC);

  desalocar(codt);
  desalocar(cep);
  desalocar(cnpj);
  desalocar(nome);

}


void executarPmP(Canvas canvas, FILE *arqEntradaPm){
  char *cpf, *nome, *sobrenome, *sexo, *nasc;
  char secao4[] = "cpfXpessoa";

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

  /* Insere na secao4 - cpfXpessoa */
  insertHT(hash, cpf, pessoa);

  desalocar(cpf);
  desalocar(nome);
  desalocar(sobrenome);
  desalocar(sexo);
  desalocar(nasc);
}


void executarPmM(Canvas canvas, FILE *arqEntradaPm){
  char *cpf, *cep, face, *comp;
  char secao1[] = "cpfXcep";
  char secao4[] = "cpfXpessoa";
  char secao6[] = "cepXmoradores";
  char secao7[] = "cepXpessoas";
  char secao11[] = "cpfXmorador";

  int l;
  int num;
  Cidade cidade;
  Pessoa pessoa;
  Endereco endereco;
  Morador morador;
  l = qtdCaracteres(arqEntradaPm);
  cpf = alocarString(l);
  fscanf(arqEntradaPm, "%s ", cpf);

  l = qtdCaracteres(arqEntradaPm);
  cep = alocarString(l);
  fscanf(arqEntradaPm, "%s ", cep);

  fscanf(arqEntradaPm, "%c ", &face);

  fscanf(arqEntradaPm, "%d ", &num);

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
    morador = criaMorador(cpf, endereco);

    /* Insere na secao1 - cpfXcep */
    hash = getSecaoDicionario(dicionario, secao1);
    insertHT(hash, cpf, cep);

    /* Insere na secao6 - cepXmoradores */
    hash = getSecaoDicionario(dicionario, secao6);
    insertHT(hash, cep, morador);


    /* Insere na secao7 - cepXpessoas */
    hash = getSecaoDicionario(dicionario, secao7);
    insertHT(hash, cep, pessoa);

    /* Insere na secao11 - cpfXmorador */
    hash = getSecaoDicionario(dicionario, secao11);
    insertHT(hash, cpf, morador);

  } else {
    printf("Insercao de morador na cidade imposibilitada.\n");
  }

  desalocar(cpf);
  desalocar(comp);

}


void executarTmSu(Canvas canvas, FILE *arqEntradaTm){
  char secao2[] = "numcelXpessoa";
  char secao4[] = "cpfXpessoa";
  char secao12[] = "operadoraXcelular";
  char secao15[] = "numcelXcelular";
  char *cpf, *numCel;
  int l;
  char nomeO[] = "SercomtUEL";
  Pessoa pessoa;
  Cidade cidade;
  Celular celular;
  l = qtdCaracteres(arqEntradaTm);
  cpf = alocarString(l);
  fscanf(arqEntradaTm, "%s ", cpf);

  l = qtdCaracteres(arqEntradaTm);
  numCel = alocarString(l);
  fscanf(arqEntradaTm, "%s ", numCel);

  cidade = getCidade(canvas);

  dicionario = getDicionario(cidade);
  hash = getSecaoDicionario(dicionario, secao4);
  pessoa = itemIsInsideHT(hash, cpf, cpf, comparePessoas);

  if(pessoa != NULL){
    celular = criaCelular(numCel);
    setNomeOperadora(celular, nomeO);
    setDonoCelular(celular, pessoa);
    setCelular(pessoa, celular);

    /* Insere na secao2 - numcelXpessoa */
    hash = getSecaoDicionario(dicionario, secao2);
    insertHT(hash, numCel, pessoa);

    /* Insere na secao12 - operadoraXcelular */
    hash = getSecaoDicionario(dicionario, secao12);
    insertHT(hash, nomeO, celular);


    /* Insere na secao15 - numcelXcelular */
    hash = getSecaoDicionario(dicionario, secao15);
    insertHT(hash, numCel, celular);

  }

  desalocar(cpf);
  desalocar(numCel);
}


void executarTmUm(Canvas canvas, FILE *arqEntradaTm){
  char secao2[] = "numcelXpessoa";
  char secao4[] = "cpfXpessoa";
  char secao12[] = "operadoraXcelular";
  char secao15[] = "numcelXcelular";

  char *cpf, *numCel;
  int l;
  char nomeO[] = "UELMobile";
  Pessoa pessoa;
  Cidade cidade;
  Celular celular;
  l = qtdCaracteres(arqEntradaTm);
  cpf = alocarString(l);
  fscanf(arqEntradaTm, "%s ", cpf);

  l = qtdCaracteres(arqEntradaTm);
  numCel = alocarString(l);
  fscanf(arqEntradaTm, "%s ", numCel);

  cidade = getCidade(canvas);

  dicionario = getDicionario(cidade);
  hash = getSecaoDicionario(dicionario, secao4);
  pessoa = itemIsInsideHT(hash, cpf, cpf, comparePessoas);

  if(pessoa != NULL){
    celular = criaCelular(numCel);
    setNomeOperadora(celular, nomeO);
    setDonoCelular(celular, pessoa);
    setCelular(pessoa, celular);

    /* Insere na secao2 - numcelXpessoa */
    hash = getSecaoDicionario(dicionario, secao2);
    insertHT(hash, numCel, pessoa);

    /* Insere na secao12 - operadoraXcelular */
    hash = getSecaoDicionario(dicionario, secao12);
    insertHT(hash, nomeO, celular);


    /* Insere na secao15 - numcelXcelular */
    hash = getSecaoDicionario(dicionario, secao15);
    insertHT(hash, numCel, celular);

  }

  desalocar(cpf);
  desalocar(numCel);
}
