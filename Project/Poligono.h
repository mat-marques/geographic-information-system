#ifndef POLIGONO_H
#define POLIGONO_H

typedef void* Polygon;

/*
   Autor: Matheus Augusto Marques.
   Tad Poligono:
   Um poligon é um elemento geométrico constituido de n pontos. Quando ocorre a ligação dos n pontos de forma específica, então é formado uma fígura geométrica de n lados. Cada lado do polígono pode ou não serem do mesmo tamanho. Um polígono possui como características um número de identificação (id) único, um conjunto de pontos e opcionalmente uma cor. Um polígono possui uma quantidade de pontos representada por nPoints.
 */

/*
   Cria e retorna um polígono configurado com um id e cria um vetor de
   (2*nPoints).
   nPoints (nPoints > 0) é a quantidade de pontos que serão inseridos no vetor.
 */
Polygon createPolygon(int id, int nPoints);

/*
   A função retorna o id de polygon.
 */
int getIdPolygon(Polygon polygon);

/*
   O procedimento define um novo id para polygon.
 */
void setIdPolygon(Polygon polygon, int id);

/*
   A função insere um ponto de coordenada x y em polygon.
   Retorna 1 se o processo de inserção ocorreu com sucesso.
   Retorna 0 se o precesso de inserção falhou.
 */
int insertPointsPolygon(Polygon polygon, double x, double y);

/*
   A função retorna o vetor de pontos de polygon.
 */
double *getPointsPolygon(Polygon polygon);

/*
   O procedimento define um novo conjunto de ponto para polygon.
   nPoints > 0.
 */
void setPointsPolygon(Polygon polygon, double *points, int nPoints);

/*
   A função retorna a quantidade de pontos que compõem o vetor de pontos de polygon.
   O tamanho do vetor é (2 * nPoints).
 */
int getqtdPointsPolygon(Polygon polygon);

/*
   A função retorna a quantidade de pontos que foram inseridos atualmente no vetor de pontos de polygon.
   O tamanho do vetor é (2 * nPoints).
 */
int getnPointsPolygon(Polygon polygon);

/*
   A função retorna a coordenada x de polygon.
 */
double getXPolygon(Polygon polygon, int position);

/*
   O procedimento define uma novo x para polygon.
 */
void setXPolygon(Polygon polygon, int position, double x);

/*
   A função retorna a coordenada y de polygon.
 */
double getYPolygon(Polygon polygon, int position);

/*
   O procedimento define uma novo y para polygon.
 */
void setYPolygon(Polygon polygon, int position, double y);


/*
   A função retorna a espessura das linhas de polygon.
 */
int getLineSizePolygon(Polygon polygon);


/*
   O procedimento define uma nova espessura para as linhas de polygon.
 */
void setLineSizePolygon(Polygon polygon, int lineSize);


/*
   A função retorna o nome da cor de preenchimento da estrutura polygon.
 */
char *getColourFillPolygon(Polygon polygon);

/*
   O procedimento define uma nova de preenchimento para polygon.
 */
void setColourFillPolygon(Polygon polygon, char *colourFill);


/*
   A função retorna o nome da cor da linha da estrutura polygon.
 */
char *getColourLinePolygon(Polygon polygon);


/*
   O procedimento define uma nova cor para a linha de polygon.
 */
void setColourLinePolygon(Polygon polygon, char *colourLine);


/*
   A função verifica se o id de polygon é igual ao valor da variável id.
   Retorna 1 se forem iguais e 0 se forem diferentes.
 */
int comparePolygon(Polygon polygon, void *id);

/*
   O procedimento apaga todas as informações de polygon.
 */
void erasePolygon(Polygon polygon);

#endif
