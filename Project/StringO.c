#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StringO.h"


char *criarString(char *char1) {
  int i = 0;
  char *charR = NULL;
  i = strlen(char1) + 1;
  charR = (char *)malloc(i * sizeof(char));
  strcpy(charR, char1);
  return charR;
}

int qtdCaracteres(FILE *file){
  char letra;
  int i=0;
  letra = fgetc(file);
  do{
    i++;
    letra = fgetc(file);
  }while(letra!=' '&&letra!='\n');
  fseek(file, -(i+1), SEEK_CUR);
  return i+1;
}

int compareStrings(void *s1, void *s2){
  char *string1 = (char*) s1;
  char *string2 = (char*) s2;

  if(strcmp(string1, string2) == 0){
    return 1;
  }
  return 0;
}

char *alocarString(int size){
  char *newString0=NULL;
  newString0 = (char*) calloc(size, sizeof(char));
  if(newString0==NULL){
    printf("ERRO EM ALOCACAO DE MEMORIA.\n");
    exit(0);
  }
  return newString0;
}

int sizeStringElement(char *oldString, int *index){
  int i = *index, size=0;
  char letra;
  if(oldString!=NULL){
    while(1)
    {
      letra = oldString[i];
      i++;
      if(letra==' '|| letra=='\0')
      {
        break;
      }
      else
      {
        size++;
      }
    }
    *index = i;
  }
  return size;
}

char *newStringElement(char *oldString, int qtd, int index){
  char *new0=NULL;
  int i=0, j = 0;
  if(oldString!=NULL) {
    new0 = (char *) malloc(qtd * sizeof(char));
    if(new0==NULL){
      printf("ERRO EM ALOCACAO DE MEMORIA.");
      exit(0);
    }
    new0[0] = '\0';
    for (i = index; i < (index + (qtd - 1)); i++) {
      new0[j] = oldString[i];
      j++;
    }
    new0[j] = '\0';
  }
  return new0;
}

void desalocar(char *valor){
  if(valor!=NULL)
  {
    free(valor);
    valor=NULL;
  }
}

void desalocarString(void *s){
  char *s1 = (char*) s;
  if(s!=NULL)
  {
    free(s1);
    s1=NULL;
  }
}

char *concatenarStrings(char *concatenar, char *palavra){
  int tamanho1=0, tamanho2=0, resultado=0;
  char letra='0', *new0=NULL;
  if(palavra!=NULL)
  {
    tamanho1 = strlen(palavra);
    if (concatenar != NULL)
    {
      tamanho2 = strlen(concatenar);
      resultado = tamanho1 + tamanho2;
      new0 = (char *) malloc((resultado + 1)*sizeof(char));
      if (new0 == NULL)
      {
        printf("ERRO DE ALOCACAO DE MEMORIA\n");
        return NULL;
      }
      new0[0]='\0';
      strcpy(new0, concatenar);
      if (tamanho1 == 1)
      {

        letra = palavra[0];
        new0[resultado - 1] = letra;
        new0[resultado] = '\0';
      } else
      strcat(new0, palavra);

    }
    else
    {
      new0 = (char *) malloc((tamanho1 + 1)*sizeof(char));
      if (new0 == NULL)
      {
        printf("ERRO DE ALOCACAO DE MEMORIA\n");
        return NULL;
      }
      new0[0] = '\0';
      if (tamanho1 == 1)
      {
        letra = palavra[0];
        new0[0] = letra;
        new0[1] = '\0';
      }
      else
      strcpy(new0, palavra);
    }
    return new0;
  }

  return NULL;
}

char verificarBarra(char *nome, char *diretorio){
  if(diretorio!=NULL&&nome!=NULL){
    if(((nome[0]=='/')&&(diretorio[strlen(diretorio)-1]!='/')))
    {
      return '1';
    }
    if(((nome[0]!='/')&&(nome[0]!='.')&&(diretorio[strlen(diretorio)-1]=='/')))
    {
      return '2';
    }
    if((nome[0]=='/')&&(diretorio[strlen(diretorio)-1]=='/'))
    {
      return '3';
    }
    if((nome[0]!='/')&&(nome[0]!='.')&&(diretorio[strlen(diretorio)-1]!='/'))
    {
      return '4';
    }
    if((nome[0]=='.'&&nome[1]=='/')&&(diretorio[strlen(diretorio)-1]!='/')){
      return '5';
    }
    if((nome[0]=='.'&&nome[1]=='/')&&(diretorio[strlen(diretorio)-1]=='/')){
      return '6';
    }
    if((nome[0]=='.'&&nome[1]=='.'&&nome[2]=='/')&&
    (diretorio[strlen(diretorio)-1]!='/'))
    {
      return '7';
    }
    if((nome[0]=='.'&&nome[1]=='.'&&nome[2]=='/')&&
    (diretorio[strlen(diretorio)-1]=='/'))
    {
      return '8';
    }
  }

   return 'f';
}

char *colocarBarra(char *palavra){
  char *new0 = NULL;
  char barra = '/';
  if(palavra!=NULL){
    new0 = concatenarStrings(palavra, &barra);
  }
  return new0;
}

char verificarGeo(char *arqNome){
  int i;
  if(arqNome!=NULL){
    int tamanho = strlen(arqNome);
    for(i=0; i<tamanho-3;i++)
    {
      if((arqNome[i]=='.')&&(arqNome[i+1]=='g')&&(arqNome[i+2]=='e')&&(arqNome[i+3]=='o'))
      {
        return 'v';
      }
    }
  }
  return 'f';
}
