#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "OperacoesF.h"

double distanciaEntrePontos(double x1, double y1, double x2, double y2){
    double distancia=0;
    distancia =  pow((x2 - x1), 2.0);
    distancia =  distancia + pow((y2 - y1), 2.0);
    distancia =  sqrt(distancia);
    return  distancia;
}

char verificarInteiramenteSobrepostoRR(double w1,double h1, double x1, double y1,double w2, double h2, double x2, double y2){
   char boolean='f';
    if(x1<=x2 && y1<=y2) {
        if (((x2 + w2)<= (x1 + w1)) && ((y1 + h1)>=(y2 + h2))) {
            boolean = 't';
        }
    }else if(x2<=x1 && y2<=y1) {
        if (((x1 + w1)<=(x2 + w2)) && ((y2 + h2)>=(y1 + h1))) {
            boolean = 't';
        }
    }
    return boolean;
}

char verificarInteiramenteSobrepostoRC(double w1, double h1, double x1, double y1, double r2, double x2, double y2){
    char boolean='f';
    if((x2<=(x1+w1))&&(x2>=x1)&&(y2>=y1)&&(y2<=(y1+h1))){
       if( ( fabs(x2-r2)>=x1 ) && ( fabs(x2+r2)<=(x1+w1) ) && ( fabs(y2-r2)>=y1 ) && ( fabs(y2+r2)<=(y1+h1) ) ){
           boolean = 't';
       }
    }
    return boolean;
}

char verificarInteiramenteSobrepostoCR(double w1, double h1, double x1, double y1, double r2, double x2, double y2){
    char boolean='f';
    double k1, k2, k3, k4;
    k1 = distanciaEntrePontos(x1, y1, x2, y2);
    k2 = distanciaEntrePontos(x1+w1, y1, x2, y2);
    k3 = distanciaEntrePontos(x1, y1+h1, x2, y2);
    k4 = distanciaEntrePontos(x1+w1, y1+h1, x2, y2);
    if((k1<=r2)&&(k2<=r2)&&(k3<=r2)&&(k4<=r2)){
      return 't';
    }
    return boolean;
}

char verificarInteiramenteSobrepostoCC(double r1, double x1, double y1, double r2, double x2, double y2){
    double distancia;
    if(r1>=r2){
      distancia = distanciaEntrePontos(x1, y1, x2, y2);
      distancia = distancia + r2;
      if(distancia<=r1){
        return 't';
      }
    }else{
      distancia = distanciaEntrePontos(x1, y1, x2, y2);
      distancia = distancia + r1;
      if(distancia<=r2){
        return 't';
      }
    }
    return 'f';
}

/**
 Verifica se dois retângulos estão sobrepostos. Essa verificação é feita através de comparações dos pontos bases da figura para gerar
 o resultado.
*/
char verificarSobreposicaoRR(double w1,double h1, double x1, double y1,double w2, double h2, double x2, double y2){
    char boolean='f';

    if(((x1==x2)&&(y1==y2)) || ((x1+w1==x2)&&(y1==y2)) || ((x1+w1==x2)&&(y1+h1==y2)) || ((x1==x2)&&(y1+h1==y2)))
    {
        boolean = 't';
    }
    else if(x1<=x2 && y1<=y2) {
        if ((x2 <= (x1 + w1)) && ((y1 + h1)>=y2)) {
            boolean = 't';
        }
    }else if(x1>=x2 && y1<=y2){
        if ((x1 <= (x2 + w2)) && ((y1 + h1)>=y2)) {
            boolean = 't';
        }
    }
    else if(x2<=x1 && y2<=y1) {
        if ((x1 <= (x2 + w2)) && ((y2 + h2)>=y1)) {
            boolean = 't';
        }
    }else if(x2>=x1 && y2<=y1){
        if ((x2 <= (x1 + w1)) && ((y2 + h2)>=y1)) {
            boolean = 't';
        }
    }
    return boolean;
}

/**
 Verifica se dois círculos estão sobrepostos. Essa verificação é feita através de comparações dos pontos bases da figura para gerar
 o resultado.
*/
char verificarSobreposicaoCC(double r1, double x1, double y1, double r2, double x2, double y2){
    char boolean='f';
    double distancia;

    if((x1==x2) && (y1==y2))
    {
        boolean = 't';
    }
    else
    {
        distancia = distanciaEntrePontos(x1, y1, x2, y2);
        if(distancia <= (r1+r2))
        {
            boolean = 't';
        }
    }

    return boolean;
}

/**
 Verifica se um círculo e um retângulo estão sobrepostos. Essa verificação é feita através de comparações dos pontos bases da figura para gerar
 o resultado.
*/
char verificarSobreposicaoRC(double w1, double h1, double x1, double y1, double r2, double x2, double y2){
     char boolean='f';
     if(((x1==x2)&&(y1==y2)) || ((x1+w1==x2)&&(y1==y2)) || ((x1+w1==x2)&&(y1+h1==y2)) || ((x1==x2)&&(y1+h1==y2)) )
     {
         boolean = 't';
     }
     else if((x2<=x1)&&(y2<=y1)){
         if((x2+r2)>x1 && (y2+r2)>y1){
             boolean = 't';
         }
     }
     else if((x2<=x1)&&( (y2>=y1)&&(y2<=y1+h1) ) ){
         if((x2+r2)>=x1){
             boolean = 't';
         }
     }
     else if((x2<=x1)&&(y2>=y1+h1)){
         if((x2+r2)>=x1 && (abs(y2-r2))<=(y1+h1)){
             boolean = 't';
         }
     }

     else if( (x2>=(x1+w1) )&&(y2<=y1)){
         if(( (fabs(x2-r2))<(x1+w1) )&&((y2+r2)>y1)){
             boolean = 't';
         }
     }
     else if((x2>=x1+w1)&&((y2>=y1)&&(y2<=(y1+h1)))){
         if((fabs(x2-r2))<=(x1+w1)){
             boolean = 't';
         }
     }
     else if( (x2>=x1+w1)&&( y2>=(y1+h1) ) ){
         if((fabs(x2-r2)<(x1+w1)) && (fabs(y2-r2))<=(y1+h1)){
             boolean = 't';
         }
     }
     else if((x2<=(x1+w1))&&(x2>=x1)&&(y2<=y1)){
         if((fabs(y2+r2))>=y1){
             boolean = 't';
         }
     }else if((x2<=(x1+w1))&&(x2>=x1)&&(y2>=(y1+h1))){
         if((fabs(y2-r2))<=(y1+h1)){
             boolean = 't';
         }
     }
     else if((x2<=(x1+w1))&&(x2>=x1)&&(y2>=y1)&&(y2<=(y1+h1))){
             boolean = 't';
     }


     return boolean;
}

/**
 Calcula as medidas necessárias para sobrepor dois círculos. Essas medidas são referentes as configurações de um retângulo.
*/
void sobreposicaoCC(double r1, double x1, double y1,double r2, double x2, double y2, double *w, double *h, double *x, double *y){
    double x3,y3,w3,h3,x4,y4,w4,h4;

    y3 = fabs(y1-r1);
    x3 = fabs(x1-r1);
    w3 = 2*r1;
    h3 = 2*r1;

    y4 = fabs(y2-r2);
    x4 = fabs(x2-r2);
    w4 = 2*r2;
    h4 = 2*r2;

    if(y3<=y4&&x3<=x4){
        *x = x3;
        *y = y3;
    }
    else if(y3<=y4&&x3>=x4){
        *x = x4;
        *y = y3;
    }
    else if(y3>=y4&&x3<=x4){
        *x = x3;
        *y = y4;
    }
    else if(y3>=y4&&x3>=x4){
        *x = x4;
        *y = y4;
    }

    if(w3+x3>=w4+x4)
        *w = (w3+x3)-(*x);
    else
        *w = (w4+x4)-(*x);
    if(h3+y3>=h4+y4)
        *h = (h3+y3)-(*y);
    else
        *h = (h4+y4)-(*y);

}

/**
 Calcula as medidas necessárias para sobrepor dois retângulos. Essas medidas são referentes as configurações de um retângulo.
*/
void sobreposicaoRR(double w1,double h1, double x1, double y1,double w2, double h2, double x2, double y2, double *w, double *h, double *x, double *y){

    if(y1<=y2&&x1<=x2){
        *x = x1;
        *y = y1;
    }
    else if(y1<=y2&&x1>=x2){
        *x = x2;
        *y = y1;
    }
    else if(y1>=y2&&x1<=x2){
        *x = x1;
        *y = y2;
    }
    else if(y1>=y2&&x1>=x2){
        *x = x2;
        *y = y2;
    }

    if(w1+x1>=w2+x2)
        *w = (w1+x1)-(*x);
    else
        *w = (w2+x2)-(*x);
    if(h1+y1>=h2+y2)
        *h = (h1+y1)-(*y);
    else
        *h = (h2+y2)-(*y);

}

/**
 Calcula as medidas necessárias para sobrepor um círculo e um retângulo. Essas medidas são referentes as configurações de um retângulo.
*/
void sobreposicaoRC(double w1, double h1, double x1, double y1, double r2, double x2, double y2, double *w, double *h, double *x, double *y){
    double x3,y3,w3,h3;

    y3 = fabs(y2-r2);
    x3 = fabs(x2-r2);
    w3 = 2*r2;
    h3 = 2*r2;

    if(y1<=y3&&x1<=x3){
        *x = x1;
        *y = y1;
    }
    else if(y1<=y3&&x1>=x3){
        *x = x3;
        *y = y1;
    }
    else if(y1>=y3&&x1<=x3){
        *x = x1;
        *y = y3;
    }
    else if(y1>=y3&&x1>=x3){
        *x = x3;
        *y = y3;
    }

    if(w1+x1>=w3+x3)
        *w = (w1+x1)-(*x);
    else
        *w = (w3+x3)-(*x);
    if(h1+y1>=h3+y3)
        *h = (h1+y1)-(*y);
    else
        *h = (h3+y3)-(*y);

}

/**
 Calcula através de comparação se um ponto qualquer é interno a um retângulo.
*/
char pontoInternoR(double w, double h, double x1, double y1, double x2, double y2){
    char boolean='f';
    if((x2>=x1) && (x2<=x1+w) && (y2>=y1) && (y2<=y1+h))
    {
        boolean = 't';
    }

    return boolean;
}

/**
 Calcula através de comparação se um ponto qualquer é interno a um circulo.
*/
char pontoInternoC(double r, double x1, double y1, double x2, double y2){
    char boolean='f';
    double distancia = distanciaEntrePontos(x1, y1, x2, y2);
    if((distancia == 0.0) || (distancia < r))
    {
        boolean = 't';
    }
    return boolean;
}
