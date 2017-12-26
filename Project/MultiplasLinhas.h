#ifndef MULTIPLASLINHAS_H
#define MULTIPLASLINHAS_H

typedef void* PolyLine;

/*
   Autor: Matheus Augusto Marques.
   Tad MultiplasLinha:
   Um dado do tipo multiplas linhas é constituído de n (nPoints) pontos e um número de identificação único (id). Cada ponto será conectado a outro ponto através de uma linha. Basicamente, os pontos serão conectados da seguinte forma: o primeiro ponto conecta com o segundo, o segundo conecta com o terceiro, o terceiro conecta com o quarto e assim por diante. A conexão entre os pontos será representada, como mencionado anteriormente, por uma linha. A linha e os pontos podem opcionalmente ser configurados com uma cor
 */


/*
   Cria e retorna um dado do tipo PolyLine configurado com um id e uma quantidade de nPoints.
   nPoints > 0.
 */
PolyLine createPolyLine(int id, int nPoints);


/*
   A função retorna o id de polyLine.
 */
int getIdPolyLine(PolyLine polyLine);


/*
   O procedimento define um novo id para polyLine.
 */
void setIdPolyLine(PolyLine polyLine, int id);


/*
   A função insere um ponto de coordenada x y em polyLine.
   Retorna 1 se o processo de inserção ocorreu com sucesso.
   Retorna 0 se o precesso de inserção falhou.
 */
int insertPointsPolyLine(PolyLine polyLine, double x, double y);


/*
   A função retorna o conjunto de pontos (vetor) que estão os pontos de polyLine
 */
double *getPoints(PolyLine polyLine);


/*
   O procedimento define um novo conjunto de pontos para polyLine.
 */
void setPoints(PolyLine polyLine, double *points, int nPoints);


/*
   A função retorna a quantidade de pontos que podem ser inseridos em polyLine.
 */
int getnPoints(PolyLine polyLine);


/*
   A função retorna a quantidade de pontos que foram inseridos em polyLine.
 */
int getqtdPointsPolyLine(PolyLine polyLine);


/*
   A função retorna a coordenada x de um dos pontos de polyLine na posição position.
 */
double getXPolyLine(PolyLine polyLine, int position);


/*
   O procedimento define um novo valor para a coordenada x de um ponto na posição position.
 */
void setXPolyLine(PolyLine polyLine, int position, double x);


/*
   A função retorna a coordenada y de um dos pontos de polyLine na posição position.
 */
double getYPolyLine(PolyLine polyLine, int position);


/*
   O procedimento define um novo valor para a coordenada y de um ponto na posição position.
 */
void setYPolyLine(PolyLine polyLine, int position, double y);


/*
   A função retorna o nome da cor das linhas de polyLine
 */
char *getColourLinePolyLine(PolyLine polyLine);


/*
   O procedimento define uma nova cor para as linhas de conexão de polyLine.
 */
void setColourLinePolyLine(PolyLine polyLine, char *colour);


/*
   A função retorna o nome da cor dos pontos de polyLine
 */
char *getColourPointPolyLine(PolyLine polyLine);


/*
   O procedimento define uma nova cor para os pontos de polyLine.
 */
void setColourPointPolyLine(PolyLine polyLine, char *colour);


/*
   A função verifica se o id de polyLine é igual ao valor da variável id.
   Retorna 1 se forem iguais e 0 se forem diferentes.
 */
int comparePolyLine(PolyLine polyLine, void *id);


/*
   A função apaga todas as informações de polyLine.
 */
void erasePolyLine(PolyLine polyLine);

#endif
