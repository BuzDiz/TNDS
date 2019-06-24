LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esercizio10.0: esercizio10.0.cpp RandomGen.o Gauss.o
	g++ esercizio10.0.cpp RandomGen.o Gauss.o -o esercizio10.0 ${INCS} ${LIBS}
Gauss.o: Gauss.cc Gauss.h
	g++ -c Gauss.cc -o Gauss.o
RandomGen.o: RandomGen.cc RandomGen.h Gauss.o
	g++ -c RandomGen.cc -o RandomGen.o
clean:
	rm *.o
cleanall: clean
	rm *.o
