LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esercizio11.0: esercizio11.0.cpp EsperimentoPrisma.o RandomGen.o Vettore.o Gauss.o
	g++ esercizio11.0.cpp EsperimentoPrisma.o RandomGen.o Vettore.o Gauss.o -o esercizio11.0 ${INCS} ${LIBS}
RandomGen.o: RandomGen.cc RandomGen.h Gauss.h
	g++ -c RandomGen.cc -o RandomGen.o
Vettore.o: Vettore.cc Vettore.h
	g++ -c Vettore.cc -o Vettore.o
EsperimentoPrisma.o: EsperimentoPrisma.cc EsperimentoPrisma.h Gauss.o RandomGen.o Vettore.o
	g++ -c EsperimentoPrisma.cc -o EsperimentoPrisma.o ${INCS} ${LIBS}
Gauss.o: Gauss.h Gauss.cc
	g++ -c Gauss.cc -o Gauss.o
clean:
	rm *.o *.pdf *.txt
