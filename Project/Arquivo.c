#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Arquivo.h"


FILE *createArqR(char *path){
    FILE *file;
    if(path==NULL){
      exit(0);
    }
    file = fopen(path, "r");
    if(file == NULL){
        printf("ERRO EM ARQUIVO.");
        exit(0);
    }
    return file;
}


FILE *createArqW(char *path){
    FILE *file;
    if(path==NULL){
      exit(0);
    }

    file = fopen(path, "w");
    if(file==NULL){
        printf("ERRO EM ARQUIVO.\n");
        exit(0);
    }

    return file;
}

FILE *createArqA(char *path){
    FILE *file;
    if(path==NULL){
      exit(0);
    }
    file = fopen(path, "a");
    if(file==NULL){
        printf("ERRO EM ARQUIVO.\n");
        exit(0);
    }

    return file;
}

void fillArq(FILE *arq, char caracter){
    fprintf(arq, "%c", caracter);
}


void fillArq1(FILE *arq, char *palavra){
    fprintf(arq, "%s", palavra);
}


void fillArq2(FILE *arq, float out){
    fprintf(arq, "%f", out);
}


void fillArq3(FILE *arq, int out){
    fprintf(arq, "%d", out);
}

void fillArq4(FILE *arq, double out){
    fprintf(arq, "%f", out);
}

void fillSpace(FILE *arq){
    fprintf(arq, "%c", ' ');
}

void fillTab(FILE *arq){

    fprintf(arq, "%s", "   ");
}

void fillBreakLine(FILE *arqSaida){
    fprintf(arqSaida, "%c", '\n');
}

int getQuantidade(FILE *file){
    int quantity=0;
    if(file!=NULL){
        char letra=fgetc(file);
        while(letra!='\n'){
            quantity++;
            letra = fgetc(file);
        }
    }
    fseek(file, -(quantity+1), SEEK_CUR);
    return quantity;
}

/**
  Cria uma string de tamanho quantity e percorre o arquivo file colocando cada caracter lido na string alocada.
  Por fim, retorna essa string.
*/
char *getString(FILE *file, int quantity){
    char *parametro=NULL, letra;
    int i=0;

    parametro = (char *) malloc(quantity * sizeof(char));
    if(parametro == NULL){
        printf("ERRO NA ALOCAÇÃO DE MEMÓRIA. FUNÇÃO 'getString'.\n");
        return NULL;
    }
    parametro[i]='\0';
    letra = fgetc(file);
    do{
        parametro[i] = letra;
        i++;
        letra = fgetc(file);
    }while(letra!='\n'&&letra!='\r');
    parametro[i]='\0';
    return parametro;
}
