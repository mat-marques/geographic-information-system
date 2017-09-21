#include<stdio.h>
#include<stdlib.h>
#include "Ordination.h"
#include "Svg.h"
#include "Stack.h"
#include<math.h>

typedef struct S{
  double x, y;
  int id;
}S;

S *p0;

/*Aloca um vetor ou variavel do tipo S. Função necessária para a pilha.*/
void *alocar(int qtd){
  S *s1 = (S*) malloc(qtd * sizeof(S));
  return s1;
}

/*Desaloca a variavel item. Função necessária para a pilha.*/
void desalocar(void* item){
  S *s1 = (S*) item;
  free(s1);
}

/*Função que atribui os valores de valor para valor. Função necessária para a pilha.*/
void atribuir(void* valor1, int p1, void* valor2, int p2){
  S *s1 = (S*) valor1;
  S *s2 = (S*) valor2;
  (s1 + p1)->id = (s2 + p2)->id;
  (s1 + p1)->x = (s2 + p2)->x;
  (s1 + p1)->y = (s2 + p2)->y;
}

/*Encontra o menor elemento dentro de um conjunto de pontos.*/
S *menorPonto(S *s, int qtd){
  int i;
  double y, x;
  S *s1;
  y = s->y;
  x = s->x;
  for(i=1; i<qtd; i++){
    /*Encontra o menor y*/
    if((s + i)->y < y){
      y = (s + i)->y;
      x = (s + i)->x;
      s1 = (s + i);
    }
    /*Caso dois pontos tenha o mesmo y, então o ponto que possuir o menor x e selecionado.*/
    if((s + i)->y == y && (s + i)->x < x){
      y = (s + i)->y;
      x = (s + i)->x;
      s1 = (s + i);
    }
  }
  /*Coloca o menor ponto no inicio do vetor*/
  x = s1->x;
  y = s1->y;
  i = s1->id;
  s1->x = s->x;
  s1->y = s->y;
  s1->id = s->id;
  s->x = x;
  s->y = y;
  s->id = i;
  s1 = s;
  return s1;
}

/*Retorna um elemento abaixo do topo da pilha*/
S *nextToTop(Stack pilha){
    S *p1 = (S*)removeTopI(pilha);
    S *p2 = (S*)getItemTop(pilha);
    insertTop(pilha, -1, p1);
    return p2;
}

/*Função utilizada para encontra a distancia quadrada de dois pontos*/
int dist(S* p1, S* p2){
  return (p1->x - p2->x) * (p1->x - p2->x) + (p1->y - p2->y) * (p1->y - p2->y);
}

/*Calcula a orientação de três pontos.*/
double orientation(S* p, S* q, S* r){
  int val = (q->y - p->y) * (r->x - q->x) - (q->x - p->x) * (r->y - q->y);
  /*Caseo val == 0 os pontos são colineares*/
  if (val == 0){
    return 0;
  }
  /*caso val > 0 os pontos fazem uma curva para a esquerda.*/
  /*caso val < 0 os pontos fazem uma curva para a direita.*/
  return (val > 0) ? 1 : 2;
}

/*Função utilizada para ordenar o vetor de pontos. Função necessária para o mergeSort.*/
int comparar(void* valor1, int p1, void* valor2, int p2){
  S *s1 = (S*) valor1;
  S *s2 = (S*) valor2;
  int o = orientation(p0, (s1 + p1), (s2 + p2));
  if (o == 0){
    return (dist(p0, (s2 + p2)) >= dist(p0, (s1 + p1))) ? -1 : 1;
  }
  return (o == 2) ? -1 : 1;
}

/*Calcula os vertices do polígono convexo.*/
Stack convexHull(S *vetor, int n){
  int i;
  Stack pilha;
  pilha = createStack();

  /*Encontra o menor y no conjunto de pontos*/
  p0 = menorPonto(vetor, n);

  /*Ordena o vetor da posicão 1 até n. A posição inicial e o menor y.*/
  mergeSort(vetor+1, 0, n-2, alocar, desalocar, comparar, atribuir);

  /* Coloca na pilha vetor[0] */
  S *A = (S*) malloc(sizeof(S));
  atribuir(A, 0, vetor, 0);
  insertTop(pilha, -1, A);

  /* Coloca na pilha vetor[1] */
  A = (S*) malloc(sizeof(S));
  atribuir(A, 0, vetor, 1);
  insertTop(pilha, -1, A);

  /* Coloca na pilha vetor[2] */
  A = (S*) malloc(sizeof(S));
  atribuir(A, 0, vetor, 2);
  insertTop(pilha, -1, A);

  /*Comparação entre os pontos*/
  for (i = 3; i < n; i++){
    /*Continua removendo os pontos da pilha enquanto os três pontos não fazem uma curva para a esquerda.*/
    while (orientation(nextToTop(pilha), (S*) getItemTop(pilha), (vetor + i)) != 2){
      removeTop(pilha, desalocar);
    }
    A = (S*) malloc(sizeof(S));
    atribuir(A, 0, vetor, i);
    insertTop(pilha, -1, A);
  }
  /*Coloca na pilha o elemento inicial do vetor(vetor[0])*/
  A = (S*) malloc(sizeof(S));
  atribuir(A, 0, vetor, 0);
  insertTop(pilha, -1, A);
 return pilha;
}

int main(int argv, char *argc[]) {
  FILE *file, *fileSvg;
  int i, j=0, n;
  double x, y;
  char p;
  char cor[] = "red";
  char cor2[] = "black";
  Stack pilha;
  S *s = NULL;
  S *P;
  file = fopen(argc[1], "r");
  fscanf(file, "%d\n", &n);
  s = (S*) malloc(n * sizeof(S));
  while(1){
    if(feof(file)){
      break;
    }
    fscanf(file, "%c %lf %lf %d\n", &p, &x, &y, &i);
    if(p == 'p'){
      (s + j)->id = i;
      (s + j)->x = x;
      (s + j)->y = y;
      j++;
    }
  }

  pilha = convexHull(s, n);

  fileSvg = createSvg(argc[2]);
  tagAbertura(fileSvg, 300, 300);

  for(i=0; i<n; i++){
    printf("Ordenacao = %d %lf %lf\n", (s + i)->id, (s + i)->x, (s + i)->y);
    pontos(fileSvg, (s + i)->x, (s + i)->y, cor);
  }

  printf("size = %d\n", lengthStack(pilha));
  while(lengthStack(pilha)>1){
    P = (S*) getItemTop(pilha);
    x = P->x;
    y = P->y;
    removeTop(pilha, desalocar);
    P = (S*) getItemTop(pilha);
    linha(fileSvg, x, y, P->x, P->y, cor2);
  }
  eraseStack(pilha, desalocar);
  tagFechamento(fileSvg);
  fclose(fileSvg);
  free(s);
  fclose(file);
  return 0;
}
