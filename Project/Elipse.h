#ifndef ELIPSE_H
#define ELIPSE_H

typedef void* Ellipse;

/*
Autor: Matheus Augusto Marques.
Tad Elipse:
  Uma elipse é composta por um ponto central com coordenadas cx, cy e também possui dois raios. Um raio (rx) está relacionado ao eixo x e o outro (ry) está relacionado ao eixo y. Opcionalmente a elipse pode ter uma cor. Além disso, uma elipse possui um número (id) de identificação único e exclusivo com a finalidade de diferenciar as elipses no espaço. 
 */

/*
  A função cria e retorna uma ellipse definida com um id, no ponto cx, cy e com raio em rx e ry.
 */
Ellipse createEllipse(int id, double cx, double cy, double rx, double ry);

/*
   A função retorna o valor id configurado na ellipse.
 */
int getIdEllipse(Ellipse ellipse);

/*
   O procedimento define uma novo valor de id para a ellipse.
 */
void setIdEllipse(Ellipse ellipse, int id);

/*
   A função retorna o valor cx configurado na ellipse.
 */
double getCXEllipse(Ellipse ellipse);

/*
   O procedimento define uma novo valor cx para a ellipse.
 */
void setCXEllipse(Ellipse ellipse, double cx);

/*
   A função retorna o valor cy configurado na ellipse.
 */
double getCYEllipse(Ellipse ellipse);

/*
   O procedimento define uma novo valor cy para a ellipse.
 */
void setCYEllipse(Ellipse ellipse, double cy);

/*
   A função retorna o valor rx configurado na ellipse.
 */
double getRXEllipse(Ellipse ellipse);

/*
   O procedimento define uma novo valor rx para a ellipse.
 */
void setRXEllipse(Ellipse ellipse, double rx);

/*
   A função retorna o valor ry configurado na ellipse.
 */
double getRYEllipse(Ellipse ellipse);

/*
   O procedimento define uma novo valor ry para a ellipse.
 */
void setRYEllipse(Ellipse ellipse, double ry);

/*
   A função retorna a cor configurada na ellipse.
   Retorna null caso a cor não foi definida.
 */
char *getColourEllipse(Ellipse ellipse);

/*
   O procedimento define uma nova cor para a ellipse.
 */
void setColourEllipse(Ellipse ellipse, char *colour);

/*
   A função verifica se o id de ellipse é igual ao valor da variável id.
   Retorna 1 se forem iguais e 0 se forem diferentes.
 */
int compareEllipses(Ellipse ellipse, void *id);

/*
   O procedimento apaga as informações que compõem uma ellipse.
 */
void eraseEllipse(Ellipse ellipse);

#endif
