#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ExecucaoQry2.h"
#include "OperacoesF.h"

#include "Endereco.h"
#include "StringO.h"

char cor[] = "black";

char secao1[] = "cpfXcep";
char secao2[] = "numcelXpessoa";
char secao3[] = "codtXestabC";
char secao4[] = "cpfXpessoa";
char secao5[] = "cepXquadra";
char secao6[] = "cepXmoradores";
char secao7[] = "cepXpessoas";
char secao8[] = "cnpjXestabC";
char secao9[] = "descricaoXestabC";
char secao10[] = "cepXestabC";
char secao11[] = "cpfXmorador";
char secao12[] = "operadoraXcelular";
char secao13[] = "torreXcelular";
char secao14[] = "numcelXtorre";
char secao15[] = "numcelXcelular";
char secao16[] = "operadoraXtorre";

HashTable hash;
Dicionario dicionario;

struct dados {
  char *nome, *cel;
};

Torre getTorreMaisProxima(Canvas canvas, char *operadora, double x, double y,
                          double *dist) {
  Torre torre = NULL, torre2 = NULL;
  List list = NULL;
  int i, j;
  char boolean = 'f';
  double menorDistancia = 0, distancia = 0;
  list = getElementsListInsideR(canvas, 4, 0, 0, getWidth(canvas),
                                getHeight(canvas));

  if (list != NULL) {
    j = lengthL(list);
    if (operadora != NULL) {
      torre = NULL;
      for (i = 1; i <= j; i++) {
        torre = getItemL(list, i);
        distancia = distanciaEntrePontos(x, y, getXT(torre), getYT(torre));
        if (getOperadora(torre) != NULL) {
          if ((boolean == 'f') &&
              (strcmp(operadora, getOperadora(torre)) == 0)) {
            menorDistancia = distancia;
            torre2 = torre;
            boolean = 't';
          } else {
            if ((distancia < menorDistancia) &&
                (strcmp(operadora, getOperadora(torre)) == 0)) {
              menorDistancia = distancia;
              torre2 = torre;
            }
          }
        }
      }

    } else {

      torre = NULL;
      for (i = 1; i <= j; i++) {
        torre = getItemL(list, i);
        distancia = distanciaEntrePontos(x, y, getXT(torre), getYT(torre));
        if (boolean == 'f') {
          menorDistancia = distancia;
          torre2 = torre;
          boolean = 't';
        } else {
          if (menorDistancia > distancia) {
            menorDistancia = distancia;
            torre2 = torre;
          }
        }
      }
    }
    if (dist != NULL) {
      *dist = menorDistancia;
    }
  }

  eraseListL(list, NULL);
  eraseBase(list);
  return torre2;
}

EstabC getCodt_x_EstabC(Canvas canvas, char *codt, char *cnpj) {
  EstabC estabC = NULL;

  dicionario = getDicionario(getCidade(canvas));
  hash = getSecaoDicionario(dicionario, secao3);

  estabC = itemIsInsideHT(hash, codt, cnpj, compareEstabC);

  return estabC;
}

EstabC getCnpj_x_EstabC(Canvas canvas, char *cnpj) {
  EstabC estabC = NULL;

  dicionario = getDicionario(getCidade(canvas));
  hash = getSecaoDicionario(dicionario, secao8);

  estabC = itemIsInsideHT(hash, cnpj, cnpj, compareEstabC);

  return estabC;
}

EstabC getDescricao_x_EstabC(Canvas canvas, char *descricao, char *cnpj) {
  EstabC estabC = NULL;

  dicionario = getDicionario(getCidade(canvas));
  hash = getSecaoDicionario(dicionario, secao9);

  estabC = itemIsInsideHT(hash, descricao, cnpj, compareEstabC);

  return estabC;
}

Pessoa getCpf_x_Pessoa(Canvas canvas, char *cpf) {
  Pessoa pessoa = NULL;
  dicionario = getDicionario(getCidade(canvas));

  hash = getSecaoDicionario(dicionario, secao4);

  pessoa = itemIsInsideHT(hash, cpf, cpf, comparePessoas);

  return pessoa;
}

char *getCpf_x_Cep(Canvas canvas, char *cpf) {
  char *cep = NULL, *cep2 = NULL;
  Pessoa pessoa = NULL;
  Endereco endereco = NULL;

  pessoa = getCpf_x_Pessoa(canvas, cpf);

  if (pessoa != NULL) {
    endereco = getEnderecoP(pessoa);
    if (endereco != NULL) {
      cep2 = getCep(endereco);
      if (cep2 != NULL) {
        dicionario = getDicionario(getCidade(canvas));
        hash = getSecaoDicionario(dicionario, secao1);
        cep = (char *)itemIsInsideHT(hash, cpf, cep2, compareQ);
      }
    }
  }

  return cep;
}

Morador getCpf_x_Morador(Canvas canvas, char *cpf) {
  Morador morador = NULL;
  dicionario = getDicionario(getCidade(canvas));
  hash = getSecaoDicionario(dicionario, secao11);

  morador = itemIsInsideHT(hash, cpf, cpf, compareMorador);

  return morador;
}

Pessoa getNumCel_x_Pessoa(Canvas canvas, char *numCel, char *cpf) {
  Morador morador = NULL;
  dicionario = getDicionario(getCidade(canvas));
  hash = getSecaoDicionario(dicionario, secao2);

  morador = itemIsInsideHT(hash, numCel, cpf, comparePessoas);

  return morador;
}

Quadra getCep_x_Quadra(Canvas canvas, char *cep) {
  Quadra quadra = NULL;
  dicionario = getDicionario(getCidade(canvas));
  hash = getSecaoDicionario(dicionario, secao5);

  quadra = itemIsInsideHT(hash, cep, cep, compareQ);

  return quadra;
}

Celular getNumcel_x_Celular(Canvas canvas, char *numCel) {
  List list = NULL;
  Celular celular = NULL;
  char *var;
  int i, j;
  dicionario = getDicionario(getCidade(canvas));
  hash = getSecaoDicionario(dicionario, secao15);

  list = getHtList(hash, numCel);

  if (list != NULL) {
    /* Verifica se o celular existe */
    j = lengthL(list);
    for (i = 1; i <= j; i++) {
      celular = getItemL(list, i);
      var = getNumCelular(celular);
      if (strcmp(numCel, var) == 0) {
        break;
      }
      celular = NULL;
    }
  }
  return celular;
}

Celular getOperadora_x_Celular(Canvas canvas, char *op, char *num) {
  List list = NULL;
  Celular celular = NULL;
  char *var;
  int i, j;
  dicionario = getDicionario(getCidade(canvas));
  hash = getSecaoDicionario(dicionario, secao12);

  list = getHtList(hash, op);

  if (list != NULL) {
    /* Verifica se o celular existe */
    j = lengthL(list);
    for (i = 1; i <= j; i++) {
      celular = getItemL(list, i);
      var = getNumCelular(celular);
      if (strcmp(num, var) == 0) {
        break;
      }
      celular = NULL;
    }
  }
  return celular;
}

Celular getTorre_x_Celular(Canvas canvas, char *idTorre, char *num) {
  List list = NULL;
  Celular celular = NULL;
  char *var;
  int i, j;
  dicionario = getDicionario(getCidade(canvas));
  hash = getSecaoDicionario(dicionario, secao13);

  list = getHtList(hash, idTorre);

  if (list != NULL) {
    /* Verifica se o celular existe */
    j = lengthL(list);
    for (i = 1; i <= j; i++) {
      celular = getItemL(list, i);
      var = getNumCelular(celular);
      if (strcmp(num, var) == 0) {
        break;
      }
      celular = NULL;
    }
  }
  return celular;
}

Torre getNumCel_x_Torre(Canvas canvas, char *num) {
  List list = NULL;
  Torre torre = NULL;
  Celular celular = NULL;
  char *var;
  int i, j;
  dicionario = getDicionario(getCidade(canvas));
  hash = getSecaoDicionario(dicionario, secao14);

  list = getHtList(hash, num);
  if (list != NULL) {
    /* Verifica se o celular existe */
    j = lengthL(list);
    for (i = 1; i <= j; i++) {
      torre = getItemL(list, i);
      celular = getTorre_x_Celular(canvas, getIdT(torre), num);
      var = getNumCelular(celular);
      if (strcmp(num, var) == 0) {
        break;
      }
      celular = NULL;
    }
  }
  return torre;
}

void desconectarTorre_x_Celular(Canvas canvas, char *idTorre) {
  List list = NULL;
  Celular celular = NULL;
  char *var;
  int i, j, *vetor, p = 0;
  dicionario = getDicionario(getCidade(canvas));
  hash = getSecaoDicionario(dicionario, secao13);

  list = getHtList(hash, idTorre);

  if (list != NULL) {
    /* Verifica se o celular existe */
    j = lengthL(list);
    vetor = (int *)malloc(j * sizeof(int));

    for (i = 1; i <= j; i++) {
      celular = getItemL(list, i);
      if (celular != NULL) {
        var = NULL;
        var = getIdTorreConexao(celular);
        if (var != NULL) {
          if (strcmp(idTorre, var) == 0) {
            setIdTorreConexao(celular, NULL);
            *(vetor + p) = i;
            p++;
          }
        }
      }
      celular = NULL;
    }
    for (i = 1; i <= p; i++) {
      removeMiddleL(list, *(vetor + i - 1), NULL);
    }
    free(vetor);
  }
}

void insertHtTorre_x_Celular(Canvas canvas, Torre torre, Celular celular) {
  /* Insere na secao13 - Torre_x_Celular */
  dicionario = getDicionario(getCidade(canvas));
  hash = getSecaoDicionario(dicionario, secao13);
  insertHT(hash, getIdT(torre), celular);
}

void insertHtNumCel_x_Torre(Canvas canvas, Torre torre, Celular celular) {
  /* Insere na secao14 - NumCel_x_Torre */
  dicionario = getDicionario(getCidade(canvas));
  hash = getSecaoDicionario(dicionario, secao14);
  insertHT(hash, getNumCelular(celular), torre);
}

void executarQryMv(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas) {
  int i;
  char *opdest, *num;
  char op1[] = "um", op2[] = "su";
  Celular celular = NULL, celular2 = NULL;
  Pessoa pessoa = NULL;
  Torre torre = NULL;
  void *var;

  i = qtdCaracteres(arqEntradaQry);
  opdest = alocarString(i);

  fscanf(arqEntradaQry, "%s ", opdest);

  i = qtdCaracteres(arqEntradaQry);
  num = alocarString(i);

  fscanf(arqEntradaQry, "%s\n", num);

  /* Verifica se o celular existe */
  celular = getNumcel_x_Celular(canvas, num);

  fprintf(*arqSaidaT, "mv? %s %s\n", opdest, num);

  if (celular != NULL) {
    if (strcmp(opdest, op1) == 0) { /* Muda a operadora para UELMobile */
      /* Verifica na operadora de origem SercomtUEL */
      celular = NULL;
      celular = getOperadora_x_Celular(canvas, op2, num);
      /* Verifica se celular esta na operadora de origem SercomtUEL */
      if (celular == NULL) {
        fprintf(*arqSaidaT,
                "Numero de telefone nao existe na operadora de origem.\n");
      } else {
        /* Verifica na operadora de destino UELMobile */
        celular2 = NULL;
        celular2 = getOperadora_x_Celular(canvas, op1, num);
        /* Verifica se celular esta na operadora de destino UELMobile */

        if (celular2 != NULL) {
          fprintf(*arqSaidaT,
                  "Numero de celular ja existe na operadora de destino.\n");
        } else {
          /* Conecta o celular na torre mais próxima */
          pessoa = getDonoCelular(celular);

          if ((getIdTorreConexao(celular) != NULL) && (pessoa != NULL)) {
            var = getEnderecoP(pessoa);
            if (var != NULL) {
                torre = getTorreMaisProxima(canvas, op1, getXEndereco(var),
                                            getYEndereco(var), NULL);
                setIdTorreConexao(celular, getIdT(torre));
            }
          }

          setNomeOperadora(celular, opdest);
          if (pessoa != NULL) {
            fprintf(*arqSaidaT, "Celular %s, pertencente a %s, "
                                "migrou de %s para %s.\n",
                    num, getNomeP(pessoa), op2, op1);
          }
        }
      }
    } else {
      if (strcmp(opdest, op2) == 0) { /* Muda a operadora para SercomtUEL */
        /* Verifica na operadora de origem UELMobile */
        celular = getOperadora_x_Celular(canvas, op1, num);
        /* Verifica se celular esta na operadora de origem UELMobile */

        if (celular == NULL) {
          fprintf(*arqSaidaT,
                  "Numero de telefone nao existe na operadora de origem.\n");
        } else {
          /* Verifica na operadora de destino SercomtUEL  */
          celular2 = NULL;
          celular2 = getOperadora_x_Celular(canvas, op2, num);

          if (celular2 != NULL) {
            fprintf(*arqSaidaT,
                    "Numero de celular ja existe na operadora de destino.\n");
          } else {
            /* Conecta o celular na torre mais próxima */
            pessoa = getDonoCelular(celular);

            if ((getIdTorreConexao(celular) != NULL) && (pessoa != NULL)) {
              var = getEnderecoP(pessoa);
              if (var != NULL) {
                  torre = getTorreMaisProxima(canvas, op1, getXEndereco(var),
                                              getYEndereco(var), NULL);
                  setIdTorreConexao(celular, getIdT(torre));
              }
            }

            setNomeOperadora(celular, opdest);
            if (pessoa != NULL) {
              fprintf(*arqSaidaT, "Celular %s, pertencente a %s, "
                                  "migrou de %s para %s.\n",
                      num, getNomeP(pessoa), op1, op2);
            }
          }
        }
      }
    }
  } else{
    fprintf(*arqSaidaT, "Celular %s nao existe.\n", num);
  }
  free(opdest);
  free(num);
}

void executarQryM(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas) {
  char *cep;
  int sizeString, i, l;
  Quadra quadra = NULL;
  HashTable hash = NULL;
  List list = NULL;
  Endereco endereco = NULL;
  Pessoa pessoa = NULL;
  Morador morador = NULL;
  Cidade cidade = NULL;
  Celular celular;
  char *cpf = NULL;

  sizeString = qtdCaracteres(arqEntradaQry);
  cep = alocarString(sizeString);

  fscanf(arqEntradaQry, "%s\n", cep);

  quadra = getCep_x_Quadra(canvas, cep);

  cidade = getCidade(canvas);
  dicionario = getDicionario(cidade);

  fprintf(*arqSaidaT, "m? %s\n", cep);

  if (quadra == NULL) {
    printf("Cep de quadra fornecida nao existe na cidade.\n");
  } else {
    /* Pega uma lista de moradores de uma quadra. */
    hash = getSecaoDicionario(dicionario, secao6);
    list = getHtList(hash, cep);
    l = lengthL(list);
    hash = getSecaoDicionario(dicionario, secao4);

    for (i = 1; i <= l; i++) {
      morador = getItemL(list, i);
      if (morador != NULL) {
        cpf = getCpfM(morador);
        pessoa = itemIsInsideHT(hash, cpf, cpf, comparePessoas);
        if (pessoa != NULL) {
          endereco = getEndereco(morador);
          fprintf(*arqSaidaT, "Nome: %s, Endereco: %s %c %d %s\n",
                  getNomeP(pessoa), getCep(endereco), getFace(endereco),
                  getNum(endereco), getComp(endereco));
          celular = getCelular(pessoa);
          if (celular != NULL) {
            fprintf(*arqSaidaT, "Numero Celular: %s, Operadora: %s\n",
                    getNumCelular(celular), getNomeOperadora(celular));
          }
        } else {
          printf("Morador nao possui informacoes registradas.\n");
        }
      }
      morador = NULL;
      pessoa = NULL;
    }
  }
  free(cep);
}

void executarQryMr(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas) {
  List list = NULL;
  Pessoa pessoa = NULL;
  List moradores = NULL;
  Endereco endereco = NULL;
  Cidade cidade = NULL;
  Quadra quadra = NULL;
  Morador morador = NULL;
  Celular celular = NULL;
  int i, l, j, k, p = 0;
  double x, y, w, h;
  char *cep, *cpf;

  fscanf(arqEntradaQry, "%lf %lf %lf %lf", &x, &y, &w, &h);

  list = getElementsListInsideR(canvas, 1, x, y, w, h);

  cidade = getCidade(canvas);

  fprintf(*arqSaidaT, "mr? %f %f %f %f\n", x, y, w, h);

  if (list != NULL) {
    l = lengthL(list);
    dicionario = getDicionario(cidade);
    hash = getSecaoDicionario(dicionario, secao6);

    for (i = 1; i <= l; i++) { /*Percorre lista das quadras*/
      quadra = getItemL(list, i);
      cep = getCepQ(quadra);
      moradores = getHtList(hash, cep);

      p = 0;
      fprintf(*arqSaidaT, "Moradores da quadra %s.\n", cep);
      if (moradores != NULL) {
        k = lengthL(moradores);

        for (j = 1; j <= k; j++) { /*Percorre lista de moradores*/
          morador = NULL;
          morador = getItemL(moradores, j);
          if (morador != NULL) {
            endereco = getEndereco(morador);

            if (strcmp(getCep(endereco), cep) == 0) {
              cpf = getCpfM(morador);
              pessoa = itemIsInsideHT(getSecaoDicionario(dicionario, secao4),
                                      cpf, cpf, comparePessoas);
              if (pessoa != NULL) {
                p++;
                fprintf(*arqSaidaT, "Nome: %s, Endereco: %s %c %d %s\n",
                        getNomeP(pessoa), getCep(endereco), getFace(endereco),
                        getNum(endereco), getComp(endereco));
                celular = getCelular(pessoa);
                if (celular != NULL) {
                  fprintf(*arqSaidaT, "Numero celular: %s, Operadora: %s\n",
                          getNumCelular(celular), getNomeOperadora(celular));
                }
              } else {
                printf("Morador de cep %s nao possui informacoes pessoais.\n", cpf);
              }
            }
          }
        }

      }

      if(p == 0){
          fprintf(*arqSaidaT, "Nao existem moradores.\n");
      }
    }
    eraseListL(list, NULL);
    eraseBase(list);
  } else {
    fprintf(*arqSaidaT, "Nao existem quadras na regiao fornecida.\n");
  }
}

void executarQryDm(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas) {
  Pessoa pessoa = NULL;
  Endereco endereco = NULL;
  Celular celular = NULL;
  int i;
  char *cpf;
  double x = 0, y = 0;

  i = qtdCaracteres(arqEntradaQry);
  cpf = alocarString(i);

  fscanf(arqEntradaQry, "%s\n", cpf);

  pessoa = getCpf_x_Pessoa(canvas, cpf);

  fprintf(*arqSaidaT,"dm? %s\n", cpf);

  if (pessoa != NULL) {
    fprintf(
        *arqSaidaT,
        "Nome: %s, Sobrenome: %s, Sexo: %s, Data Nascimento: %s\n",
        getNomeP(pessoa), getSobrenome(pessoa), getSexo(pessoa),
        getNasc(pessoa));
    celular = getCelular(pessoa);
    if (celular != NULL) {
      fprintf(*arqSaidaT, "Numero do celular: %s, Operadora: %s\n",
              getNumCelular(celular), getNomeOperadora(celular));
    }
    endereco = getEnderecoP(pessoa);
    if (endereco != NULL) {
        x = getXEndereco(endereco);
        y = getYEndereco(endereco);
        fprintf(*arqSaidaT, "Coordenada x: %f e Coordenada y: %f\n", x, y);
        /* Insere um ponto no canvas */
        insertPointCanvas(canvas, createPoint(automaticId++, x, y));
        insertTextCanvas(canvas, createText(automaticId++, cpf, x, y));
    }

  } else {
    fprintf(*arqSaidaT, "Pessoa com cpf fornecido não existe no banco de dados.\n");
  }

  free(cpf);
}

void executarQryDe(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas) {
  Endereco endereco = NULL;
  EstabC estabC = NULL;
  int i;
  char *cnpj = NULL;
  double x, y;
  i = qtdCaracteres(arqEntradaQry);
  cnpj = alocarString(i);

  fscanf(arqEntradaQry, "%s\n", cnpj);

  estabC = getCnpj_x_EstabC(canvas, cnpj);

  fprintf(*arqSaidaT, "de? %s\n", cnpj);

  if (estabC != NULL) {

    endereco = getEnderecoEstabC(estabC);
    x = getXEndereco(endereco);
    y = getYEndereco(endereco);

    fprintf(*arqSaidaT, "Codt: %s, Descricao: %s, Cep: %s, "
                          "Face: %c, Num: %d, Cnpj: %s, Nome: %s, Coordenada: "
                          "%f %f\n",
              getCodt(estabC), getDescription(estabC), getCep(endereco),
              getFace(endereco), getNum(endereco), getCnpj(estabC),
              getNomeEstabC(estabC), x, y);

      /* Insere um círculo na lista de figuras geométricas */
      insertPointCanvas(canvas, createPoint(automaticId++, x, y));

  } else {
    fprintf(*arqSaidaT, "Estabelecimento comercial fornecido não existe no banco de dados.\n");
  }

  free(cnpj);
}

void executarQryCon(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas) {
  char *numC, face, *cep;
  int num, i;
  double x, y, menorDistancia;
  Quadra quadra = NULL;
  Celular celular = NULL;
  Torre torre = NULL;
  Pessoa pessoa = NULL;

  i = qtdCaracteres(arqEntradaQry);
  numC = alocarString(i);
  fscanf(arqEntradaQry, "%s ", numC);

  i = qtdCaracteres(arqEntradaQry);
  cep = alocarString(i);
  fscanf(arqEntradaQry, "%s %c %d", cep, &face, &num);

  quadra = getCep_x_Quadra(canvas, cep);
  fprintf(*arqSaidaT, "con %s %s %c %d\n", numC, cep, face, num);
  if (quadra != NULL) {

    celular = getNumcel_x_Celular(canvas, numC);

    if (celular != NULL) {

      calculaCoordenadaM(quadra, num, face, &x, &y);

      torre = getTorreMaisProxima(canvas, getNomeOperadora(celular), x, y,
                                  &menorDistancia);

      if (torre != NULL) {
        setIdTorreConexao(celular, getIdT(torre));

        insertHtTorre_x_Celular(canvas, torre, celular);
        insertHtNumCel_x_Torre(canvas, torre, celular);

        pessoa = getDonoCelular(celular);
        fprintf(*arqSaidaT,
                "Cpf: %s,Nome Do Usuario: %s,Nome Operadora: %s, "
                "Id torre: %s, Coordenada x: %f y: %f e Distancia: %f\n",
                getCpf(pessoa), getNomeP(pessoa), getNomeOperadora(celular),
                getIdT(torre), getXT(torre), getYT(torre), menorDistancia);

        /* Insere uma linha no canvas */
        insertLineCanvas(canvas,
                         createLine(automaticId++, x, y, getXT(torre), getYT(torre)));

        setCepCelular(celular, cep);
        setFaceCelular(celular, face);
        setNumQCelular(celular, num);
        setXCelular(celular, x);
        setYCelular(celular, y);
      }
    }
  }
  free(numC);
  free(cep);
}

void executarQryMse(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas) {
  Endereco endereco = NULL;
  Cidade cidade = NULL;
  Quadra quadra = NULL;
  EstabC estabC = NULL;
  List list = NULL, estabCs = NULL, pessoas = NULL;
  Pessoa pessoa;
  HashTable hash2 = NULL;
  int i, j, n, k, p, q, a = 0;
  char *cep, sx[2], *tp, *codt, *var, *sx1;
  double x, y, w, h;

  fscanf(arqEntradaQry, "%s ", sx);

  i = qtdCaracteres(arqEntradaQry);
  tp = alocarString(i);

  fscanf(arqEntradaQry, "%s %lf %lf %lf %lf\n", tp, &x, &y, &w, &h);

  cidade = getCidade(canvas);

  list = getElementsListInsideR(canvas, 1, x, y, w, h);

  fprintf(*arqSaidaT, "mse? %s %f %f %f %f\n", tp, x, y, w, h);

  if (list != NULL) {
    dicionario = getDicionario(cidade);
    hash = getSecaoDicionario(dicionario, secao10);
    hash2 = getSecaoDicionario(dicionario, secao7);
    k = lengthL(list);

    for (i = 1; i <= k; i++) { /* Percorre a lista de quadras */
      quadra = getItemL(list, i);

      if (quadra != NULL) {

        cep = getCepQ(quadra);
        fprintf(*arqSaidaT, "Pesquisando na quadra de cep %s.\n", cep);
        if (cep != NULL) {
          estabCs = getHtList(hash, cep);
        }
        a = 0;
        if (estabCs != NULL) {

          n = lengthL(estabCs);
          for (j = 1; j <= n; j++) { /* Percorre a lista de Estabelecimentos */
            estabC = getItemL(estabCs, j);

            if (estabC != NULL) {
              codt = getCodt(estabC);

              if (codt != NULL) {

                if (strcmp(codt, tp) == 0) {

                  pessoas = getHtList(hash2, cep);
                  q = lengthL(pessoas);

                  for (p = 1; p <= q; p++) { /* Percorre a lista de Pessoas*/
                    pessoa = getItemL(pessoas, p);
                    if (pessoa != NULL) {
                      endereco = getEnderecoP(pessoa);
                      var = getCep(endereco);
                      sx1 = getSexo(pessoa);
                      if ((strcmp(cep, var) == 0) && (strcmp(sx, sx1) == 0)) {
                        a++;
                        fprintf(*arqSaidaT,
                                "Nome: %s %s, Endereco: %s %c %d %s\n",
                                getNomeP(pessoa), getSobrenome(pessoa), cep,
                                getFace(endereco), getNum(endereco),
                                getComp(endereco));
                      }
                    }
                  }
                }
              }
              estabC = NULL;
            }
          }
        }

        if(a == 0){
            fprintf(*arqSaidaT, "Nenhuma elemento com as caracteristica fornecidas encontrado.\n");
        }
        quadra = NULL;
      }
    }
    eraseListL(list, NULL);
    eraseBase(list);
  } else {
    fprintf(*arqSaidaT, "Nenhuma quadra encontrada na regiao fornecida.\n");
  }
  free(tp);
}

void calcularCoordLosango(Canvas canvas, char face, double x, double y) {
  Polygon polygon = NULL;
  Line line1 = NULL, line2 = NULL;
  char colour[] = "white";
  polygon = createPolygon(automaticId++, 4);
  switch (face) {
  case 'S':
    insertPointsPolygon(polygon, x, y);
    insertPointsPolygon(polygon, x - 5, y + 5);
    insertPointsPolygon(polygon, x, y + 10);
    insertPointsPolygon(polygon, x + 5, y + 5);
    line1 = createLine(automaticId++, x, y + 2.5, x, y + 7.5);
    line2 = createLine(automaticId++, x - 2.5, y + 5, x + 2.5, y + 5);
    break;
  case 'L':
    insertPointsPolygon(polygon, x + 5, y - 5);
    insertPointsPolygon(polygon, x, y);
    insertPointsPolygon(polygon, x + 5, y + 5);
    insertPointsPolygon(polygon, x + 10, y);
    line1 = createLine(automaticId++, x + 2.5, y, x + 7.5, y);
    line2 = createLine(automaticId++, x + 5, y - 2.5, x + 5, y + 2.5);
    break;
  case 'N':
    insertPointsPolygon(polygon, x, y - 10);
    insertPointsPolygon(polygon, x - 5, y - 5);
    insertPointsPolygon(polygon, x, y);
    insertPointsPolygon(polygon, x + 5, y - 5);
    line1 = createLine(automaticId++, x, y - 2.5, x, y - 7.5);
    line2 = createLine(automaticId++, x - 2.5, y - 5, x + 2.5, y - 5);
    break;
  case 'O':
    insertPointsPolygon(polygon, x - 5, y - 5);
    insertPointsPolygon(polygon, x - 10, y);
    insertPointsPolygon(polygon, x - 5, y + 5);
    insertPointsPolygon(polygon, x, y);
    line1 = createLine(automaticId++, x - 5, y - 2.5, x - 5, y + 2.5);
    line2 = createLine(automaticId++, x - 2.5, y, x - 7.5, y);
    break;
  }
  insertPolygonCanvas(canvas, polygon);
  insertLineCanvas(canvas, line1);
  insertLineCanvas(canvas, line2);
  setColourLine(line1, colour);
  setColourLine(line2, colour);
}

void executarQryRip(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas) {
  Cidade cidade = NULL;
  Pessoa pessoa = NULL;
  Endereco endereco = NULL;
  Celular celular = NULL;
  Quadra quadra = NULL;
  int i;
  double x = 0, y = 0;
  char *cpf, *cep, *numC;

  /* secao2, secao4, secao6, secao7, secao11, secao12, secao13, secao15 */

  i = qtdCaracteres(arqEntradaQry);
  cpf = alocarString(i);

  fscanf(arqEntradaQry, "%s\n", cpf);

  cidade = getCidade(canvas);
  dicionario = getDicionario(cidade);


  /* Remove os dados da secao4 - cpfXpessoa */
  hash = getSecaoDicionario(dicionario, secao4);
  pessoa = itemIsInsideHT(hash, cpf, cpf, comparePessoas);
  fprintf(*arqSaidaT, "rip %s\n", cpf);
  if (pessoa != NULL) {
    fprintf(*arqSaidaT,
            "Faleceu %s, portador do cpf %s, do sexo %s, nascido em %s\n",
            getNomeP(pessoa), getCpf(pessoa), getSexo(pessoa), getNasc(pessoa));
    celular = getCelular(pessoa);
    endereco = getEnderecoP(pessoa);
    removeHT(hash, cpf, cpf, comparePessoas);
  } else {
    fprintf(*arqSaidaT, "Pessoa nao existe.\n");
  }

  if (celular != NULL) {
    fprintf(*arqSaidaT, "usuário da linha móvel %s da operadora %s\n",
            getNumCelular(celular), getNomeOperadora(celular));

    /* Remove os dados da secao2 - numcelXpessoa */
    hash = getSecaoDicionario(dicionario, secao2);
    numC = getNumCelular(celular);
    removeHT(hash, numC, cpf, compareMorador);

    /* Remove os dados da secao15 - numcelXcelular */
    hash = getSecaoDicionario(dicionario, secao15);
    removeHT(hash, numC, numC, compareCelulares);

    /* Remove os dados da secao12 - operadoraXcelular */
    hash = getSecaoDicionario(dicionario, secao12);
    removeHT(hash, getNomeOperadora(celular), numC, compareCelulares);

    /* Remove os dados da secao13 - torreXcelular */
    hash = getSecaoDicionario(dicionario, secao13);
    if (getIdTorreConexao(celular) != NULL) {
      removeHT(hash, getIdTorreConexao(celular), numC, compareCelulares);
    }
  }

  if (endereco != NULL) {
    fprintf(*arqSaidaT, "residia no endereço %s/%d/%c\n", getCep(endereco),
            getNum(endereco), getFace(endereco));
    cep = getCep(endereco);
    hash = getSecaoDicionario(dicionario, secao5);
    quadra = itemIsInsideHT(hash, cep, cep, compareQ);

    if (quadra != NULL) {
      /* Insere um losango no svg */
      x = getXEndereco(endereco);
      y = getYEndereco(endereco);
      calcularCoordLosango(canvas, getFace(endereco), x, y);
    }

    /* Remove os dados da secao6 - cepXmoradores */
    hash = getSecaoDicionario(dicionario, secao6);
    removeHT(hash, getCepQ(quadra), cpf, compareMorador);

    /* Remove os dados da secao7 - cepXpessoas */
    hash = getSecaoDicionario(dicionario, secao7);
    removeHT(hash, getCepQ(quadra), cpf, comparePessoas);

    /* Remove os dados da secao11 - cpfXmorador */
    hash = getSecaoDicionario(dicionario, secao11);
    removeHT(hash, cpf, cpf, compareMorador);

    removeMoradorCidade(cidade, cpf);
  }

  if(pessoa != NULL){
    removePessoasCidade(cidade, cpf);
  }
  free(cpf);
}

void executarQryLk(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas) {
  List list = NULL;
  Cidade cidade = NULL;
  int i, j, n = 0;
  void *element;
  double x = 0, y = 0;
  char *id, *var2;
  Torre torre;
  Pessoa pessoa;
  Endereco endereco;
  Quadra quadra;
  cidade = getCidade(canvas);

  dicionario = getDicionario(cidade);

  i = qtdCaracteres(arqEntradaQry);
  id = alocarString(i);

  fscanf(arqEntradaQry, "%s\n", id);

  hash = getSecaoDicionario(dicionario, secao13);

  list = getHtList(hash, id);

  fprintf(*arqSaidaT, "lk? %s\n", id);

  if (list != NULL) {
    j = lengthL(list);
    for (i = 1; i <= j; i++) {
      element = getItemL(list, i);
      var2 = getIdTorreConexao(element);
      if (strcmp(id, var2) == 0) {
        n++;
        fprintf(*arqSaidaT,
                "%d - Celular de numero: %s esta conectado a torre de id %s.\n",
                n, getNumCelular(element), id);
        torre = getTorre(cidade, id);
        pessoa = getDonoCelular(element);
        endereco = getEnderecoP(pessoa);
        quadra = getQuadra(cidade, getCep(endereco));
        if(quadra != NULL){
          calculaCoordenadaM(quadra, getNum(endereco), getFace(endereco), &x, &y);
          insertLineCanvas(canvas, createLine(automaticId++, getXT(torre), getYT(torre), x, y));
          insertPointCanvas(canvas, createPoint(automaticId++, x, y));
        }
        quadra = NULL;
        pessoa = NULL;
        torre = NULL;
      }
    }
    if(n == 0){
      fprintf(*arqSaidaT, "Nenhum celular esta conectado a torre de id %s.\n",
              id);
    }
  } else {
    fprintf(*arqSaidaT, "Nenhum celular esta conectado a torre de id %s.\n",
            id);
  }
  free(id);
}

void executarQryRb(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas) {
  Cidade cidade = NULL;
  int i;

  char *numCel;
  Torre torre = NULL;

  cidade = getCidade(canvas);

  dicionario = getDicionario(cidade);

  i = qtdCaracteres(arqEntradaQry);
  numCel = alocarString(i);

  fscanf(arqEntradaQry, "%s\n", numCel);

  torre = getNumCel_x_Torre(canvas, numCel);

  fprintf(*arqSaidaT, "rb? %s\n", numCel);

  if (torre != NULL) {
    fprintf(*arqSaidaT, "O celular de numero %s esta conectado a "
                        "radio-base de id %s\n",
            numCel, getIdT(torre));
  } else {
    fprintf(*arqSaidaT, "O celular de numero %s nao esta "
                        "conectado a nenhuma radio-base\n",
            numCel);
  }
  free(numCel);
}

int compareStrings2(const void *s1, const void *s2) {
  struct dados *string1 = (struct dados *)s1;
  struct dados *string2 = (struct dados *)s2;
  char *var1, *var2;
  var1 = string1->nome;
  var2 = string2->nome;
  if (var1[0] > var2[0]) {
    return 1;
  }
  if (var1[0] < var2[0]) {
    return -1;
  }
  return 0;
}

void executarQryCo(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas) {
  int i, j, n = -1, p = 0;
  char *op, letra;
  Cidade cidade;
  List list = NULL;
  void *element;
  struct dados *vector;

  i = qtdCaracteres(arqEntradaQry);
  op = alocarString(i);

  fscanf(arqEntradaQry, "%s", op);
  letra = fgetc(arqEntradaQry);
  letra = fgetc(arqEntradaQry);
  fprintf(*arqSaidaT, "co? %s", op);
  if ((feof(arqEntradaQry) == 0) && (letra != ' ') && (letra != '\n')) {
    fseek(arqEntradaQry, -1, SEEK_CUR);
    fscanf(arqEntradaQry, "%d\n", &n);
    fprintf(*arqSaidaT, " %d\n", n);
  } else {
    fprintf(*arqSaidaT, "\n");
  }

  cidade = getCidade(canvas);

  dicionario = getDicionario(cidade);

  hash = getSecaoDicionario(dicionario, secao12);

  list = getHtList(hash, op);

  if (list != NULL) {
    j = lengthL(list);
    if (j > 0) {
      vector = (struct dados *)malloc(j * sizeof(struct dados));
    }

    for (i = 1; i <= j; i++) { /* Percorre a lista de celulares */
      element = getItemL(list, i);
      if (element != NULL) {
        (vector + p)->nome = getNomeP(getDonoCelular(element));
        (vector + p)->cel = getNumCelular(element);
        p++;
      }
      element = NULL;
    }

    /* Ordena os dados */
    if (j > 0) {
      qsort(vector, j, sizeof(struct dados), compareStrings2);
    }

    /* Escreve no arquivo de saida */
    p = 0;
    if (n == -1) {
      n = j;
    }

    for (i = 1; i <= j; i++) {
      if ((i - 1) < n) {
        fprintf(*arqSaidaT, "%d - Nome: %s, Numero: %s\n", i,
                (vector + (i - 1))->nome, (vector + (i - 1))->cel);
      } else {
        break;
      }
    }
    free(vector);
    free(op);
  }
}

void executarQryLnr(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas) {
  List list = NULL, list2 = NULL;
  Cidade cidade = NULL;
  double x, y, w, h;
  int i, j, n, k, aux=0;
  void *element, *element2;
  char *id, *var, letra, *op;
  cidade = getCidade(canvas);

  dicionario = getDicionario(cidade);

  fscanf(arqEntradaQry, "%lf %lf %lf %lf", &x, &y, &w, &h);

  list = getElementsListInsideR(canvas, 4, x, y, w, h);

  if (list != NULL) {
    letra = fgetc(arqEntradaQry);
    letra = fgetc(arqEntradaQry);
    if ((feof(arqEntradaQry) == 0) && (letra != ' ') && (letra != '\n')) {
      fseek(arqEntradaQry, -1, SEEK_CUR);
      i = qtdCaracteres(arqEntradaQry);
      op = alocarString(i);
      fscanf(arqEntradaQry, "%s\n", op);
      fprintf(*arqSaidaT, "lnr? %f %f %f %f %s\n", x, y, w, h, op);

      j = lengthL(list);
      for (i = 1; i <= j; i++) {
        element = getItemL(list, i);
        id = getIdT(element);
        if (getOperadora(element) != NULL) {
          if (strcmp(getOperadora(element), op) == 0) {
            aux = 1;
            hash = getSecaoDicionario(dicionario, secao13);
            list2 = getHtList(hash, id);
            if (list2 != NULL) {
              n = lengthL(list2);
              for (k = 1; k <= n; k++) {
                element2 = getItemL(list2, k);
                var = getIdTorreConexao(element2);
                if (strcmp(id, var) == 0) {
                  fprintf(*arqSaidaT, "O celular de numero %s esta conectado a "
                                      "torre de id %s\n",
                          getNumCelular(element2), id);
                }
              }
            }
          }
        }
      }
      if(aux == 0){
        fprintf(*arqSaidaT,
                "Nao existem celulares conectados as torres da regiao fornecida.");
      }
      free(op);
    } else {
      fseek(arqEntradaQry, -1, SEEK_CUR);
      fgetc(arqEntradaQry);

      j = lengthL(list);
      /* Pega as torres */
      for (i = 1; i <= j; i++) {
        element = getItemL(list, i);
        id = getIdT(element);
        hash = getSecaoDicionario(dicionario, secao13);
        list2 = getHtList(hash, id);
        if (list2 != NULL) {
          n = lengthL(list2);
          /* Pega os celulares */
          for (k = 1; k <= n; k++) {
            element2 = getItemL(list2, k);
            var = getIdTorreConexao(element2);
            if ((strcmp(id, var) == 0) && (getOperadora(element) != NULL)) {
              aux = 1;
              fprintf(
                  *arqSaidaT,
                  "O celular de numero %s esta conectado a torre de id %s\n",
                  getNumCelular(element2), id);
            }
          }
        }
      }
    }
    if(aux == 0){
      fprintf(*arqSaidaT,
              "Nao existem celulares conectados as torres da regiao fornecida.");
    }
    eraseListL(list, NULL);
    eraseBase(list);
  } else {
    fprintf(*arqSaidaT,
            "lnr? %f %f %f %f\nNao existem torres na regiao fornecida.", x, y, w, h);
  }
}

void executarQryEcq(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas) {
  int i, n;
  char *cep, *cep2;
  Cidade cidade;
  List list = NULL;
  Endereco endereco = NULL;
  void *element;

  i = qtdCaracteres(arqEntradaQry);
  cep = alocarString(i);

  fscanf(arqEntradaQry, "%s\n", cep);

  cidade = getCidade(canvas);
  dicionario = getDicionario(cidade);
  hash = getSecaoDicionario(dicionario, secao10);

  list = getHtList(hash, cep);
  fprintf(*arqSaidaT, "ecq? %s\n", cep);
  if (list != NULL) {
    n = lengthL(list);
    for (i = 1; i <= n; i++) {
      element = getItemL(list, i);
      if (element != NULL) {
        endereco = getEnderecoEstabC(element);
        cep2 = getCep(endereco);
        if (strcmp(cep, cep2) == 0) {
          fprintf(*arqSaidaT, "%s %s %s %s %c %d\n", getCnpj(element),
                  getNomeEstabC(element), getCodt(element), getCep(endereco),
                  getFace(endereco), getNum(endereco));
        }
      }
      element = NULL;
    }
  } else {
    fprintf(*arqSaidaT, "Nao existem Estabelecimentos comerciais no cep %s.\n",
            cep);
  }
  free(cep);
}

void executarQryEcr(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas) {
  List list = NULL, list2 = NULL;
  Endereco endereco = NULL;
  Cidade cidade = NULL;
  Quadra quadra = NULL;
  void *element = NULL;
  int i, l, n, k;
  double x, y, w, h;
  char *cep, *cep2, letra, *tipo1, *tipo2;

  i = qtdCaracteres(arqEntradaQry);
  tipo1 = alocarString(i);

  fscanf(arqEntradaQry, "%s", tipo1);
  letra = fgetc(arqEntradaQry);
  letra = fgetc(arqEntradaQry);
  if ((feof(arqEntradaQry) == 0) && (letra != ' ') && (letra != '\n')) {
    fseek(arqEntradaQry, -1, SEEK_CUR);
    fscanf(arqEntradaQry, "%lf %lf %lf %lf\n", &x, &y, &w, &h);

    cidade = getCidade(canvas);
    dicionario = getDicionario(cidade);

    list = getElementsListInsideR(canvas, 1, x, y, w, h);

    if (list != NULL) {
      fprintf(*arqSaidaT, "ecr? %s %f %f %f %f\n", tipo1, x, y, w, y);
      hash = getSecaoDicionario(dicionario, secao10);
      l = lengthL(list);
      for (i = 1; i <= l; i++) {
        /* Quadras */
        quadra = getItemL(list, i);
        if (quadra != NULL) {
          cep = getCepQ(quadra);
          list2 = getHtList(hash, cep);
          if (list2 != NULL) {
            n = lengthL(list2);
            /* Estabelecimentos comerciais */
            for (k = 1; k <= n; k++) {
              element = getItemL(list2, k);
              endereco = getEnderecoEstabC(element);
              cep2 = getCep(endereco);
              tipo2 = getCodt(element);
              if ((strcmp(cep, cep2) == 0) && (strcmp(tipo1, tipo2) == 0)) {
                fprintf(*arqSaidaT, "Nome: %s, Tipo: %s, Cnpj: %s\n",
                        getNomeEstabC(element), getCodt(element),
                        getCnpj(element));
              }
            }
          }
          list2 = NULL;
        }
        quadra = NULL;
      }
    } else {
      fprintf(*arqSaidaT,
              "ecr? %s %f %f %f %f\n Nao existem Estabelecimentos comerciais.\n", tipo1, x, y, w, y);
    }
    eraseListL(list, NULL);
    eraseBase(list);
  } else {
    fseek(arqEntradaQry, -1, SEEK_CUR);
    cidade = getCidade(canvas);
    dicionario = getDicionario(cidade);

    hash = getSecaoDicionario(dicionario, secao3);

    list = getHtList(hash, tipo1);

    if (list != NULL) {
      fprintf(*arqSaidaT, "ecr? %s\n", tipo1);
      n = lengthL(list);
      /* Estabelecimentos comerciais */
      for (k = 1; k <= n; k++) {
        element = getItemL(list, k);
        endereco = getEnderecoEstabC(element);
        tipo2 = getCodt(element);
        if (strcmp(tipo1, tipo2) == 0) {
          fprintf(*arqSaidaT, "Nome: %s, Tipo: %s, Cnpj: %s\n",
                  getNomeEstabC(element), getCodt(element), getCnpj(element));
        }
      }
    } else {
      fprintf(*arqSaidaT,
              "ecr? %s\n Nao existem Estabelecimentos comerciais.\n", tipo1);
    }
  }
  free(tipo1);
}

void executarQryTecq(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas) {
  Cidade cidade = NULL;
  EstabC estabC = NULL;
  Endereco endereco = NULL;
  List list = NULL;
  int i, j, k = 1;
  char *cep, *cep2;

  i = qtdCaracteres(arqEntradaQry);
  cep = alocarString(i);

  fscanf(arqEntradaQry, "%s", cep);

  cidade = getCidade(canvas);
  dicionario = getDicionario(cidade);

  hash = getSecaoDicionario(dicionario, secao10);

  list = getHtList(hash, cep);

  if (list != NULL) {
    j = lengthL(list);
    fprintf(*arqSaidaT, "tecq? %s\n", cep);
    for (i = 1; i <= j; i++) {
      estabC = getItemL(list, i);
      endereco = getEnderecoEstabC(estabC);
      cep2 = getCep(endereco);
      if (strcmp(cep, cep2) == 0) {
        fprintf(*arqSaidaT, "%d - Codt: %s, Nome: %s\n", k, getCodt(estabC),
                getNomeEstabC(estabC));
        k++;
      }
    }
  } else {
    fprintf(*arqSaidaT,
            "tecq? %s\nNao existem Estabelecimentos comerciais.\n", cep);
  }
  free(cep);
}

void executarQryTecr(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas) {

  List list = NULL, list2 = NULL;
  Endereco endereco = NULL;
  Cidade cidade = NULL;
  Quadra quadra = NULL;
  void *element = NULL;
  int i, l, n, k, p = 1;
  double x, y, w, h;
  char *cep, *cep2;

  fscanf(arqEntradaQry, "%lf %lf %lf %lf\n", &x, &y, &w, &h);

  cidade = getCidade(canvas);
  dicionario = getDicionario(cidade);

  list = getElementsListInsideR(canvas, 1, x, y, w, h);

  if (list != NULL) {
    fprintf(*arqSaidaT, "tecr? %f %f %f %f\n", x, y, w, h);
    hash = getSecaoDicionario(dicionario, secao10);
    l = lengthL(list);
    for (i = 1; i <= l; i++) {
      quadra = getItemL(list, i);
      if (quadra != NULL) {
        cep = getCepQ(quadra);
        list2 = getHtList(hash, cep);
        if (list2 != NULL) {
          n = lengthL(list2);
          fprintf(*arqSaidaT, "Cep: %s\n", cep);
          p = 0;
          for (k = 1; k <= n; k++) {
            element = getItemL(list2, k);
            endereco = getEnderecoEstabC(element);
            cep2 = getCep(endereco);
            if (strcmp(cep, cep2) == 0) {
              p++;
              fprintf(*arqSaidaT, "%d - Codt: %s\n", p, getCodt(element));
            }
          }
          if(p == 0){
            fprintf(*arqSaidaT, "Nenhum estabelecimento encontrado na quadra analisada.\n");
          }
        }
        list2 = NULL;
      }
      quadra = NULL;
    }
    eraseListL(list, NULL);
    eraseBase(list);
  } else {
    fprintf(*arqSaidaT,
            "tecr? %f %f %f %f\nNao existem Estabelecimentos comerciais.\n", x, y, w, h);
  }
}

void executarQryDc(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas) {
  List list = NULL;
  Pessoa pessoa = NULL;
  Cidade cidade = NULL;
  char *num, *num2;
  Celular celular;
  int i, j;

  i = qtdCaracteres(arqEntradaQry);
  num = alocarString(i);

  fscanf(arqEntradaQry, "%s\n", num);

  cidade = getCidade(canvas);

  dicionario = getDicionario(cidade);
  hash = getSecaoDicionario(dicionario, secao2);

  list = getHtList(hash, num);
  if (list != NULL) {
    fprintf(*arqSaidaT, "dc? %s\n", num);
    j = lengthL(list);
    for (i = 1; i <= j; i++) {
      pessoa = getItemL(list, i);
      celular = getCelular(pessoa);
      num2 = getNumCelular(celular);
      if (strcmp(num, num2) == 0) {
        fprintf(*arqSaidaT, "O celular de numero %s pertence a pessoa de Nome: "
                            "%s %s, Cpf: %s, Sexo: %s, Nascimento: %s e "
                            "Operadora: %s",
                num, getNomeP(pessoa), getSobrenome(pessoa), getCpf(pessoa),
                getSexo(pessoa), getNasc(pessoa), getNomeOperadora(celular));
        break;
      }
    }
    if(i > j){
      fprintf(*arqSaidaT, "Pessoa nao encontrada.");
    }
  } else {
    fprintf(*arqSaidaT,
            "dc? %s\nNao existe pessoa com esse numero de celular.\n", num);
  }

  free(num);
}

void executarQryLec(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas) {
  List list = NULL;
  Pessoa pessoa = NULL;
  Cidade cidade = NULL;
  char *num, *num2;
  Celular celular;
  int i, j;
  double x = 0, y = 0;

  i = qtdCaracteres(arqEntradaQry);
  num = alocarString(i);

  fscanf(arqEntradaQry, "%s\n", num);

  cidade = getCidade(canvas);

  dicionario = getDicionario(cidade);
  hash = getSecaoDicionario(dicionario, secao2);

  list = getHtList(hash, num);
  if (list != NULL) {
    j = lengthL(list);
    for (i = 1; i <= j; i++) {
      pessoa = getItemL(list, i);
      celular = getCelular(pessoa);
      num2 = getNumCelular(celular);

      if (strcmp(num, num2) == 0) {
        fprintf(*arqSaidaT, "lec? %s\nOs dados do dono do celular sao\n"
                            "Nome: %s %s, Cpf: %s, Sexo: %s, Data De "
                            "Nascimento: %s.\n", num,
                getNomeP(pessoa), getSobrenome(pessoa), getCpf(pessoa),
                getSexo(pessoa), getNasc(pessoa));


        if (getCepCelular(celular) != NULL) {
          fprintf(*arqSaidaT, "O endereço da última conexão do celular é (cep: %s | face: %c | num: %d).\n", getCepCelular(celular), getFaceCelular(celular), getNumQCelular(celular));
          x = getXCelular(celular);
          y = getYCelular(celular);
          insertPointCanvas(canvas, createPoint(automaticId++, x, y));
        } else {
          fprintf(*arqSaidaT,
                  "O celular nao foi conectado a nenhuma torre.\n");
        }
        break;
      }

    }

  } else {
    fprintf(*arqSaidaT, "lec? %s\n Nenhum dados existente.", num);
  }
  free(num);
}

void executarQryLcc(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas) {
  List list = NULL;
  Pessoa pessoa = NULL;
  Cidade cidade = NULL;
  char *num, *num2;
  Celular celular;
  int i, j;
  double x = 0, y = 0;

  i = qtdCaracteres(arqEntradaQry);
  num = alocarString(i);

  fscanf(arqEntradaQry, "%s\n", num);

  cidade = getCidade(canvas);

  dicionario = getDicionario(cidade);
  hash = getSecaoDicionario(dicionario, secao2);

  fprintf(*arqSaidaT, "lcc? %s\nDono do celular nao existe.", num);

  list = getHtList(hash, num);
  if (list != NULL) {
    j = lengthL(list);
    fprintf(*arqSaidaT, "lcc? %s\n", num);
    for (i = 1; i <= j; i++) {
      pessoa = getItemL(list, i);
      celular = getCelular(pessoa);
      num2 = getNumCelular(celular);
      if (strcmp(num, num2) == 0) {
        x = getXCelular(celular);
        y = getYCelular(celular);

        if(x == -1 && y == -1){
          fprintf(*arqSaidaT, "O celular de numero %s nao foi conectado em nenhuma torre. Nao possui localidade.", num);
        } else {
          fprintf(*arqSaidaT, "O celular de numero %s esta localizado na coordenada x = %f e y = %f\n", num, x, y);
          x = getXCelular(celular);
          y = getYCelular(celular);
          insertPointCanvas(canvas, createPoint(automaticId++, x, y));
        }

        break;
      }

    }

    if(i > j){
        fprintf(*arqSaidaT, "O celular de numero %s nao foi conectado em nenhuma torre. Nao possui localidade.", num);
    }

  } else {
  }
  free(num);
}

void executarQryDpr(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas) {
  List list = NULL, list2 = NULL;
  Endereco endereco = NULL;
  Cidade cidade = NULL;
  void *element = NULL, *id = NULL, *element2 = NULL, *id2 = NULL, *id3 = NULL;
  int i, l, n, k;
  double x, y, w, h, x1, y1;

  fscanf(arqEntradaQry, "%lf %lf %lf %lf\n", &x, &y, &w, &h);

  cidade = getCidade(canvas);

  fprintf(*arqSaidaT, "dpr %f %f %f %f\nOs seguintes elementos foram removidos:\n", x, y, w, h);

  /* Hidrante */
  list = getElementsListInsideR(canvas, 2, x, y, w, h);

  dicionario = getDicionario(cidade);
  if (list != NULL) {
    l = lengthL(list);
    for (i = 1; i <= l; i++) {
      element = getItemL(list, i);
      if (element != NULL) {
        id = getIdH(element);
        fprintf(*arqSaidaT, "Hidrante com id: %s removido\n", (char *)id);
        removeHidrante(cidade, (char *)id);
      }
      element = NULL;
      id = NULL;
    }
    eraseListL(list, NULL);
    eraseBase(list);
  }

  /* Semafaro */
  list = getElementsListInsideR(canvas, 3, x, y, w, h);
  if (list != NULL) {
    l = lengthL(list);
    for (i = 1; i <= l; i++) {
      element = getItemL(list, i);
      if (element != NULL) {
        id = getIdS(element);
        fprintf(*arqSaidaT, "Semafaro com id: %s removido\n", (char *)id);
        removeSemafaro(cidade, (char *)id);
      }
      element = NULL;
      id = NULL;
    }
    eraseListL(list, NULL);
    eraseBase(list);
  }

  /* Torre */
  list = getElementsListInsideR(canvas, 4, x, y, w, h);
  if (list != NULL) {
    l = lengthL(list);
    for (i = 1; i <= l; i++) {
      element = getItemL(list, i);
      if (element != NULL) {
        id = getIdT(element);
        fprintf(*arqSaidaT, "Torre com id: %s removido\n", (char *)id);
        desconectarTorre_x_Celular(canvas, (char *)id);
        removeHT2(getSecaoDicionario(dicionario, secao14), (char *)id,
                  compareT);
        removeHT2(getSecaoDicionario(dicionario, secao16), (char *)id,
                  compareT);
        removeTorre(cidade, (char *)id);
      }
      element = NULL;
      id = NULL;
    }
    eraseListL(list, NULL);
    eraseBase(list);
  }

  /* Quadra */
  list = getElementsListPartialInsideR(canvas, 1, x, y, w, h);
  if (list != NULL) {
    l = lengthL(list);
    for (i = 1; i <= l; i++) {
      element = NULL;
      element = getItemL(list, i);
      if (element != NULL) {
        id = getCepQ(element);

        /* Estabelecimentos comerciais */
        hash = getSecaoDicionario(dicionario, secao10);
        list2 = getHtList(hash, (char *)id);
        n = lengthL(list2);
        for (k = 1; k <= n; k++) {
          element2 = NULL;
          id2 = NULL;
          id3 = NULL;
          element2 = getItemL(list2, k);
          if (element2 != NULL) {
            endereco = getEnderecoEstabC(element2);
            id2 = getCep(endereco);
            if (strcmp((char *)id, (char *)id2) == 0) {
              x1 = getXEndereco(endereco);
              y1 = getYEndereco(endereco);

              if (pontoInternoR(w, h, x, y, x1, y1) == 't') {
                id2 = getCnpj(element2);
                fprintf(*arqSaidaT, "Estabelecimento com cnpj: %s removido\n",
                        (char *)id2);

                hash = getSecaoDicionario(dicionario, secao3);
                id3 = getCodt(element2);
                removeHT(hash, (char *)id3, id2, compareEstabC);

                hash = getSecaoDicionario(dicionario, secao8);
                removeHT(hash, (char *)id2, id2, compareEstabC);

                hash = getSecaoDicionario(dicionario, secao9);
                id3 = NULL;
                id3 = getDescription(element2);
                if (id3 != NULL) {
                  removeHT(hash, (char *)id3, id2, compareEstabC);
                }

                hash = getSecaoDicionario(dicionario, secao10);
                removeHT(hash, (char *)id, id2, compareEstabC);

                removeEstabCidade(cidade, (char *)id2);
              }
            }
          }
        }

        /* Moradores */
        hash = getSecaoDicionario(dicionario, secao6);
        list2 = getHtList(hash, (char *)id);
        n = lengthL(list2);
        for (k = 1; k <= n; k++) {
          element2 = NULL;
          id2 = NULL;
          id3 = NULL;
          element2 = getItemL(list2, k);
          if (element2 != NULL) {
            endereco = getEndereco(element2);
            id2 = getCep(endereco);
            if (strcmp((char *)id, (char *)id2) == 0) {
              x1 = getXEndereco(endereco);
              y1 = getYEndereco(endereco);

              if (pontoInternoR(w, h, x, y, x1, y1) == 't') {
                id3 = getCpfM(element2);
                fprintf(*arqSaidaT, "Morador com cpf: %s removido\n",
                        (char *)id3);

                setMoradorP(getPessoaM(element2), NULL);

                hash = getSecaoDicionario(dicionario, secao11);
                removeHT(hash, (char *)id3, id3, compareMorador);

                hash = getSecaoDicionario(dicionario, secao6);
                removeHT(hash, (char *)id, id3, compareMorador);

                element2 = NULL;
                element2 = getCpf_x_Pessoa(canvas, (char *)id3);
                if (element2 != NULL) {
                  setEnderecoP(element2, NULL);
                }

                removeMoradorCidade(cidade, (char *)id3);
              }
            }
          }
        }

        if (verificarInteiramenteSobrepostoRR(
                getLargQ(element), getAltQ(element), getXQ(element),
                getYQ(element), w, h, x, y) == 't') {
          fprintf(*arqSaidaT, "Quadra com cep: %s removido\n", (char *)id);
          hash = getSecaoDicionario(dicionario, secao5);
          removeHT(hash, (char *)id, id, compareQ);
          removeQuadra(cidade, (char *)id);
        }
      }
      element = NULL;
      id = NULL;
    }
    eraseListL(list, NULL);
    eraseBase(list);
  }

  /* Texto */
  list = getElementsListPartialInsideR(canvas, 10, x, y, w, h);
  if (list != NULL) {
    l = lengthL(list);
    for (i = 1; i <= l; i++) {
      element = getItemL(list, i);
      if (element != NULL) {
        removeTextCanvas(canvas, getIdText(element));
      }
      element = NULL;
      id = NULL;
    }
    eraseListL(list, NULL);
    eraseBase(list);
  }

  /* Ponto */
  list = getElementsListPartialInsideR(canvas, 13, x, y, w, h);
  if (list != NULL) {
    l = lengthL(list);
    for (i = 1; i <= l; i++) {
      element = getItemL(list, i);
      if (element != NULL) {
        removePointCanvas(canvas, getIdPoint(element));
      }
      element = NULL;
      id = NULL;
    }
    eraseListL(list, NULL);
    eraseBase(list);
  }

  /* Linha */
  list = getElementsListPartialInsideR(canvas, 9, x, y, w, h);
  if (list != NULL) {
    l = lengthL(list);
    for (i = 1; i <= l; i++) {
      element = getItemL(list, i);
      if (element != NULL) {
        removeLineCanvas(canvas, getIdLine(element));
      }
      element = NULL;
      id = NULL;
    }
    eraseListL(list, NULL);
    eraseBase(list);
  }

  /* Polígono */
  list = getElementsListPartialInsideR(canvas, 11, x, y, w, h);
  if (list != NULL) {
    l = lengthL(list);
    for (i = 1; i <= l; i++) {
      element = getItemL(list, i);
      if (element != NULL) {
        removePolygonCanvas(canvas, getIdPolygon(element));
      }
      element = NULL;
      id = NULL;
    }
    eraseListL(list, NULL);
    eraseBase(list);
  }

}
