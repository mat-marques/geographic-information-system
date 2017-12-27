#include "Svg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *createSvg(char *arqName) {
  FILE *file;
  file = fopen(arqName, "w");
  if (file == NULL) {
    printf("ERRO EM ARQUIVO DE SAIDA SVG.\n");
    exit(0);
  }

  return file;
}

void tagAbertura(FILE *arqSvg, double w, double h) {
  fprintf(arqSvg, "%s ", "<svg");
  fprintf(arqSvg, "width=\"%f\" ", w);
  fprintf(arqSvg, "height=\"%f\" ", h);
  fprintf(arqSvg, "%s\n", ">");
}

void tagRetangulo(FILE *arqSvg, double w, double h, double x, double y,
                  char *cor) {
  fprintf(arqSvg, "%s\n", "<rect");

  fprintf(arqSvg, " %s", "x=");
  fprintf(arqSvg, "\"%f\"\n", x);

  fprintf(arqSvg, " %s", "y=");
  fprintf(arqSvg, "\"%f\"\n", y);

  fprintf(arqSvg, " %s", "width=");
  fprintf(arqSvg, "\"%f\"\n", w);

  fprintf(arqSvg, " %s", "height=");
  fprintf(arqSvg, "\"%f\"\n", h);

  fprintf(arqSvg, " %s", "fill=");
  fprintf(arqSvg, "\"%s\"\n", cor);

  fprintf(arqSvg, " %s\n", "stroke=\"black\"");
  fprintf(arqSvg, " %s\n", "stroke-width=\"1\"");

  fprintf(arqSvg, "%s\n", " />");
}

void tagRetangulo2(FILE *arqSvg, double w, double h, double x, double y,
                   char *corB, char *corS) {

  fprintf(arqSvg, "%s\n", "<rect");

  fprintf(arqSvg, " %s", "x=");
  fprintf(arqSvg, "\"%f\"\n", x);

  fprintf(arqSvg, " %s", "y=");
  fprintf(arqSvg, "\"%f\"\n", y);

  fprintf(arqSvg, " %s", "width=");
  fprintf(arqSvg, "\"%f\"\n", w);

  fprintf(arqSvg, " %s", "height=");
  fprintf(arqSvg, "\"%f\"\n", h);

  fprintf(arqSvg, " %s", "fill=");
  fprintf(arqSvg, "\"%s\"\n", corB);

  fprintf(arqSvg, " %s", "stroke=\"");
  fprintf(arqSvg, " %s %s\n", corS, "\"");
  fprintf(arqSvg, " %s\n", "stroke-width=\"1\"");

  fprintf(arqSvg, "%s\n", " />");
}

void tagCirculo2(FILE *arqSvg, double r, double x, double y, char corB[60],
                 char corS[60]) {

  fprintf(arqSvg, "%s\n", "<circle");

  fprintf(arqSvg, " %s", "cx=");
  fprintf(arqSvg, "\"%f\"\n", x);

  fprintf(arqSvg, " %s", "cy=");
  fprintf(arqSvg, "\"%f\"\n", y);

  fprintf(arqSvg, " %s", "r=");
  fprintf(arqSvg, "\"%f\"\n", r);

  fprintf(arqSvg, " %s", "fill=");
  fprintf(arqSvg, "\"%s\"\n", corB);

  fprintf(arqSvg, " %s", "stroke=\"");
  fprintf(arqSvg, " %s %s\n", corS, "\"");
  fprintf(arqSvg, " %s\n", "stroke-width=\"1\"");

  fprintf(arqSvg, "%s\n", " />");
}

void tagCirculo(FILE *arqSvg, double r, double x, double y, char *cor) {

  fprintf(arqSvg, "%s\n", "<circle");

  fprintf(arqSvg, " %s", "cx=");
  fprintf(arqSvg, "\"%f\"\n", x);

  fprintf(arqSvg, " %s", "cy=");
  fprintf(arqSvg, "\"%f\"\n", y);

  fprintf(arqSvg, " %s", "r=");
  fprintf(arqSvg, "\"%f\"\n", r);

  fprintf(arqSvg, " %s", "fill=");
  fprintf(arqSvg, "\"%s\"\n", cor);

  fprintf(arqSvg, " %s\n", "stroke=\"black\"");
  fprintf(arqSvg, " %s\n", "stroke-width=\"1\"");

  fprintf(arqSvg, "%s\n", " />");
}

void tagCirculoOpacity(FILE *arqSvg, double r, double x, double y, char *cor) {

  fprintf(arqSvg, "%s\n", "<circle");

  fprintf(arqSvg, " %s", "cx=");
  fprintf(arqSvg, "\"%f\"\n", x);

  fprintf(arqSvg, " %s", "cy=");
  fprintf(arqSvg, "\"%f\"\n", y);

  fprintf(arqSvg, " %s", "r=");
  fprintf(arqSvg, "\"%f\"\n", r);

  fprintf(arqSvg, " %s", "fill=");
  fprintf(arqSvg, "\"%s\"\n", cor);

  fprintf(arqSvg, " %s\n", "stroke=\"black\"");
  fprintf(arqSvg, " %s\n", "stroke-width=\"1\"");
  fprintf(arqSvg, " %s\n", "fill-opacity=\"0.5\"");
  fprintf(arqSvg, "%s\n", " />");
}

void tagTexto(FILE *arqSvg, double x, double y) {
  fprintf(arqSvg, "%s", "<text");

  fprintf(arqSvg, " %s", "x=");
  fprintf(arqSvg, "\"%f\"", x);

  fprintf(arqSvg, " %s", "y=");
  fprintf(arqSvg, "\"%f\"", y);

  fprintf(arqSvg, " %s\n", "fill=\"red\"");

  fprintf(arqSvg, "%s", "font-size=\"");
  fprintf(arqSvg, "%d", 20);
  fprintf(arqSvg, "%s\n", "\"");

  fprintf(arqSvg, " %s", ">");

  fprintf(arqSvg, "%s", "SOBREPÕEM");
  fprintf(arqSvg, "%s\n", "</text>");
}

void tagTexto2(FILE *arqSvg, char *texto, char *cor, int fontSize, double x,
               double y) {
  fprintf(arqSvg, "%s", "<text");

  fprintf(arqSvg, " %s", "x=");
  fprintf(arqSvg, "\"%f\"", x);

  fprintf(arqSvg, " %s", "y=");
  fprintf(arqSvg, "\"%f\"", y);

  fprintf(arqSvg, "\n%s\n", "stroke-width=\"1\"");

  fprintf(arqSvg, "%s", "fill=\"");
  fprintf(arqSvg, "%s", cor);
  fprintf(arqSvg, "%s\n", "\"");

  fprintf(arqSvg, "%s", "font-size=\"");
  fprintf(arqSvg, "%d", fontSize);
  fprintf(arqSvg, "%s\n", "\"");

  fprintf(arqSvg, " %s", ">");
  fprintf(arqSvg, "%s", texto);
  fprintf(arqSvg, "%s\n", "</text>");
}

void tagTexto3(FILE *arqSvg, int id, char *texto, char *cor, int fontSize,
               char *fontFamily, double x, double y) {
  fprintf(arqSvg, "%s", "<text");

  fprintf(arqSvg, " id= \"%d\"\n", id);

  fprintf(arqSvg, " %s", "x=");
  fprintf(arqSvg, "\"%f\"", x);

  fprintf(arqSvg, " %s", "y=");
  fprintf(arqSvg, "\"%f\"", y);

  fprintf(arqSvg, "\n%s\n", "stroke-width=\"1\"");

  fprintf(arqSvg, "%s", "fill=\"");
  fprintf(arqSvg, "%s", cor);
  fprintf(arqSvg, "%s\n", "\"");

  fprintf(arqSvg, "%s", "font-size=\"");
  fprintf(arqSvg, "%d", fontSize);
  fprintf(arqSvg, "%s\n", "\"");

  fprintf(arqSvg, "%s", "font-family=\"");
  fprintf(arqSvg, "%s", fontFamily);
  fprintf(arqSvg, "%s\n", "\"");

  fprintf(arqSvg, " %s", ">");
  fprintf(arqSvg, "%s", texto);
  fprintf(arqSvg, "%s\n", "</text>");
}

void tagRetanguloSobreposicao(FILE *arqSvg, double x, double y, double w,
                              double h) {
  fprintf(arqSvg, "%s\n", "<rect");

  fprintf(arqSvg, " %s", "x=");
  fprintf(arqSvg, "\"%f\"\n", x);

  fprintf(arqSvg, " %s", "y=");
  fprintf(arqSvg, "\"%f\"\n", y);

  fprintf(arqSvg, " %s", "width=");
  fprintf(arqSvg, "\"%f\"\n", w);

  fprintf(arqSvg, " %s", "height=");
  fprintf(arqSvg, "\"%f\"\n", h);

  fprintf(arqSvg, " %s\n", "fill=\"none\"");
  fprintf(arqSvg, " %s\n",
          "style=\"stroke:black;stroke-width:3;stroke-dasharray:5\"");

  fprintf(arqSvg, "%s\n", " />");
}

void pontos(FILE *arqSvg, double x, double y, char *cor) {
  fprintf(arqSvg, "%s\n", "<circle");

  fprintf(arqSvg, " %s", "cx=");
  fprintf(arqSvg, "\"%.5f\"\n", x);

  fprintf(arqSvg, " %s", "cy=");
  fprintf(arqSvg, "\"%f\"\n", y);

  fprintf(arqSvg, " %s\n", "r=\"2\"");

  fprintf(arqSvg, " %s", "fill=");
  fprintf(arqSvg, "\"%s\"\n", cor);

  fprintf(arqSvg, " %s\n", "stroke=\"black\"");
  fprintf(arqSvg, " %s\n", "stroke-width=\"1\"");

  fprintf(arqSvg, "%s\n", " />");
}

void linha(FILE *arqSvg, double x1, double y1, double x2, double y2,
           char *cor) {
  fprintf(arqSvg, "%s\n", "<line");

  fprintf(arqSvg, " %s", "x1=");
  fprintf(arqSvg, "\"%.5f\"\n", x1);

  fprintf(arqSvg, " %s", "y1=");
  fprintf(arqSvg, "\"%f\"\n", y1);

  fprintf(arqSvg, " %s", "x2=");
  fprintf(arqSvg, "\"%.5f\"\n", x2);

  fprintf(arqSvg, " %s", "y2=");
  fprintf(arqSvg, "\"%f\"\n", y2);

  fprintf(arqSvg, " %s", "style=");
  fprintf(arqSvg, "\"%s", "stroke: ");
  fprintf(arqSvg, " %s;", cor);
  fprintf(arqSvg, " %s\"\n", "stroke-width: 2");

  fprintf(arqSvg, "%s\n", "/>");
}

void tagLinha2(FILE *arqSvg, int id, double x1, double y1, double x2, double y2, char *cor, int sizeLine) {

  fprintf(arqSvg, "%s\n", "<line");

  fprintf(arqSvg, " id= \"%d\"\n", id);

  fprintf(arqSvg, " %s", "x1=");
  fprintf(arqSvg, "\"%.5f\"\n", x1);

  fprintf(arqSvg, " %s", "y1=");
  fprintf(arqSvg, "\"%f\"\n", y1);

  fprintf(arqSvg, " %s", "x2=");
  fprintf(arqSvg, "\"%.5f\"\n", x2);

  fprintf(arqSvg, " %s", "y2=");
  fprintf(arqSvg, "\"%f\"\n", y2);

  fprintf(arqSvg, " %s", "style=");
  fprintf(arqSvg, "\"%s", "stroke: ");
  fprintf(arqSvg, " %s;", cor);
  fprintf(arqSvg, " %s %d\"\n", "stroke-width:", sizeLine);

  fprintf(arqSvg, "%s\n", "/>");
}

void tagMultiplasLinhas(FILE *arqSvg, int id, double *pontos, int n, char *corL, char *corF, int lineSize)
{
  int i;

  fprintf(arqSvg, "%s\n", "<polyline");
  fprintf(arqSvg, "points=\"");
  for(i = 0; i < n; i = i + 2){
    fprintf(arqSvg, "%f,%f", *(pontos + i), *(pontos + i + 1));
    if(i < n){
      fprintf(arqSvg, " ");
    }
  }
  fprintf(arqSvg, "\"\n");
  fprintf(arqSvg, "style=\"");

  fprintf(arqSvg, "fill:%s;", corF);
  fprintf(arqSvg, "stroke:%s;", corL);
  fprintf(arqSvg, "stroke-width:%d;", lineSize);

  fprintf(arqSvg, "%s\n", "/>");

}

void tagPoligono(FILE *arqSvg, int id, double *pontos, int n, char *corL, char *corF, int lineSize)
{
  int i;

  fprintf(arqSvg, "%s\n", "<polygon");
  fprintf(arqSvg, "points=\"");
  for(i = 0; i < n; i = i + 2){
    fprintf(arqSvg, "%f,%f", *(pontos + i), *(pontos + i + 1));
    if(i < n){
      fprintf(arqSvg, " ");
    }
  }
  fprintf(arqSvg, "\"\n");
  fprintf(arqSvg, "style=\"");

  fprintf(arqSvg, "fill:%s;", corF);
  fprintf(arqSvg, "stroke:%s;", corL);
  fprintf(arqSvg, "stroke-width:%d;", lineSize);

  fprintf(arqSvg, "%s\n", "/>");

}


void tagEllipse(FILE *arqSvg, int id, double cx, double cy, double rx, double ry, char *corL, char *corF, int lineSize)
{

  fprintf(arqSvg, "%s\n", "<ellipse");


  fprintf(arqSvg, " %s", "cx=");
  fprintf(arqSvg, "\"%.5f\"\n", cx);

  fprintf(arqSvg, " %s", "cy=");
  fprintf(arqSvg, "\"%f\"\n", cy);

  fprintf(arqSvg, " %s", "rx=");
  fprintf(arqSvg, "\"%.5f\"\n", rx);

  fprintf(arqSvg, " %s", "ry=");
  fprintf(arqSvg, "\"%f\"\n", ry);

  fprintf(arqSvg, "fill:%s;", corF);
  fprintf(arqSvg, "stroke:%s;", corL);
  fprintf(arqSvg, "stroke-width:%d;", lineSize);

  fprintf(arqSvg, "%s\n", "/>");

}

void tagFechamento(FILE *arqSvg) { fprintf(arqSvg, "%s\n", "</svg>"); }
