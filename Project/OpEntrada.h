#ifndef OPENTRADAS_H
#define OPENTRADAS_H

/**
   Autor: Matheus Augusto Marques.
   Módulo: OpEntrada
   Modela um conjunto de operações referentes a manipulação dos parâmetros
   fornecidos para o programa pelo usúario. Os parametros geralmente
   são do tipo String, Inteiro ou Real.
 */

/**
   Retorna uma String referente ao parâmetro -f passado para o programa pelo usúario.
   O parâmetro -f deve ser valido.
 */
char *parametroF(char **argv, int argc);

/**
   Retorna uma String referente ao parâmetro -o passado para o programa pelo usúario.
   O parâmetro -o deve ser valido.
 */
char *parametroO(char **argv, int argc);

/**
   Retorna uma String referente ao parâmetro -e passado para o programa pelo usúario.
   O parâmetro -e deve ser valido.
 */
char *parametroE(char **argv, int argc);

/**
   Retorna um caracter. Retorna t se o comando -acc0 foi passado ao programa e retorna f caso não.
 */
char parametroAcc0(char **argv, int argc);

/**
   Retorna um caracter. Retorna t se o comando -acc foi passado ao programa e retorna f caso não.
 */
char parametroAcc(char **argv, int argc);

/**
   Retorna uma String referente ao parâmetro -q passado para o programa pelo usúario.
   O parâmetro -q deve ser valido.
 */
char *parametroQ(char **argv, int argc);

/**
   O procedimento imprime na saida do usuário informações sobre o autor do projeto.
 */
void parametroId(char **argv, int argc);

/*
   Retorna uma String referente ao parâmetro -ec passado para o programa pelo usúario.
   O parâmetro -ec deve ser valido.
 */
char *parametroEc(char **argv, int argc);

/*
   Retorna uma String referente ao parâmetro -pm passado para o programa pelo usúario.
   O parâmetro -pm deve ser valido.
 */
char *parametroPm(char **argv, int argc);

/*
   Retorna uma String referente ao parâmetro -tm passado para o programa pelo usúario.
   O parâmetro -tm deve ser valido.
 */
char *parametroTm(char **argv, int argc);

/**
   Retorna uma String referente ao nome do arquivo de entrada na string parametro.
 */
char *nomeArquivo(char *parametro);

/**
   Retorna uma String que é o resultado da concatenação de um dirPath + arqNome + extensao.
 */
char *concatenarElementos(char *dirPath, char *arqNome, char *extensao);

/**
   Retorna uma String que é o resultado da concatenação de um dirPath + arqNome.
 */
char *concatenarElementos2(char *dirPath, char *arqNome);

#endif
