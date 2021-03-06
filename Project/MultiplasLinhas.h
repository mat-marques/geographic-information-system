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
  A função retorna um vetor de números reais. Esse vetor contém as coordenadas x e y dos pontos que estão em polygon.
*/
double *getPointsPolyLine(PolyLine polyLine);


/*
   A função retorna a quantidade de pontos que podem ser inseridos em polyLine.
 */
int getnPointsPolyLine(PolyLine polyLine);


/*
   A função retorna a quantidade de pontos que foram inseridos em polyLine.
 */
int getQtdPointsPolyLine(PolyLine polyLine);


/*
   A função retorna a coordenada x de um dos pontos de polyLine na posição position.
 */
double getXPolyLine(PolyLine polyLine, int point);


/*
   O procedimento define um novo valor para a coordenada x de um ponto na posição position.
 */
void setXPolyLine(PolyLine polyLine, int point, double x);


/*
   A função retorna a coordenada y de um dos pontos de polyLine na posição position.
 */
double getYPolyLine(PolyLine polyLine, int point);


/*
   O procedimento define um novo valor para a coordenada y de um ponto na posição position.
 */
void setYPolyLine(PolyLine polyLine, int point, double y);


/*
   A função retorna o tamanho da espessura das linhas de polyLine.
 */
int getLineSizePolyLine(PolyLine polyLine);


/*
   O procedimento define um novo valor para a espessura da linha de polyLine.
 */
void setLineSizePolyLine(PolyLine polyLine, int lineSize);


/*
   A função retorna o nome da cor das linhas de polyLine
 */
char *getColourLinePolyLine(PolyLine polyLine);


/*
   O procedimento define uma nova cor para as linhas de conexão de polyLine.
 */
void setColourLinePolyLine(PolyLine polyLine, char *colour);


/*
   A função retorna o nome da cor de preenchimento de polyLine
 */
char *getColourFillPolyLine(PolyLine polyLine);


/*
   O procedimento define uma nova cor para a cor de preenchimento de polyLine.
 */
void setColourFillPolyLine(PolyLine polyLine, char *colour);


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
