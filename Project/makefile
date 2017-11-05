#								Makefile
#		Autor: Matheus Augusto Marques

objects = main.o Arquivo.o StringO.o Retangulo.o Circulo.o Svg.o \
          OpEntrada.o OperacoesF.o List.o Processamento.o \
          Quadra.o Semafaro.o Torre.o Hidrante.o Cidade.o Canvas.o \
 		  		ExecucaoGeo.o ExecucaoQry.o QuadTree.o ConvexHull.o Stack.o \
					Ordination.o Cor.o

dependenciasP = Processamento.h Processamento.c Arquivo.h Arquivo.c \
                StringO.h StringO.c Svg.h Svg.c \
                OpEntrada.h OpEntrada.c List.h List.c \
                Circulo.h Circulo.c Retangulo.h Retangulo.c \
                OperacoesF.h OperacoesF.c Quadra.h Quadra.c \
                Semafaro.h Semafaro.c Torre.h Torre.c \
                Hidrante.h Hidrante.c Cidade.h Cidade.c \
                Canvas.h Canvas.c ExecucaoGeo.h ExecucaoGeo.c \
								ExecucaoQry.h ExecucaoQry.c QuadTree.h QuadTree.c Cor.h Cor.c

dependenciasEg = Arquivo.h Arquivo.c StringO.h StringO.c Svg.h Svg.c \
                 OpEntrada.h OpEntrada.c Circulo.h Circulo.c \
								 List.h List.c  \
                 Retangulo.h Retangulo.c OperacoesF.h OperacoesF.c \
                 Quadra.h Quadra.c Semafaro.h Semafaro.c Torre.h Torre.c \
                 Hidrante.h Hidrante.c Cidade.h Cidade.c Canvas.h Canvas.c \
                 ExecucaoGeo.h ExecucaoGeo.c ConvexHull.h ConvexHull.c \
								 QuadTree.h QuadTree.c

dependenciasEq = Arquivo.h Arquivo.c StringO.h StringO.c \
                 Svg.h Svg.c OpEntrada.h OpEntrada.c \
				 			 	 List.h List.c \
                 Circulo.h Circulo.c Retangulo.h Retangulo.c \
                 OperacoesF.h OperacoesF.c Quadra.h Quadra.c \
                 Semafaro.h Semafaro.c Torre.h Torre.c \
				 			   Hidrante.h Hidrante.c Cor.h Cor.c \
                 Cidade.h Cidade.c Canvas.h Canvas.c \
				 			   ExecucaoQry.h ExecucaoQry.c ConvexHull.h ConvexHull.c \
								 QuadTree.h QuadTree.c

dependenciasCa = Canvas.h Canvas.c Circulo.h Circulo.c \
			           Retangulo.h Retangulo.c List.h \
				 			   List.c Cidade.h Cidade.c \
				 			   ConvexHull.h ConvexHull.c OperacoesF.h OperacoesF.c \
				 			   QuadTree.h QuadTree.c

dependenciasCi = Cidade.h Cidade.c Quadra.h Quadra.c\
				 				 List.h List.c \
   				 			 Hidrante.h Hidrante.c Semafaro.h Semafaro.c \
						     Torre.h Torre.c QuadTree.h QuadTree.c Svg.h Svg.c \
				 			 	 ConvexHull.h ConvexHull.c Stack.h Stack.c

dependenciasCh = ConvexHull.h ConvexHull.c Quadra.h Quadra.c \
				 				 Hidrante.h Hidrante.c Semafaro.h Semafaro.c \
				 				 Torre.h Torre.c Circulo.h Circulo.c \
				 				 Retangulo.h Retangulo.c Ordination.h Ordination.c \
				 				 QuadTree.h QuadTree.c Stack.h Stack.c \
				 				 Svg.h Svg.c OperacoesF.h OperacoesF.c

CFLAGS  = -ansi -pedantic -g

siguel:	$(objects)
	gcc -o siguel $(CFLAGS) $(objects) -lm


ExecucaoGeo.o: $(dependenciasEg)
	gcc -c $(CFLAGS) ExecucaoGeo.c -o ExecucaoGeo.o -lm


ExecucaoQry.o: $(dependenciasEq)
	gcc -c $(CFLAGS) ExecucaoQry.c -o ExecucaoQry.o -lm


Svg.o: Svg.h Svg.c
	gcc -c $(CFLAGS) Svg.c -o Svg.o


Stack.o: Stack.h Stack.c
	gcc -c $(CFLAGS) Stack.c -o Stack.o


QuadTree.o: QuadTree.h QuadTree.c List.h List.c
	gcc -c $(CFLAGS) QuadTree.c -o QuadTree.o


List.o: List.h List.c
	gcc -c $(CFLAGS) List.c -o List.o


Ordination.o: Ordination.h Ordination.c
	gcc -c $(CFLAGS) Ordination.c -o Ordination.o -lm


ConvexHull.o: $(dependenciasCh)
	gcc -c $(CFLAGS) ConvexHull.c -o ConvexHull.o


StringO.o: StringO.h StringO.c
	gcc -c $(CFLAGS) StringO.c -o StringO.o


Cor.o: Cor.h Cor.c
	gcc -c $(CFLAGS) Cor.c -o Cor.o


Arquivo.o: Arquivo.h Arquivo.c
	gcc -c $(CFLAGS) Arquivo.c -o Arquivo.o


Retangulo.o: Retangulo.h Retangulo.c
	gcc -c $(CFLAGS) Retangulo.c -o Retangulo.o


Circulo.o: Circulo.h Circulo.c
	gcc -c $(CFLAGS) Circulo.c -o Circulo.o


Quadra.o: Quadra.h Quadra.c
	gcc -c $(CFLAGS) Quadra.c -o Quadra.o


Semafaro.o: Semafaro.h Semafaro.c
	gcc -c $(CFLAGS) Semafaro.c -o Semafaro.o


Torre.o: Torre.h Torre.c
	gcc -c $(CFLAGS) Torre.c -o Torre.o


Hidrante.o: Hidrante.h Hidrante.c
	gcc -c $(CFLAGS) Hidrante.c -o Hidrante.o


OperacoesF.o: OperacoesF.h OperacoesF.c
	gcc -c $(CFLAGS) OperacoesF.c -o OperacoesF.o -lm


OpEntrada.o: OpEntrada.h OpEntrada.c StringO.h StringO.c
	gcc -c $(CFLAGS) OpEntrada.c -o OpEntrada.o


Canvas.o:	$(dependenciasCa)
	gcc -c $(CFLAGS) Canvas.c -o Canvas.o


Cidade.o: $(dependenciasCi)
	gcc -c $(CFLAGS) Cidade.c -o Cidade.o


Processamento.o: $(dependenciasP)
	gcc -c $(CFLAGS) Processamento.c -o Processamento.o -lm


main.o:	main.c Processamento.h Processamento.c
	gcc -c $(CFLAGS) main.c -o main.o -lm



.PHONY : clean

clean:
	rm edit *.o
