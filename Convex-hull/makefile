### MAKEFILE  ###
### Matheus Augusto Marques ###

teste: main.o Ordination.o  Stack.o Svg.o
	gcc -o teste main.o Ordination.o  Stack.o Svg.o -lm

main.o: main.c Ordination.h Ordination.c Stack.h Stack.c Svg.h Svg.c
	gcc -c main.c -o main.o -lm -g

Ordination.o: Ordination.h Ordination.c
	gcc -c Ordination.c -o Ordination.o -g

Stack.o: Stack.h Stack.c
	gcc -c Stack.c -o Stack.o -g

Svg.o: Svg.h Svg.c
	gcc -c Svg.c -o Svg.o -g

.PHONY : clean

clean:
	rm edit *.o
