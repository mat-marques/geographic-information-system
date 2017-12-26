#					Makefile
#		Autor: Matheus Augusto Marques

objects = Arquivo.o Cidade.o Canvas.o Celular.o Circulo.o \
					ConvexHull.o Cor.o Dicionario.o Endereco.o \
					EstabelecimentoComercial.o ExecucaoEcPmTm.o ExecucaoGeo.o \
					ExecucaoQry.o ExecucaoQry2.o HashTable.o Hidrante.o \
					List.o main.o Morador.o OpEntrada.o OperacoesF.o \
					Ordination.o Pessoa.o Processamento.o Quadra.o QuadTree.o \
					Retangulo.o Semafaro.o Stack.o StringO.o Svg.o Torre.o


dependenciasP = Processamento.h Processamento.c Arquivo.h Arquivo.c \
                StringO.h StringO.c Svg.h Svg.c \
                OpEntrada.h OpEntrada.c List.h List.c \
                Circulo.h Circulo.c Retangulo.h Retangulo.c \
                OperacoesF.h OperacoesF.c Quadra.h Quadra.c \
                Semafaro.h Semafaro.c Torre.h Torre.c \
                Hidrante.h Hidrante.c Cidade.h Cidade.c \
                Canvas.h Canvas.c ExecucaoGeo.h ExecucaoGeo.c \
				ExecucaoQry.h ExecucaoQry.c QuadTree.h QuadTree.c Cor.h Cor.c \
				Dicionario.h Dicionario.c ExecucaoEcPmTm.h ExecucaoEcPmTm.c \
				ExecucaoQry2.h ExecucaoQry2.c HashTable.h HashTable.c

dependenciasEg = Arquivo.h Arquivo.c StringO.h StringO.c Svg.h Svg.c \
                 OpEntrada.h OpEntrada.c Circulo.h Circulo.c \
				 List.h List.c Cor.h Cor.c Stack.h Stack.c \
                 Retangulo.h Retangulo.c OperacoesF.h OperacoesF.c \
                 Quadra.h Quadra.c Semafaro.h Semafaro.c Torre.h Torre.c \
                 Hidrante.h Hidrante.c Cidade.h Cidade.c Canvas.h Canvas.c \
                 ExecucaoGeo.h ExecucaoGeo.c ConvexHull.h ConvexHull.c \
				 QuadTree.h QuadTree.c HashTable.h HashTable.c

dependenciasEq = Arquivo.h Arquivo.c StringO.h StringO.c \
                 Svg.h Svg.c OpEntrada.h OpEntrada.c \
				 List.h List.c QuadTree.h QuadTree.c \
                 Circulo.h Circulo.c Retangulo.h Retangulo.c \
                 OperacoesF.h OperacoesF.c Quadra.h Quadra.c \
                 Semafaro.h Semafaro.c Torre.h Torre.c \
				 Hidrante.h Hidrante.c Cor.h Cor.c \
                 Cidade.h Cidade.c Canvas.h Canvas.c \
				 ExecucaoQry.h ExecucaoQry.c ConvexHull.h ConvexHull.c


dependenciasCa = Canvas.h Canvas.c Circulo.h Circulo.c \
			     Retangulo.h Retangulo.c List.h \
 			     List.c Cidade.h Cidade.c \
 			     ConvexHull.h ConvexHull.c OperacoesF.h OperacoesF.c \
 			     QuadTree.h QuadTree.c

dependenciasCi = Cidade.h Cidade.c Quadra.h Quadra.c\
				 List.h List.c Pessoa.h Pessoa.c\
   				 Hidrante.h Hidrante.c Semafaro.h Semafaro.c \
				 Torre.h Torre.c QuadTree.h QuadTree.c Svg.h Svg.c \
 			 	 ConvexHull.h ConvexHull.c Stack.h Stack.c \
				 EstabelecimentoComercial.h EstabelecimentoComercial.c \
				 Dicionario.h Dicionario.c Endereco.h Endereco.c \
				 HashTable.h HashTable.c Celular.h Celular.c \
				 Morador.h Morador.c StringO.h StringO.c

dependenciasCh = ConvexHull.h ConvexHull.c Quadra.h Quadra.c \
 				 Hidrante.h Hidrante.c Semafaro.h Semafaro.c \
 				 Torre.h Torre.c Circulo.h Circulo.c \
 				 Retangulo.h Retangulo.c Ordination.h Ordination.c \
 				 QuadTree.h QuadTree.c Stack.h Stack.c \
 				 Svg.h Svg.c OperacoesF.h OperacoesF.c

dependenciasEcPmTm = ExecucaoEcPmTm.h ExecucaoEcPmTm.c StringO.h StringO.c \
					 Cidade.h Cidade.c Pessoa.h Pessoa.c Endereco.h Endereco.c \
					 EstabelecimentoComercial.h EstabelecimentoComercial.c \
					 HashTable.h HashTable.c Morador.h Morador.c \
					 Dicionario.h Dicionario.c Celular.h Celular.c \
					 Canvas.h Canvas.c

dependenciasEq2 = ExecucaoQry2.h ExecucaoQry2.c Canvas.h Canvas.c \
				  OperacoesF.h OperacoesF.c Cidade.h Cidade.c \
				  Endereco.h Endereco.c Pessoa.h Pessoa.c \
				  EstabelecimentoComercial.h EstabelecimentoComercial.c \
				  Hidrante.h Hidrante.c List.h List.c Morador.h Morador.c \
				  Quadra.h Quadra.c Retangulo.h Retangulo.c \
				  Semafaro.h Semafaro.c StringO.h StringO.c \
				  Torre.h Torre.c HashTable.h HashTable.c


CFLAGS  = -g -ansi -pedantic

siguel:	$(objects)
	gcc -o siguel $(CFLAGS) $(objects) -lm


HashTable.o: HashTable.h HashTable.c List.h List.c
	gcc -c $(CFLAGS) HashTable.c -o HashTable.o


Endereco.o: Endereco.c Endereco.h StringO.h StringO.c
	gcc -c $(CFLAGS) Endereco.c -o Endereco.o


Morador.o: Morador.h Morador.c Endereco.h Endereco.c StringO.h StringO.c
	gcc -c $(CFLAGS) Morador.c -o Morador.o


EstabelecimentoComercial.o: EstabelecimentoComercial.c EstabelecimentoComercial.h Endereco.h Endereco.c StringO.h StringO.c
	gcc -c $(CFLAGS) EstabelecimentoComercial.c -o EstabelecimentoComercial.o


Pessoa.o: Pessoa.h Pessoa.c Celular.h Celular.c StringO.h StringO.c
	gcc -c $(CFLAGS) Pessoa.c -o Pessoa.o


Celular.o: Celular.h Celular.c Pessoa.h Pessoa.c StringO.h StringO.c
	gcc -c $(CFLAGS) Celular.c -o Celular.o


Dicionario.o: Dicionario.h Dicionario.c HashTable.h HashTable.c List.h List.c
	gcc -c $(CFLAGS) Dicionario.c -o Dicionario.o



ExecucaoEcPmTm.o: $(dependenciasEcPmTm)
	gcc -c $(CFLAGS) ExecucaoEcPmTm.c -o ExecucaoEcPmTm.o



ExecucaoGeo.o: $(dependenciasEg)
	gcc -c $(CFLAGS) ExecucaoGeo.c -o ExecucaoGeo.o -lm


ExecucaoQry.o: $(dependenciasEq)
	gcc -c $(CFLAGS) ExecucaoQry.c -o ExecucaoQry.o -lm


ExecucaoQry2.o: $(dependenciasEq2)
	gcc -c $(CFLAGS) ExecucaoQry2.c -o ExecucaoQry2.o -lm


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


Quadra.o: Quadra.h Quadra.c StringO.h StringO.c
	gcc -c $(CFLAGS) Quadra.c -o Quadra.o


Semafaro.o: Semafaro.h Semafaro.c StringO.h StringO.c
	gcc -c $(CFLAGS) Semafaro.c -o Semafaro.o


Torre.o: Torre.h Torre.c StringO.h StringO.c
	gcc -c $(CFLAGS) Torre.c -o Torre.o


Hidrante.o: Hidrante.h Hidrante.c StringO.h StringO.c
	gcc -c $(CFLAGS) Hidrante.c -o Hidrante.o


OperacoesF.o: OperacoesF.h OperacoesF.c
	gcc -c $(CFLAGS) OperacoesF.c -o OperacoesF.o -lm


OpEntrada.o: OpEntrada.h OpEntrada.c StringO.h StringO.c
	gcc -c $(CFLAGS) OpEntrada.c -o OpEntrada.o


Canvas.o: $(dependenciasCa)
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
