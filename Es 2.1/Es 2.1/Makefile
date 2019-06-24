esercizio2.1: esercizio2.1.o Vettore.o funzioni.o
	g++ esercizio2.1.o Vettore.o funzioni.o -o esercizio2.1
funzioni.o: funzioniVett.cc funzioni.h
	g++ -c funzioniVett.cc -o funzioni.o
esercizio2.1.o: esercizio2.1.cpp funzioni.h
	g++ -c esercizio2.1.cpp -o esercizio2.1.o
Vettore.o: Vettore.cc Vettore.h
	g++ -c Vettore.cc -o Vettore.o

clean:
	rm *.o
cleanall: clean
	rm esercizio2.1