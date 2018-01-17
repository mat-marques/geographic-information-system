#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Texto.h"
#include "StringO.h"

typedef struct myText{
  char *text, *colour, *fontFamily;
  double x, y;
  int fontSize, id;
} newText;


Text createText(int id, char *text, double x, double y){
  newText *myText = NULL;
  char colour1[] = "red", family[] = "Arial";
  myText = (newText*) malloc(sizeof(newText));
  if(myText != NULL){
    myText->id = id;
    myText->text = criarString(text);
    myText->x = x;
    myText->y = y;
    myText->colour = criarString(colour1);
    myText->fontFamily = criarString(family);
    myText->fontSize = 5;
  }
  return myText;
}


int getIdText(Text text){
  newText *myText = (newText*) text;
  if (text != NULL) {
    return myText->id;
  }
  return 0;
}


void setIdText(Text text, int id){
  newText *myText = (newText*) text;
  if (text != NULL) {
    myText->id = id;
  }
}


char *getText(Text text){
  newText *myText = (newText*) text;
  if (text != NULL) {
    return myText->text;
  }
  return NULL;
}


void setText(Text text, char *nText){
  newText *myText = (newText*) text;
  if (text != NULL) {
    if (myText->text != NULL) {
      free(myText->text);
    }
    myText->text = criarString(nText);
  }
}


double getXText(Text text){
  newText *myText = (newText*) text;
  if (text != NULL) {
    return myText->x;
  }
  return 0;
}


void setXText(Text text, double x){
  newText *myText = (newText*) text;
  if (text != NULL) {
    myText->x = x;
  }
}


double getYText(Text text){
  newText *myText = (newText*) text;
  if (text != NULL) {
    return myText->y;
  }
  return 0;
}


void setYText(Text text, double y){
  newText *myText = (newText*) text;
  if (text != NULL) {
    myText->y = y;
  }
}


char *getColourText(Text text){
  newText *myText = (newText*) text;
  if (text != NULL) {
    return myText->colour;
  }
  return NULL;
}


void setColourText(Text text, char *colour){
  newText *myText = (newText*) text;
  if (text != NULL) {
    if (myText->colour != NULL) {
      free(myText->colour);
    }
    myText->colour = criarString(colour);
  }
}


char *getFontFamilyText(Text text){
  newText *myText = (newText*) text;
  if (text != NULL) {
    return myText->fontFamily;
  }
  return NULL;
}


void setFontFamilyText(Text text, char *fontFamily){
  newText *myText = (newText*) text;
  if (text != NULL) {
    if (myText->fontFamily != NULL) {
      free(myText->fontFamily);
    }
    myText->fontFamily = criarString(fontFamily);
  }
}


int getFontSizeText(Text text){
  newText *myText = (newText*) text;
  if (text != NULL) {
    return myText->fontSize;
  }
  return 0;
}


void setFontSizeText(Text text, int fontSize){
  newText *myText = (newText*) text;
  if (text != NULL) {
    myText->fontSize = fontSize;
  }
}


int compareText(Text text, void *id){
  newText *myText = (newText*) text;
  int *myId = (int *)id;
  if (myText->id == *myId) {
    return 1;
  }
  return 0;
}


void eraseText(Text text){
  newText *myText = (newText*) text;
  if(text != NULL){
    if(myText->text != NULL){
      free(myText->text);
    }
    if(myText->colour != NULL){
      free(myText->colour);
    }
    if(myText->fontFamily != NULL){
      free(myText->fontFamily );
    }
    free(myText);
  }
}
