#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "StringO.h"
#include "OpEntrada.h"

/**
retorna uma string que é passada como parâmetro -f para a main.
A string é associada a um arquivo de entrada.
*/
char *parametroF(char **argv, int argc){
  int i;
  char *new0=NULL;
  for(i=1; i<argc; i++){
    if(strcmp(argv[i],"-f")==0)
    {
      new0 = concatenarStrings(new0, *(argv+i+1));
      break;
    }
  }
  return new0;

}

/**
retorna uma string que é passada como parâmetro -o para a main.
A string é associada um diretório.
*/
char *parametroO(char **argv, int argc){
  int i;
  char *new0=NULL;
  for(i=1; i<argc; i++){
    if(strcmp(argv[i],"-o")==0)
    {
      new0 = concatenarStrings(new0,*(argv+i+1));
      break;
    }
  }
  return new0;
}


char *parametroE(char **argv, int argc){
  int i;
  char *new0=NULL;
  for(i=1; i<argc; i++){
    if(strcmp(argv[i],"-e")==0)
    {
      new0 = concatenarStrings(new0, *(argv+i+1));
    }
  }

  return new0;
}

char parametroAcc0(char **argv, int argc){
  int i;
  for(i=1; i<argc; i++){
    if(strcmp(argv[i],"-acc0")==0)
    {
      return 't';
    }
  }

  return 'f';
}

char parametroAcc(char **argv, int argc){
  int i;
  for(i=1; i<argc; i++){
    if(strcmp(argv[i],"-acc")==0)
    {
      return 't';
    }
  }

  return 'f';
}

char *parametroQ(char **argv, int argc){
  int i;
  char *new0=NULL;
  for(i=1; i<argc; i++){
    if(strcmp(argv[i],"-q")==0)
    {
      new0 = concatenarStrings(new0, *(argv+i+1));
      break;
    }
  }
  return new0;
}

void parametroId(char **argv, int argc){
  int i;
  for(i=1; i<argc; i++){
    if(strcmp(argv[i],"-id")==0)
    {
      printf("Nome: Matheus Augusto Marques.\n");
      printf("Numero de matricula: 201600560273.\n");
    }
  }
}


char *nomeArquivo(char *parametro){
  char *newString0=NULL;
  int tamanho;
  int i,j=-1, k=0;

  if(parametro!=NULL){
    tamanho = strlen(parametro);
    for(i=0;i<tamanho;i++){
      if(parametro[i]=='/'){
        j=i;
      }
    }
    if(j==-1){
      k=0;
    }else{
      k = j;
    }
    newString0 = (char*) malloc((tamanho-k+2) * sizeof(char));
    if(newString0==NULL){
      printf("ERRO EM ALOCACAO DE MEMORIA.\n");
      exit(0);
    }
    j++;
    k = 0;
    for(i=j;i<tamanho;i++){
      if((i+3)<tamanho){
        if((parametro[i]=='.'&&parametro[i+1]=='g'&&parametro[i+2]=='e'&&parametro[i+3]=='o')||(parametro[i]=='.'&&parametro[i+1]=='q'&&parametro[i+2]=='r'&&parametro[i+3]=='y')){
          break;
        }
      }
      newString0[k] = parametro[i];
      k++;
    }
    newString0[k]='\0';
  }
  return newString0;
}


char *concatenarElementos(char *dirPath, char *arqNome, char *extensao){
  char *newString0=NULL, *aux=NULL, *string1=NULL;
  int i;
  char barra = verificarBarra(arqNome, dirPath);
  if(barra=='1'||barra=='2'){
    string1 = concatenarStrings(arqNome, extensao);
    newString0 = concatenarStrings(dirPath, string1);
    free(string1);
  } else
  if(barra=='3'){
    i = strlen(dirPath);
    string1 = concatenarStrings(string1, dirPath);
    string1[i-1] = '\0';
    newString0 = concatenarStrings(string1, arqNome);
    free(string1);
  }else
  if(barra=='4'){
    newString0 = colocarBarra(dirPath);
    aux = newString0;
    string1 = concatenarStrings(arqNome, extensao);
    newString0 = concatenarStrings(aux, string1);
    free(aux);
    free(string1);
  }else
  if(barra=='5'){
    i = strlen(arqNome) - 1;
    string1 = newStringElement(arqNome, i, 1);
    newString0 = concatenarElementos(dirPath, string1, extensao);
    free(string1);
  }else
  if(barra=='6'){
    i = strlen(arqNome) - 1;
    string1 = newStringElement(arqNome, i, 2);
    newString0 = concatenarElementos(dirPath, string1, extensao);
    free(string1);
  }else
  if(barra=='7'){
    i = strlen(arqNome) - 2;
    string1 = newStringElement(arqNome, i, 2);
    newString0 = concatenarElementos(dirPath, string1, extensao);
    free(string1);
  }else
  if(barra=='8'){
    i = strlen(arqNome) - 2;
    string1 = newStringElement(arqNome, i, 3);
    newString0 = concatenarElementos(dirPath, string1, extensao);
    free(string1);
  }
    return newString0;
}

char *concatenarElementos2(char *dirPath, char *arqNome){
  char *newString0=NULL, *aux=NULL, *string1=NULL;
  int i;
  char barra = verificarBarra(arqNome, dirPath);

  if(barra=='1'||barra=='2'){
    newString0 = concatenarStrings(dirPath, arqNome);
    free(string1);
  } else
  if(barra=='3'){
    i = strlen(dirPath);
    string1 = concatenarStrings(string1, dirPath);
    string1[i-1] = '\0';
    newString0 = concatenarStrings(string1, arqNome);
    free(string1);
  }else
  if(barra=='4'){
    newString0 = colocarBarra(dirPath);
    aux = newString0;
    newString0 = concatenarStrings(aux, arqNome);
    free(aux);
    free(string1);
  }else
  if(barra=='5'){
    i = strlen(arqNome) - 1;
    string1 = newStringElement(arqNome, i+1, 1);
    newString0 = concatenarStrings(dirPath, string1);
    free(string1);
  }else
  if(barra=='6'){
    i = strlen(arqNome) - 1;
    string1 = newStringElement(arqNome, i+1, 2);
    newString0 = concatenarStrings(dirPath, string1);
    free(string1);
  }else
  if(barra=='7'){
    i = strlen(arqNome) - 1;
    string1 = newStringElement(arqNome, i, 2);
    newString0 = concatenarStrings(dirPath, string1);
    free(string1);
  }else
  if(barra=='8'){
    i = strlen(arqNome) - 1;
    string1 = newStringElement(arqNome, i, 3);
    newString0 = concatenarStrings(dirPath, string1);
    free(string1);
  }

  return newString0;
}
