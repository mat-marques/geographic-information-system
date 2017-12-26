#ifndef TEXTO_H
#define TEXTO_H

typedef void* Text;

/*
   Autor: Matheus Augusto Marques.
   Tad Texto:
   Uma texto é um tipo de dado composto e formado por um conjunto de símbolos de um alfabeto. Um texto é definido por um número de identificação (id) único, um conjunto de símbolos de um alfabeto, e uma coordenada x, y. Opcionalmente um texto também pode ser configurado para uma família especifica de fontes, possuir uma cor e ter um tamanho de fonte.
 */

/*
   A função cria e retorna um texto configurado com
   id - número de identificação,
   text - conjunto de símbolos de um alfabeto
   e um ponto no plano cartesiano com coordenadas em x e y.
 */
Text createText(int id, char *text, double x, double y);

/*
   A função retorna o id de text.
 */
int getIdText(Text text);

/*
   O procedimento define uma novo id para text.
 */
void setIdText(Text text, int id);

/*
   A função retorna o texto que compõe de text.
 */
char *getText(Text text);

/*
   O procedimento define uma nova texto para text.
 */
void setText(Text text, char *nText);

/*
   A função retorna a coordenada x de text.
 */
double getXText(Text text);

/*
   O procedimento define uma nova coordenada x para text.
 */
void setXText(Text text, double x);

/*
   A função retorna a coordenada y de text.
 */
double getYText(Text text);

/*
   O procedimento define uma nova coordenada y para text.
 */
void setYText(Text text, double y);

/*
   A função retorna a cor que compõe text.
   Retorna null caso a cor não tenha sido definida.
 */
char *getColourText(Text text);

/*
   O procedimento define a cor de text.
 */
void setColourText(Text text, char *colour);

/*
   A função retorna o nome da familia de fontes que compõe text.
   Retorna null caso a familia de fontes não tenha sido definida.
 */
char *getFontFamilyText(Text text);

/*
   O procedimento define o nome da família de fontes de text.
 */
void setFontFamilyText(Text text, char *fontFamily);

/*
   A função retorna o nome da familia de fontes que compõe text.
   Retorna 12 caso a familia de fontes não tenha sido definida.
 */
int getFontSizeText(Text text);

/*
   O procedimento define o tamanho da fonte de text.
 */
void setFontSizeText(Text text, int fontSize);

/*
   A função verifica se o id de text é igual ao valor da variável id.
   Retorna 1 se forem iguais e 0 se forem diferentes.
 */
int compareText(Text text, void *id);

/*
   O procedimento apaga todas as informações de text.
 */
void eraseText(Text text);


#endif
