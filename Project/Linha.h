#ifndef LINHA_H
#define LINHA_H

typedef void* Line;

/*
   Autor: Matheus Augusto Marques.
   Tad Linha:
   Uma linha é uma abstração utilizada para conectar dois pontos em um plano.
   Uma linha possui um número de identificação (id) único e duas coordenas geográficas de dois pontos. As coordenadas x1, y1 corespondem as posições do primeiro ponto, enquanto x2, y2 são as posições do segundo ponto. Uma linha também possui opcionalmente uma cor e um tamanho de espessura.
 */


/*
   A função cria e retorna uma linha configura com um id e as coordenadas de dois pontos.
 */
Line createLine(int id, double x1, double y1, double x2, double y2);

/*
   A função retorna o id (número de identificação) de line.
 */
int getIdLine(Line line);

/*
   O procedimento define um novo id para a estrutura line.
 */
void setIdLine(Line line, int id);

/*
   A função retorna a coordenada x do primeiro ponto de line.
 */
double getX1Line(Line line);

/*
   O procedimento define um novo x1 para a estrutura line.
 */
void setX1Line(Line line, double x1);

/*
   A função retorna a coordenada y do primeiro ponto de line.
 */
double getY1Line(Line line);

/*
   O procedimento define um novo y1 para a estrutura line.
 */
void setY1Line(Line line, double y1);

/*
   A função retorna a coordenada x do segundo ponto de line.
 */
double getX2Line(Line line);

/*
   O procedimento define um novo x2 para a estrutura line.
 */
void setX2Line(Line line, double x2);

/*
   A função retorna a coordenada y do segundo ponto de line.
 */
double getY2Line(Line line);

/*
   O procedimento define um novo y2 para a estrutura line.
 */
void setY2Line(Line line, double y2);

/*
   A função retorna a espessura de line.
 */
int getSizeLine(Line line);

/*
   O procedimento define uma nova espessura para a estrutura line.
 */
void setSizeLine(Line line, int sizeLine);

/*
   A função retorna a cor de line.
 */
char *getColourLine(Line line);

/*
   O procedimento define uma nova cor para a estrutura line.
 */
void setColourLine(Line line, char *colourLine);

/*
   A função verifica se o id de line é igual ao valor da variável id.
   Retorna 1 se forem iguais e 0 se forem diferentes.
 */
int compareLines(Line line, void *id);

/*
   O procedimento apaga todas as informações de line.
 */
void eraseLine(Line line);

#endif
