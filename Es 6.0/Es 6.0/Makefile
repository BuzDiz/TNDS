LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esercizio6.0: esercizio6.0.cpp Campovettoriale.o Puntomateriale.o Particella.o Posizione.o
	g++ esercizio6.0.cpp Campovettoriale.o Puntomateriale.o Particella.o Posizione.o -o esercizio6.0 ${INCS} ${LIBS}
Posizione.o: Posizione.cc Posizione.h
	g++ -c Posizione.cc -o Posizione.o
Particella.o: Particella.cc Particella.h Posizione.h
	g++ -c Particella.cc -o Particella.o
Campovettoriale.o: CampoVettoriale.cc CampoVettoriale.h Posizione.h Particella.h
	g++ -c CampoVettoriale.cc -o Campovettoriale.o
Puntomateriale.o: PuntoMateriale.cc PuntoMateriale.h Particella.h Posizione.h
	g++ -c PuntoMateriale.cc -o Puntomateriale.o

clean:
	rm *.o