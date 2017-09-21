#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argv, char *argc[]){
  int i, j, n;
  double k;
  srand(time(NULL));
  FILE *file;
  file = fopen(argc[1], "w");
  n = rand() % 100 + 10;
  fprintf(file, "%d\n", n);
  for (i=0; i < n; i++)
  {
    j = 0;
    fprintf(file, "%c ", 'p');
    while(j < 3){
      k = rand() % 250;
      fprintf(file, "%lf ", k);
      j++;
    }
    fprintf(file, "%c", '\n');
  }
  return 0;
}
