LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esercizio8.1: esercizio8.1.cpp FunzioneBase.o Integral.o
	g++ esercizio8.1.cpp FunzioneBase.o Integral.o -o esercizio8.1 ${INCS} ${LIBS}
FunzioneBase.o: FunzioneBase.cc FunzioneBase.h
	g++ -c FunzioneBase.cc -o FunzioneBase.o
Integral.o: Integral.cc Integral.h FunzioneBase.h
	g++ -c Integral.cc -o Integral.o

clean:
	rm *.o
