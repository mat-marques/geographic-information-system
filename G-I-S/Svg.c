#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Svg.h"


FILE *createSvg(char *arqName){
    FILE *file;
    file = fopen(arqName, "w");
    if(file==NULL){
        printf("ERRO EM ARQUIVO DE SAIDA SVG.\n");
        exit(0);
    }

    return file;
}

void tagAbertura(FILE *arqSvg, double w, double h){
    fprintf(arqSvg, "%s ", "<svg");
    fprintf(arqSvg, "width=\"%f\" ", w);
    fprintf(arqSvg, "height=\"%f\" ", h);
    fprintf(arqSvg, "%s\n", ">");
}


void tagRetangulo(FILE *arqSvg,double w, double h, double x, double y, char *cor){
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

void tagRetangulo2(FILE *arqSvg,double w, double h, double x, double y, char corB[60], char corS[60]){
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

void tagCirculo2(FILE *arqSvg,double r, double x, double y, char corB[60], char corS[60]){
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

void tagCirculo(FILE *arqSvg, double r, double x, double y, char cor[30]){
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

void tagTexto(FILE *arqSvg, double x, double y){
    fprintf(arqSvg, "%s", "<text");

    fprintf(arqSvg, " %s", "x=");
    fprintf(arqSvg, "\"%f\"", x);

    fprintf(arqSvg, " %s", "y=");
    fprintf(arqSvg, "\"%f\"", y);

    fprintf(arqSvg, " %s\n", "fill=\"red\"");

    fprintf(arqSvg, " %s", ">");
    fprintf(arqSvg, "%s", "sobrepoe");
    fprintf(arqSvg, "%s\n", "</text>");
}

void tagRetanguloSobreposicao(FILE *arqSvg, double x, double y, double w, double h){
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
    fprintf(arqSvg, " %s\n", "style=\"stroke:black;stroke-width:3;stroke-dasharray:5\"");

    fprintf(arqSvg, "%s\n", " />");
}

void pontos(FILE *arqSvg, double x, double y, char *cor){
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

void tagFechamento(FILE *arqSvg){
    fprintf(arqSvg, "%s\n", "</svg>" );
}
