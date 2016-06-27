prog:	Main.o Arquivo.o Atividade.o Cliente.o Empresa.o Validacao.o OrdemDeServico.o 
	gcc -o prog Main.o Arquivo.o Atividade.o Cliente.o Empresa.o Validacao.o OrdemDeServico.o

Main.o:	Main.c
	gcc -c Main.c

Arquivo.o:	Arquivo.c	Arquivo.h
	gcc -c Arquivo.c

Atividade.o:	Atividade.c	Atividade.h
	gcc -c Atividade.c

Cliente.o:	Cliente.c	Cliente.h
	gcc -c Cliente.c

Empresa.o:	Empresa.c	Empresa.h
	gcc -c Empresa.c

Validacao.o:	Validacao.c	Validacao.h
	gcc -c Validacao.c

OrdemDeServico.o:	OrdemDeServico.c	OrdemDeServico.h
	gcc -c OrdemDeServico.c

clean:
	rm *.o
