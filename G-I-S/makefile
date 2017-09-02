###Makefile###
#Autor: Matheus Augusto Marques#

objects = main.o Arquivo.o StringO.o Retangulo.o Circulo.o Svg.o \
          OpEntrada.o OperacoesF.o Lista.o Processamento.o \
          quadra.o semafaro.o torre.o hidrante.o Cidade.o Canvas.o \
          Cor.o ExecucaoGeo.o ExecucaoQry.o

dependenciasP = Processamento.h Processamento.c Arquivo.h Arquivo.c \
                StringO.h StringO.c Svg.h Svg.c \
                OpEntrada.h OpEntrada.c Lista.h Lista.c \
                Circulo.h Circulo.c Retangulo.h Retangulo.c OperacoesF.h \
                OperacoesF.c quadra.h quadra.c \
                semafaro.h semafaro.c torre.h torre.c hidrante.h hidrante.c \
                Cidade.h Cidade.c Canvas.h Canvas.c Cor.h Cor.c ExecucaoGeo.h \
                ExecucaoGeo.c ExecucaoQry.h ExecucaoQry.c

dependenciasEg = Arquivo.h Arquivo.c StringO.h StringO.c Svg.h Svg.c \
                 OpEntrada.h OpEntrada.c Lista.h Lista.c Circulo.h Circulo.c \
                 Retangulo.h Retangulo.c OperacoesF.h OperacoesF.c \
                 quadra.h quadra.c semafaro.h semafaro.c torre.h torre.c \
                 hidrante.h hidrante.c Cidade.h Cidade.c Canvas.h Canvas.c \
                 Cor.h Cor.c ExecucaoGeo.h ExecucaoGeo.c

dependenciasEq = Arquivo.h Arquivo.c StringO.h StringO.c \
                 Svg.h Svg.c OpEntrada.h OpEntrada.c Lista.h Lista.c \
                 Circulo.h Circulo.c Retangulo.h Retangulo.c \
                 OperacoesF.h OperacoesF.c quadra.h quadra.c \
                 semafaro.h semafaro.c torre.h torre.c hidrante.h hidrante.c \
                 Cidade.h Cidade.c Canvas.h Canvas.c Cor.h Cor.c ExecucaoQry.h \
                 ExecucaoQry.c

dependenciasCa = Canvas.h Canvas.c Circulo.h Circulo.c Retangulo.h Retangulo.c \
                 Lista.h Lista.c Cidade.h Cidade.c Cor.h Cor.c

dependenciasCi = Cidade.h Cidade.c Lista.h Lista.c quadra.h quadra.c \
                 hidrante.h hidrante.c semafaro.h semafaro.c torre.h torre.c

CFLAGS  = -ansi -pedantic

siguel:	$(objects)
	gcc -o siguel $(CFLAGS) $(objects) -lm

ExecucaoGeo.o: $(dependenciasEg)
	gcc -c $(CFLAGS) ExecucaoGeo.c -o ExecucaoGeo.o -lm

ExecucaoQry.o: $(dependenciasEq)
	gcc -c $(CFLAGS) ExecucaoQry.c -o ExecucaoQry.o -lm

Svg.o: Svg.h Svg.c
	gcc -c $(CFLAGS) Svg.c -o Svg.o

Lista.o: Lista.h Lista.c
	gcc -c $(CFLAGS) Lista.c -o Lista.o

StringO.o: StringO.h StringO.c
	gcc -c $(CFLAGS) StringO.c -o StringO.o

Arquivo.o: Arquivo.h Arquivo.c
	gcc -c $(CFLAGS) Arquivo.c -o Arquivo.o

Retangulo.o: Retangulo.h Retangulo.c
	gcc -c $(CFLAGS) Retangulo.c -o Retangulo.o

Circulo.o: Circulo.h Circulo.c
	gcc -c $(CFLAGS) Circulo.c -o Circulo.o

quadra.o: quadra.h quadra.c
	gcc -c $(CFLAGS) quadra.c -o quadra.o

semafaro.o: semafaro.h semafaro.c
	gcc -c $(CFLAGS) semafaro.c -o semafaro.o

torre.o: torre.h torre.c
	gcc -c $(CFLAGS) torre.c -o torre.o

Cor.o: Cor.h Cor.c
	gcc -c $(CFLAGS) Cor.c -o Cor.o

hidrante.o: hidrante.h hidrante.c
	gcc -c $(CFLAGS) hidrante.c -o hidrante.o

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
