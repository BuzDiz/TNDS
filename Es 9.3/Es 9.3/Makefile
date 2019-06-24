LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esercizio9.3: esercizio9.3.cpp Vettore.o VettoreLineare.o EquazioniDifferenziali.o
	g++ esercizio9.3.cpp Vettore.o VettoreLineare.o EquazioniDifferenziali.o -o esercizio9.3 ${INCS} ${LIBS}
Vettore.o: Vettore.cc Vettore.h
	g++ -c Vettore.cc -o Vettore.o
VettoreLineare.o: VettoreLineare.cc VettoreLineare.h Vettore.o
	g++ -c VettoreLineare.cc -o VettoreLineare.o
EquazioniDifferenziali.o: EquazioniDifferenziali.cc EquazioniDifferenziali.h VettoreLineare.o
	g++ -c EquazioniDifferenziali.cc -o EquazioniDifferenziali.o

clean:
	rm *.o *.x
