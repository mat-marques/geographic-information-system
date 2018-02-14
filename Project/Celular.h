#ifndef CELULAR_H
#define CELULAR_H


typedef void* Celular;

/*
   Autor: Matheus Augusto Marques.
   Tad Celular:
   Um celular é definido por um número, uma operadora, uma torre de conexão e por seu usuário.
   O dado número define um número único e exclusivo de um celular.
   O dado operadora define em qual operadora o celular pertence.
   O dado torre de conexão define em qual torre-base o celular está conectado.
   O dado usuário define quem é o dono do celular.
*/

/*
  Cria e retorna um celular definido com o numero num.
*/
Celular criaCelular(char *num);

/*
  A função retorna o número do celular.
*/
char *getNumCelular(Celular celular);

/*
  O procedimento define um novo número para o celular.
*/
void setNumCelular(Celular celular, char *num);


/*
  Retorna a coordenada x da última posição onde o celular foi conectado a uma torre.
*/
double getXCelular(Celular celular);


/*
  Defina uma nova coordenada x para o celular. Coordenada onde o celular foi conectado
  por último em um torre.
*/
void setXCelular(Celular celular, double x);


/*
  Retorna a coordenada y da última posição onde o celular foi conectado a uma torre.
*/
double getYCelular(Celular celular);


/*
  Defina uma nova coordenada y para o celular. Coordenada onde o celular foi conectado
  por último em um torre.
*/
void setYCelular(Celular celular, double y);


/*
  Retorna o cep da última quadra que o celular estava quando foi conectado a uma torre.
*/
char *getCepCelular(Celular celular);


/*
  Define um novo cep para a última quadra que o celular estava quando foi conectado a uma torre.
*/
void setCepCelular(Celular celular, char *cep);

/*
  Retorna a face da última conexão do celular.
*/
char getFaceCelular(Celular celular);


/*
  Define a face da última conexão do celular.
*/
void setFaceCelular(Celular celular, char face);


/*
  Retorna o número da residência da última conexão do celular.
*/
int getNumQCelular(Celular celular);


/*
  Define o número da residência da última conexão do celular.
*/
void setNumQCelular(Celular celular, int numQ);

/*
  A função retorna o nome da operadora do celular.
*/
char *getNomeOperadora(Celular celular);

/*
  O procedimento define uma nova operadora para o celular.
*/
void setNomeOperadora(Celular celular, char *nomeOperadora);

/*
  A função retorna quem é o dono do celular.
  O dado de retorno é uma pessoa.
*/
void *getDonoCelular(Celular celular);

/*
  O procedimento define um novo proprietário para o celular.
*/
void *setDonoCelular(Celular celular, void *pessoa);

/*
  A função retorna o id da torre-base que está conectada no celular.
*/
char *getIdTorreConexao(Celular celular);

/*
  O procedimento define uma nova torre-base de conexão para o celular.
*/
void setIdTorreConexao(Celular celular, char *id);

/*
  A função verifica se o numero de celular é igual ao número de num.
  1 - se forem iguais.
  0 - se forem diferentes.
*/
int compareCelulares(Celular celular, void* num);

/*
  O procedimento apaga todos os dados de um celular.
*/
void removeCelular(Celular celular);

#endif
